#ifndef IPLUGINVIEW_H
#define IPLUGINVIEW_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QMainWindow>
#include <QMutex>

#include <interface/iappskeleton/iappview.h>

#include "appskeleton.h"

class AppSkeleton;
class IAppView;

/**
 * @brief The IPluginView class
 *
 * 该类管理插件的分层注册，包含 Group、Page 和 Action 三个层级。插件在初始化时可以通过该类进行分层注册，
 * 并在主窗口显示时动态创建对应的菜单栏、分隔符和动作。
 */
class APPSKELETON_EXPORT IPluginView : public QObject,
                                       public IAppView
{
    Q_OBJECT
public:
    IPluginView(QObject *parent = nullptr);
    ~IPluginView();

    // 注册组
    void registerGroup(const QString & groupName) override;

    // 注册页
    void registerPage(const QString & groupName, const QString & pageName) override;

    // 注册动作
    void registerAction(const QString & groupName, const QString & pageName, QAction * action) override;

    // 获取主窗口
    QMainWindow * getMainWindow() override;

    // 创建菜单栏
    void createMenuBar(QMenuBar * menuBar) override;

private:
    IPluginView(const IPluginView &)             = delete;
    IPluginView & operator=(const IPluginView &) = delete;

    // Action 结构体，用于存储动作相关信息
    struct Action
    {
        QString   name;      // 动作名称
        QAction * actionPtr; // 动作指针
    };

    // Page 结构体，用于存储页相关信息
    struct Page
    {
        QString               name;    // 页名称
        QMap<QString, Action> actions; // 动作映射
    };

    // Group 结构体，用于存储组相关信息
    struct Group
    {
        QString             name;  // 组名称
        QMap<QString, Page> pages; // 页映射
    };

    QMap<QString, Group> m_groups;               // 组映射
    QMainWindow *        m_mainWindow = nullptr; // 主窗口指针
    static QMutex        m_mutex;
};

#endif // IPLUGINVIEW_H
