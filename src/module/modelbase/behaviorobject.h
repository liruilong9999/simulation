#ifndef MODELOBJECT_H__20241209
#define MODELOBJECT_H__20241209

#include <QObject>
#include "modelbase_global.h"
#include "basedefine.h"

// 行为模型
class MODELBASE_EXPORT BehaviorObject : public QObject
{
public:
    InitTopic * GetInitTopic();
    BaseTopic * GetBaseTopic();

    virtual void init();

private:
    InitTopic * m_pInitTopic{nullptr};
    BaseTopic * m_pBaseTopic{nullptr};
};

#endif
