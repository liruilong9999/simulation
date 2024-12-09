#ifndef LSINGLETON_H__
#define LSINGLETON_H__

#include "LDeclBaseType.h"

//�������࣬�̳и����Ϊ������
//��ǰд�����������������Ԫ�����Ը�Ϊ����ݹ�ģ��ģʽ
template<typename T>
class LBASECOMMON_EXPORT LSingleton
{
public:
	static T& GetInstance() {
		static T instance;
		return instance;
	}

protected:
	LSingleton() = default;
	~LSingleton() = default;
    LSingleton(const LSingleton&)            = delete;
    LSingleton& operator=(const LSingleton&) = delete;
    LSingleton(LSingleton&&)                 = delete;
    LSingleton& operator=(LSingleton&&)      = delete;
};

//ע����Ԫ��
#define SINGLETON_DECLARE(className) \
friend class LSingleton<className>;



/*
//����ʵ��demo
class mysingleton :public LSingleton<mysingleton>
{
	SINGLETON_DECLARE(mysingleton);

	mysingleton() = default;
	~mysingleton() = default;

public:
	void print() 
	{
		//xxx;
	}
};

//����
void use()
{
	mysingleton::getInstance().print();
}
*/

#endif // !LSINGLETON_H__