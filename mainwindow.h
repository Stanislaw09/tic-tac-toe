#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class minmax;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int tab[3][3];

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    minmax *MinMax;

    void painting();
    void paintX(int, int);
    void paintO(QPair<int, int>);

    QPoint point;
    QImage image;
};
#endif // MAINWINDOW_H
