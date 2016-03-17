#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Canvas;
class PaintTool;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

private slots:
    void activateTool(QObject *tool);

private:
    Canvas *m_canvas;
    PaintTool *m_currentTool;
};

#endif // MAINWINDOW_H
