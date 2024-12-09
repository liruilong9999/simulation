#ifndef L_I_PLUGIN_H__
#define L_I_PLUGIN_H__

#include "LBaseCommon.h"
#include "LDeclBaseType.h"

// ע�����
class LBASECOMMON_EXPORT LIPluginConstructor
{
public:
    virtual ~LIPluginConstructor();
    virtual void Initialize() = 0;
};

DEF_CLASSSHARED_PTR(LIPluginConstructor);

// ���ע���
#define DEF_PlUGINREGISTERCONSTRUCTIR(pluginName)                   \
    class pluginName##Constructor : public LIPluginConstructor      \
    {                                                               \
    public:                                                         \
        virtual LIViewPluginPtr ConstructorPlugin()                 \
        {                                                           \
            LIViewPluginPtr plu = std::make_shared<LIViewPlugin>(); \
            plu->SetPluginClassName(pluginName);                    \
            return plu;                                             \
        }                                                           \
    };

#endif
