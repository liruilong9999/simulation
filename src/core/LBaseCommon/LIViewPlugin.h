#ifndef LIVIEWPLUGIN_H__
#define LIVIEWPLUGIN_H__

#include "LSingleton.h"

#include <QObject>

struct LIViewPluginParam;
DEF_STRUCTHARED_PTR(LIViewPluginParam);

class LBASECOMMON_EXPORT LIViewPlugin : QObject //: public LSingleton<LIViewPlugin>
{
    // SINGLETON_DECLARE(LIViewPlugin);
public:
    LIViewPlugin();
    virtual ~LIViewPlugin();
    // ��ʼ�����
    virtual void Initialize(LIViewPluginParamPtr Param);
    // ������
    virtual void Cleanuo();
    // ��ȡ�������
    virtual std::string GetName();
    // ��ȡ�������
    virtual std::string GetDiscripe();
    // ��ȡ�������
    LIViewPluginParam GetPluginParam();
    // ��ȡ�������
    const std::string GetPluginClassName();
    // ���ò������
    void SetPluginClassName(const std::string& className);
    // ���ò��/���ò��
    virtual void UsePlugin(bool IsUse);

private:
    LIViewPluginParam* _P;
};

DEF_CLASSSHARED_PTR(LIViewPlugin);

#endif // LIVIEWPLUGIN_H__
