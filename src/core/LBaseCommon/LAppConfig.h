#ifndef LAPPCONFIG_H__
#define LAPPCONFIG_H__
#include "LSingleton.h"

struct LAppConfigPrivate;
DEF_STRUCTHARED_PTR(LAppConfigPrivate);

class LBASECOMMON_EXPORT LAppConfig: public LSingleton<LAppConfig>
{
	SINGLETON_DECLARE(LAppConfig);
public:
	LAppConfig();
	~LAppConfig();

	//���������ļ�·��
	void SetPath(std::string path);
	//��ȡ�����ļ�·��
	std::string GetPath();
	//��ȡ����б�
    template <class T>
	T GetPluginList();
	//��ȡģ���б�
    template <class T>
	T GetModuleList();
	//��ȡ������
    template <class T>
	T GetAppConfig(std::string configName, T value);
	//����������
    template <class T>
	void SetAppConfig(std::string configName , T value);

private:
	LAppConfigPrivate* _P;
};

#endif