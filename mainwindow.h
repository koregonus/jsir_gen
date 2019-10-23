#ifndef MAINWINDOW_H
#define MAINWINDOW_H




#include <QMainWindow>

#include <QDir>

#include <QTime>

#include <QFile>

#include <QtMath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    void createLogs(QString file_extension);
    QString path;
    QString session;
    QString filename;
    void curve_function();
    void generator(qreal y, qreal z);
    void append_buf_in_f(QString buf);


    void point_creation_code_gen(int point_n, qreal x, qreal y, qreal z);


public slots:
    void create_curve();
    void ferma_generator();

};

//Внедрение блоков
class Block
{
private:
    QString name;

    //Точка 1
    QString Point_1;
    qreal x_1;
    qreal y_1;
    qreal z_1;

    //Точка 2
    QString Point_2;
    qreal x_2;
    qreal y_2;
    qreal z_2;

    //Точка 3
    QString Point_3;
    qreal x_3;
    qreal y_3;
    qreal z_3;

    //Точка 4
    QString Point_4;
    qreal x_4;
    qreal y_4;
    qreal z_4;

    //Точка 5
    QString Point_5;
    qreal x_5;
    qreal y_5;
    qreal z_5;

    //Точка 6
    QString Point_6;
    qreal x_6;
    qreal y_6;
    qreal z_6;

    //Точка 7
    QString Point_7;
    qreal x_7;
    qreal y_7;
    qreal z_7;

    //Точка 8
    QString Point_8;
    qreal x_8;
    qreal y_8;
    qreal z_8;

    //Точка 9
    QString Point_9;
    qreal x_9;
    qreal y_9;
    qreal z_9;

    //Точка 10
    QString Point_10;
    qreal x_10;
    qreal y_10;
    qreal z_10;

    //Точка 11
    QString Point_11;
    qreal x_11;
    qreal y_11;
    qreal z_11;

    //ТОчка 12
    QString Point_12;
    qreal x_12;
    qreal y_12;
    qreal z_12;
public:
    Block(QString blockname);
    void set_point_name(int point_n, QString p_name);//Иниц!!!
    void set_point_coord(int point_n, qreal x, qreal y, qreal z);
    qreal get_point_x(int point_n);
    qreal get_point_y(int point_n);
    qreal get_point_z(int point_n);
    QString get_point_name(int point_n);
    void set_blockname(QString blockname);
};

#endif // MAINWINDOW_H
