#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>             // ���� vector ��
#include <queue>              // ���� queue ��
#include <memory>             // ��������ָ��
#include <thread>             // �����߳���
#include <mutex>              // ����������
#include <condition_variable> // ������������
#include <future>             // ����δ����future����
#include <functional>         // ���������������Ͱ�
#include <stdexcept>          // ������׼�쳣��

class ThreadPool
{
public:
    // ���캯���������߳�����
    ThreadPool(size_t);

    // ��������ӵ��̳߳صĶ�����
    template <class F, class... Args>
    auto enqueue(F && f, Args &&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

    // ��������
    ~ThreadPool();

private:
    std::vector<std::thread>          workers; // ���ڸ����̣߳��Ա�������ʱ���� join ��Щ�߳�
    std::queue<std::function<void()>> tasks;   // ������У����ڴ洢��ִ�е�����
    // ͬ�����
    std::mutex              queue_mutex; // ����������еĻ�����
    std::condition_variable condition;   // ���������������̼߳�ͨ��
    bool                    stop;        // ��־��ָʾ�̳߳��Ƿ�ֹͣ
};

// ���캯��������ָ�������Ĺ����߳�
inline ThreadPool::ThreadPool(size_t threads)
    : stop(false) // ��ʼ��ʱ���̳߳�δֹͣ
{
    // �����������߳�
    for (size_t i = 0; i < threads; ++i)
        workers.emplace_back( // �����߳���ӵ� workers ����
            [this] {          // �̵߳���������� lambda ���ʽ
                for (;;)      // ����ѭ����ֱ����ʽ����
                {
                    std::function<void()> task; // ��������

                    // ��ס����
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    // �ȴ�����������ֱ���������ִ�л��̳߳�ֹͣ
                    this->condition.wait(lock,
                                         [this] {
                                             return this->stop || !this->tasks.empty();
                                         });
                    // ����̳߳�ֹͣ�����������Ϊ�գ��򷵻�
                    if (this->stop && this->tasks.empty())
                        return;

                    // �Ӷ����л�ȡ�����Ƴ�
                    task = std::move(this->tasks.front());
                    this->tasks.pop();

                    // ִ������
                    task();
                }
            });
}

// ����������ӵ��̳߳���
template <class F, class... Args>
auto ThreadPool::enqueue(F && f, Args &&... args) -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type; // ���񷵻�����

    // ����һ������ָ�룬��װ����
    auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    // ��ȡδ�������Ա�������ɺ��ȡ���
    std::future<return_type> res = task->get_future();
    {
        // ��ס�������
        std::unique_lock<std::mutex> lock(queue_mutex);

        // ����̳߳��Ѿ�ֹͣ�����׳��쳣
        if (stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        // �������װ�� lambda ���ʽ����ӵ����������
        tasks.emplace([task]() {
            (*task)(); // ִ������
        });
    }
    // ֪ͨһ���ȴ����߳�
    condition.notify_one();
    return res; // ����δ������
}

// �����������ȴ������߳���ɹ���
inline ThreadPool::~ThreadPool()
{
    // ��ס�������
    std::unique_lock<std::mutex> lock(queue_mutex);
    stop = true; // ����ֹͣ��־

    condition.notify_all(); // ֪ͨ�����߳��˳�
    // �ȴ�ÿ�������߳̽���
    for (std::thread & worker : workers)
        worker.join();
}

#endif // THREAD_POOL_H
