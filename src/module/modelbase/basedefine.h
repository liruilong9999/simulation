#ifndef BASEDEFINE_H__20241209
#define BASEDEFINE_H__20241209

using Handle = unsigned int;

// 状态属性-六自由度
struct GeoPos
{
    double lon     = 0;
    double lat     = 0;
    double alt     = 0;
    double heading = 0;
    double pitch   = 0;
    double roll    = 0;
};

// 初始化属性
struct BaseTopic
{
};

//基础属性
struct InitTopic
{
    Handle handle;
	GeoPos geoPos;
};


#endif
