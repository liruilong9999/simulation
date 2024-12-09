#ifndef LDYNAMICLIB_H__
#define LDYNAMICLIB_H__
// ���ļ����ڼ��ض�̬���ӿ�
#include "LDeclBaseType.h"

#ifdef _WIN32
#include <windows.h> // Windows�µĶ�̬���ӿ�ͷ�ļ�
#else
#include <dlfcn.h> // Linux�µĶ�̬���ӿ�ͷ�ļ�
#endif
namespace LDynamicLibrary
{
    namespace params
    {
        std::vector<void*> handles;    
    };
    // ���ض�̬�ⷵ������HMODULE��ֵΪ�գ���ʾ����ʧ��

    // ���ض�̬���ӿ�
    // LibPathName ��̬���·��+��̬������
    HMODULE LoadDynamicLibrary(const std::string& LibPathName);

    // ���ݲ�ͬ�ı����������汾��ϵͳ���ͼ��غ��ʵĶ�̬���ӿ�
    // LibPathName ��̬���·��+��̬������
    HMODULE LoadConditionsDynamicLibrary(const std::string& LibPathName);

    // ��ָ����̬���ӿ��л�ȡָ������
    // hModule ��̬����� �� funcName ��������
    FARPROC GetFounctionByLibrary(HMODULE hModule, const std::string& funcName);

    // �ͷ�ָ����̬���ӿ�
    // hModule ��̬�����
    void FreeDynamicLibrary(HMODULE hModule);

    // �ͷ��Ѽ��ص�ȫ����̬��
    void FreeAllLoadedDynamicLibrary();
}; // namespace LDynamicLibrary

#endif
