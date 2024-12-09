#ifndef LVIEWPLUGINFACTORY_H__
#define LVIEWPLUGINFACTORY_H__

#include "LDeclBaseType.h"
#include "LSingleton.h"

//���������
class LViewPluginFactory : public LSingleton<LViewPluginFactory>
{
    SINGLETON_DECLARE(LViewPluginFactory);
public:
    //���ز��
    void LoadPlugins();
    //ע����
    void RegisterViewPluginConstructor(int );
    //���ݲ�����ƴ������

    //���ݲ�����ƻ�ȡ���

    //���ղ������ע����

    //


};



#endif // LVIEWPLUGINFACTORY_H__