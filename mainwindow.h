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

private:
    Canvas *m_canvas;
    PaintTool *m_brushTool;
    PaintTool *m_textTool;
};

#endif // MAINWINDOW_H
