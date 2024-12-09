#ifndef MOTIONMODEL_H__20241209
#define MOTIONMODEL_H__20241209

#include "behaviorobject.h"

class MODELBASE_EXPORT MotionModel : public BehaviorObject
{
public:
	virtual void init() override;

	virtual void circulMotion();

};

#endif
