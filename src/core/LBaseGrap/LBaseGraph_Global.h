#ifndef LBASEGRAPH_GLOBAL_H__
#define LBASEGRAPH_GLOBAL_H__

//���ļ������еĹ������������
#ifdef LBASEGRAPH_LIBRARY
#define LBASEGRAPH_EXPORT __declspec(dllexport)
#else
#define LBASEGRAPH_EXPORT __declspec(dllimport)
#endif

#include <string>
#include <vector>

#endif // !LUSERDIALOG_GLOBAL_H__