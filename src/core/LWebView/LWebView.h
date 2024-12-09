
#ifndef LWEBVIEW_H__
#define LWEBVIEW_H__

#include <QObject>
#include <QWebChannel>
#include <QWebEngineView>
#include <QWebEnginePage>
#include "LWebBrowser.h"

class LWebBrowser;
struct LWebViewPrivate;

class LWEBVIEW_EXPORT LWebView : public QWebEngineView
{
    Q_OBJECT

public:
    explicit LWebView(QWidget * parent = nullptr);
    ~LWebView();

public:
    // ���������ҳ����ƽӿ�, ��ͨ�� runJavaScript �ӿڵ��� Javascript.
    LWebBrowser * Browser() const;
    // �ڴ�����һ HRLJWebView ǰ���ô˷�����ʼ��.
    static bool Init();

    // ��ȡҳ����ؽ���, ��Χ0-100.
    int LoadProgress() const;

    // �� obj ʹ�� name ��Ϊ����ע�ᵽ Javascript ��ȫ�ַ���.
    // name:����, ���鲻Ҫ�ͳ���ȫ�ֱ�������(�� window)��ͬ
    // obj: the object.
    void RegisterObject(const QString & name, QObject * obj);
    void UnregisterObject(QObject * obj);

    bool IsRegisterObject(QString ObjName);

protected:
    // �����Ĳ˵�.
    void contextMenuEvent(QContextMenuEvent * e);
    //////////////////////////////////////////////////////////////////////////
    /// <summary> ʹ�� Javascript �����´���/��ǩҳʱʵ�ִ˺���. </summary>
    /// <param name="type"> ��������. </param>
    /// <returns> �´���/��ǩҳ��Ӧ�� QWebEngineView ָ��. </returns>
    //////////////////////////////////////////////////////////////////////////
    QWebEngineView * createWindow(QWebEnginePage::WebWindowType type);

protected slots:
    void ShowDevToolsPageSlot();
    void ClearCacheSlot();
    void OnDownloadRequestedSlot(QWebEngineDownloadItem * download);

private:
    using QWebEngineView::page;
    using QWebEngineView::setPage;

    LWebViewPrivate * _p;
};

#endif
