#include "behaviorobject.h"

void BehaviorObject::init()
{
	m_pBaseTopic = new BaseTopic;
	m_pInitTopic = new InitTopic;
	//赋值操作，子类进行
}

InitTopic * BehaviorObject::GetInitTopic()
{
	return m_pInitTopic;
}

BaseTopic * BehaviorObject::GetBaseTopic()
{
	return m_pBaseTopic;
}
