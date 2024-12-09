#ifndef COMMUNATEMODULE_H
#define COMMUNATEMODULE_H

#include <QObject>
#include <common/TSingleton.hpp>

#include "circulevent_global.h"

class CIRCULEVENT_EXPORT CirculEvent : public QObject,
                                       public TSingleton<CirculEvent>
{
    friend class TSingleton<CirculEvent>;

public:
    // 初始化操作
    void init();
    // 获取当前作战时间
    qint64 GetBattleTime();

    // 方案总时间
    qint64 GetScenarioTime();

    // 核心-模型事件调度
    void run();

private:
    qint64 m_battleTime{0};   // 作战时间，即当前时间
    qint64 m_scenarioTime{0}; // 方案总时长
    qint64 m_step{3000};         // 仿真步长，默认3.0秒
};

#endif // COMMUNATEMODULE_H
