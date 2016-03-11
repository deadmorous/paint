#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Widget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

private:
    Widget *m_canvas;
};

#endif // MAINWINDOW_H
