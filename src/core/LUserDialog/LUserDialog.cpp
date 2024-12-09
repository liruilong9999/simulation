/*
�̳�QDialogʵ��һ�����ڣ�Ҫ��:
1.ʹ��C++(C11)ʵ�֣�
2.��ʹ��ԭ���Ĵ��ڱ߿�
3.�̳еĴ��ڰ����رա����/��С������ק���ܣ�
*/

#include "LUserDialog.h"
#include <QApplication>
#include <QtGui/QMouseEvent>

CustomWindow::CustomWindow(QWidget* parent)
{
    mMoveing = false;
    // Qt::FramelessWindowHint �ޱ߿�
    // Qt::WindowStaysOnTopHint ��������ˣ������ϵ�����������
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    this->setStyleSheet("QDialog{border:2px solid green;}");
}
CustomWindow::~CustomWindow()
{
}

// ��д��갴���¼�
void CustomWindow::mousePressEvent(QMouseEvent* event)
{
    mMoveing      = true;
    // ��¼���������ڴ��ڵ�λ��
    // event->globalPos()��갴��ʱ����������������Ļλ��
    // pos() this->pos()��갴��ʱ�����������������Ļλ��
    mMovePosition = event->globalPos() - pos();
    return QDialog::mousePressEvent(event);
}

// ��д����ƶ��¼�
void CustomWindow::mouseMoveEvent(QMouseEvent* event)
{
    //(event->buttons() && Qt::LeftButton)���������
    // ����ƶ��¼���Ҫ�ƶ����ڣ������ƶ��������أ�����Ҫ��ȡ����ƶ��У�������������Ļ�����꣬Ȼ��move��������꣬��ô��ȡ���ꣿ
    // ͨ���¼�event->globalPos()֪��������꣬��������ȥ�������ڴ���λ�ã����Ǵ�����������Ļ������
    if (mMoveing && (event->buttons() && Qt::LeftButton) && (event->globalPos() - mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}
void CustomWindow::mouseReleaseEvent(QMouseEvent* event)
{
    mMoveing = false;
}