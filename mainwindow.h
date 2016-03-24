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
    void open();
    void save();
    void saveAs();

private:
    Canvas *m_canvas;
    QToolBar *m_tbr;
    QString m_fileName;
};

#endif // MAINWINDOW_H
