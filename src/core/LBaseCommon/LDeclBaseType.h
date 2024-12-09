#ifndef LDECLBASETYPE_H__
#define LDECLBASETYPE_H__

#include "LBaseCommon.h"
#include <memory>
#include <vector>
#include <string>
#include <map>

//��װ����ָ�룬ʹ���Ϊ�귽����ٵ���
#define DEF_CLASSSHARED_PTR(className) \
	class className;\
	using className##Ptr = std::shared_ptr<className>;
#define DEF_STRUCTHARED_PTR(structName) \
	struct structName;\
	using structName##Ptr = std::shared_ptr<structName>;















#endif 

