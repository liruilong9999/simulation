/*
ע: ʹ�ö�����붨������,����Handle
*/

#ifndef LBaseGraph_H__20230601_lrl
#define LBaseGraph_H__20230601_lrl

#include "LBaseGraph_Global.h"

//ͼ����
template <class T1, class T2>
struct Vertex;
template <class T>
struct ArcSide;

template <class T1, class T2>
struct Vertex
{
    Vertex()
        : index(-1)
        , tail(nullptr)
        , head(nullptr)
    {
    }
    //�������
    int index;
    //��������
    T1 dataInfo;
    //ָ���Ըö���Ϊ��β�ĵ�һ����

    ArcSide<T2> * tail;
    //ָ���Ըö���Ϊ��ͷ�ĵ�һ����
    ArcSide<T2> * head;
};

template <class T>
struct ArcSide
{
    ArcSide()
        : tail_index(-1)
        , head_index(-1)
        , next_tail(nullptr)
        , next_head(nullptr)
    {
    }
    //��β�������
    int tail_index;
    //��ͷ�������
    int head_index;
    //ָ��β��ͬ����һ����
    ArcSide * next_tail;
    //ָ��ͷ��ͬ����һ����
    ArcSide * next_head;
    //������
    T dataInfo;
};

class LBaseGraph
{
public:
    //����ʮ������
    template <class T1, class T2>
    std::vector<Vertex<T1, T2>> create_cross_list();
    //ɾ��ʮ������
    template <class T1, class T2>
    void delete_cross_list(std::vector<Vertex<T1, T2>> & vertices);
    //�������
    //��Ӳ���
    template <class T1, class T2>
    void add_vertex(std::vector<Vertex<T1, T2>> & vertices, int index, T1 data);
    //ɾ������
    template <class T1, class T2>
    void delete_vertex(std::vector<Vertex<T1, T2>> & vertices, int index);
    //���ض��������������±�
    template <class T1, class T2>
    int GetIndexNumber(std::vector<Vertex<T1, T2>> & vertices, int index);
    //�޸Ķ�������
    template <class T1, class T2>
    void modify_vertex(std::vector<Vertex<T1, T2>> & vertices, int index, T1 new_data);
    //��ѯ����
    template <class T1, class T2>
    Vertex<T1, T2> query_vertex(std::vector<Vertex<T1, T2>> & vertices, int index);
    //������
    //��ӻ�
    template <class T1, class T2>
    void add_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index, T2 new_data);
    //ɾ����
    template <class T1, class T2>
    void delete_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index);
    //�޸Ļ�����
    template <class T1, class T2>
    bool modify_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index, T2 new_data);
    //��ѯ��
    template <class T1, class T2>
    ArcSide<T2> query_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index);
    //��ȡ���л���Ϣ
    template <class T1, class T2>
    std::vector<ArcSide<T2>> query_all_arc(std::vector<Vertex<T1, T2>> & vertices);
    //�жϻ��Ƿ����
    template <class T1, class T2>
    bool exist_arc(std::vector<Vertex<T1, T2>> & vertices, int head_index, int tail_index);
};

typedef std::shared_ptr<LBaseGraph> LBaseGraphPtr;

template <class T1, class T2>
std::vector<Vertex<T1, T2>> LBaseGraph::create_cross_list()
{
    std::vector<Vertex<T1, T2>> vec;
    return vec;
}

//ɾ��ʮ������
template <class T1, class T2>
void LBaseGraph::delete_cross_list(std::vector<Vertex<T1, T2>> & vertices)
{
    int len = vertices.size();
    for (int i = len - 1; i >= 0; i--)
    {
        delete_vertex<T1, T2>(vertices, i);
    }
    vertices.clear();
}

//�������
//��Ӳ���
template <class T1, class T2>
void LBaseGraph::add_vertex(std::vector<Vertex<T1, T2>> & vertices, int index, T1 dataInfo)
{
    Vertex<T1, T2> new_vertex;
    new_vertex.index    = index;
    new_vertex.dataInfo = dataInfo;
    new_vertex.tail     = nullptr;
    new_vertex.head     = nullptr;

    vertices.push_back(new_vertex);
}

//ɾ������
template <class T1, class T2>
void LBaseGraph::delete_vertex(std::vector<Vertex<T1, T2>> & vertices, int index)
{
    //ɾ���Ըö���Ϊ��ͷ���߻�β�����л�
    int IndexNumber = GetIndexNumber(vertices, index);
    if (IndexNumber < 0)
    {
        return;
    }
    ArcSide<T2> * arc = vertices[IndexNumber].tail;
    while (arc != nullptr)
    {
        ArcSide<T2> * next = arc->next_tail;

        delete_arc(vertices, arc->tail_index, arc->head_index);
        arc = next;
    }
    arc = vertices[IndexNumber].head;
    while (arc != nullptr)
    {
        ArcSide<T2> * next = arc->next_head;
        delete_arc(vertices, arc->tail_index, arc->head_index);
        arc = next;
    }
    vertices.erase(vertices.begin() + IndexNumber);
}

//���ض��������������±�
template <class T1, class T2>
int LBaseGraph::GetIndexNumber(std::vector<Vertex<T1, T2>> & vertices, int index)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].index == index)
        {
            return i;
        }
    }
    return -1;
}

//�޸Ķ�������
template <class T1, class T2>
void LBaseGraph::modify_vertex(std::vector<Vertex<T1, T2>> & vertices, int index, T1 new_dataInfo)
{
    int number                = GetIndexNumber(vertices, index);
    vertices[number].dataInfo = new_dataInfo;
}
//��ѯ����
template <class T1, class T2>
Vertex<T1, T2> LBaseGraph::query_vertex(std::vector<Vertex<T1, T2>> & vertices, int index)
{
    int number = GetIndexNumber(vertices, index);
    return vertices[number];
}

//������
//��ӻ�
template <class T1, class T2>
void LBaseGraph::add_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index, T2 new_dataInfo)
{
    //�����,���޸�����
    if (exist_arc(vertices, tail_index, head_index))
    {
        modify_arc(vertices, tail_index, head_index, new_dataInfo);
        return;
    }
    ArcSide<T2> * arc              = new ArcSide<T2>();
    arc->tail_index            = tail_index;
    arc->head_index            = head_index;
    arc->dataInfo              = new_dataInfo;
    int number_tail            = GetIndexNumber(vertices, tail_index);
    arc->next_tail             = vertices[number_tail].tail;
    vertices[number_tail].tail = arc;
    int number_head            = GetIndexNumber(vertices, head_index);
    arc->next_head             = vertices[number_head].head;
    vertices[number_head].head = arc;
}

//ɾ����
template <class T1, class T2>
void LBaseGraph::delete_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index)
{
    if (!exist_arc(vertices, tail_index, head_index))
    {
        return;
    }
    //ɾ���뻡
    tail_index    = GetIndexNumber(vertices, tail_index);
    head_index    = GetIndexNumber(vertices, head_index);
    ArcSide<T2> * pre = nullptr;
    ArcSide<T2> * arc = vertices[tail_index].tail;
    while (arc != nullptr && arc->head_index != vertices[head_index].index)
    {
        //��¼��һ����
        pre = arc;
        //�ƶ�����һ����
        arc = arc->next_tail;
    }
    if (arc != nullptr)
    {
        if (pre != nullptr)
        {
            //�������һ����,�ͽ�����nwxtָ��ɾ��������һ����
            pre->next_tail = arc->next_tail;
        }
        else
        {
            //������ǵ�һ����,�͸���ͷָ��
            vertices[tail_index].tail = arc->next_tail;
        }
    }
    //ɾ������
    pre = nullptr;
    arc = vertices[head_index].head;
    while (arc != nullptr && arc->tail_index != vertices[tail_index].index)
    {
        //��¼��һ����
        pre = arc;
        //�ƶ�����һ����
        arc = arc->next_head;
    }
    if (arc != nullptr)
    {
        if (pre != nullptr)
        {
            //�������һ����,�ͽ�����nextָ��ɾ��������һ����
            pre->next_head = arc->next_head;
        }
        else
        {
            //������ǵ�һ����,�͸���ͷָ��
            vertices[head_index].head = arc->next_head;
        }
    }
    //ɾ����һ��Ҫɾ���Ļ�
    delete arc;
}

//�޸Ļ�����
template <class T1, class T2>
bool LBaseGraph::modify_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index, T2 new_dataInfo)
{
    tail_index    = GetIndexNumber(vertices, tail_index);
    head_index    = GetIndexNumber(vertices, head_index);
    ArcSide<T2> * arc = vertices[tail_index].tail;
    while (arc != nullptr && arc->head_index != head_index)
    {
        arc = arc->next_tail;
    }
    if (arc != nullptr)
    {
        arc->dataInfo = new_dataInfo;
        return true;
    }
    else
    {
        return false;
    }
    return false;
}
//��ѯ��
template <class T1, class T2>
ArcSide<T2> LBaseGraph::query_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index)
{
    tail_index    = GetIndexNumber(vertices, tail_index);
    head_index    = GetIndexNumber(vertices, head_index);
    ArcSide<T2> * arc = vertices[tail_index].tail;
    while (arc != nullptr && arc->head_index != head_index)
    {
        arc = arc->next_tail;
    }
    if (arc)
    {
        return *arc;
    }
    else
    {
        ArcSide<T2> arc2;
        return arc2;
    }
}

//��ȡ���л�,ֻ��Ҫ�������нڵ�ĳ��������뻡����
template <class T1, class T2>
std::vector<ArcSide<T2>> LBaseGraph::query_all_arc(std::vector<Vertex<T1, T2>> & vertices)
{
    std::vector<ArcSide<T2>> arcs;
    for (auto vecs : vertices)
    {
        ArcSide<T2> * arc = vecs.tail;
        while (arc != nullptr)
        {
            arcs.push_back(*arc);
            arc = arc->next_tail;
        }
    }
    return arcs;
}

//�жϻ��Ƿ����
template <class T1, class T2>
bool LBaseGraph::exist_arc(std::vector<Vertex<T1, T2>> & vertices, int tail_index, int head_index)
{
    tail_index    = GetIndexNumber(vertices, tail_index);
    head_index    = GetIndexNumber(vertices, head_index);
    ArcSide<T2> * arc = vertices[tail_index].tail;
    while (arc != nullptr && arc->head_index != head_index)
    {
        arc = arc->next_tail;
    }
    if (arc)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // LBaseGraph_H__20230601_lrl
