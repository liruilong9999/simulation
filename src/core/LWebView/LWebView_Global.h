#ifndef LWEBVIEW_GLOBAL_H__
#define LWEBVIEW_GLOBAL_H__

//���ļ������еĹ������������
#ifdef LWEBVIEW_LIBRARY
#define LWEBVIEW_EXPORT __declspec(dllexport)
#else
#define LWEBVIEW_EXPORT __declspec(dllimport)
#endif

#endif // !LUSERDIALOG_GLOBAL_H__