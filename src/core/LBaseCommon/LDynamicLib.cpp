#include "LDynamicLib.h"


LPCWSTR CharToLPCWSTR(const char * str)
{
    int       size   = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    wchar_t * buffer = new wchar_t[size];
    MultiByteToWideChar(CP_ACP, 0, str, -1, buffer, size);
    LPCWSTR result = buffer;
    delete[] buffer;
    return result;
}

HMODULE LDynamicLibrary::LoadDynamicLibrary(const std::string& LibPathName)
{
#ifdef _WIN32
    HINSTANCE handle = LoadLibrary(CharToLPCWSTR(LibPathName.c_str())); // Windows�µĶ�̬����غ���
#else
    void* handle = dlopen(pluginPath.c_str(), RTLD_LAZY); // Linux�µĶ�̬����غ���
#endif
    return handle;
}

HMODULE LDynamicLibrary::LoadConditionsDynamicLibrary(const std::string& LibPathName)
{
    return nullptr;
}

FARPROC LDynamicLibrary::GetFounctionByLibrary(HMODULE hModule, const std::string& funcName)
{
    return nullptr;
}

void LDynamicLibrary::FreeDynamicLibrary(HMODULE hModule)
{
#ifdef _WIN32
    FreeLibrary(hModule); // Windows�µĶ�̬��رպ���
#else
    dlclose(handle);                                      // Linux�µĶ�̬��رպ���
#endif
}

void LDynamicLibrary::FreeAllLoadedDynamicLibrary()
{
    // �رն�̬���ӿ�
    for (void* handle : params::handles)
    {
#ifdef _WIN32
        FreeLibrary((HMODULE)handle); // Windows�µĶ�̬��رպ���
#else
        dlclose(handle);                                  // Linux�µĶ�̬��رպ���
#endif
    }
}
