#ifndef LBASECOMMON_H__
#define LBASECOMMON_H__

//���ļ������еĹ������������
#ifdef LBASECOMMON_LIBRARY
#define LBASECOMMON_EXPORT __declspec(dllexport)
#else
#define LBASECOMMON_EXPORT __declspec(dllimport)
#endif

#endif // !LBASECOMMON_H__