#ifndef LWEBBROWSER_H
#define LWEBBROWSER_H

#include <QWebEnginePage>

#include "LWebView_Global.h"


class LWEBVIEW_EXPORT LWebBrowser : public QWebEnginePage
{
public:
    explicit LWebBrowser(QWebEngineProfile* profile, QWidget* parent = nullptr);

protected:
    // ֤������� 
    bool certificateError(const QWebEngineCertificateError& error);
    void javaScriptAlert(const QUrl& securityOrigin, const QString& msg);
    bool javaScriptConfirm(const QUrl& securityOrigin, const QString& msg);
    bool javaScriptPrompt(const QUrl& securityOrigin, const QString& msg, const QString& defaultValue, QString* result);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>   ��д�ϴ��ļ�����,�Զ����ģʽ,���ò���ϵͳ��,����Qt��. </summary>
    ///
    /// <remarks>   ������, 2023/3/1 ������. </remarks>
    ///
    /// <param name="mode">                 The mode. </param>
    /// <param name="oldFiles">             The old files. </param>
    /// <param name="acceptedMimeTypes">    List of types of the accepted mimes. </param>
    ///
    /// <returns>   A QStringList. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    //QStringList chooseFiles(QWebEnginePage::FileSelectionMode mode, const QStringList& oldFiles, const QStringList& acceptedMimeTypes);

signals:
    void fileUploaded(const QByteArray& data);
};

#endif // LWEBBROWSER_H
