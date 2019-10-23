#include "mainwindow.h"
#include "ui_mainwindow.h"


#define MAX_TELESCOPE_RADIUS 30

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton,   SIGNAL(clicked()),
            this,               SLOT  (close()));

    connect(ui->pushButton_2,   SIGNAL(clicked()),
            this,               SLOT  (create_curve()));


    connect(ui->action, SIGNAL(triggered()),this, SLOT(ferma_generator()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::create_curve()
{
    createLogs(".sldcrv");
    curve_function();


}


void MainWindow::createLogs(QString file_extension)
    {
     path="logs/";
     QDir dir;
     if (!dir.exists(path))
        dir.mkpath(path);
     session=QTime::currentTime().toString();
     session.append("/");
     session.replace(":","_");
     session.replace("\n","");
     //QDir dir;
     if (!dir.exists(path+session))
        dir.mkpath(path+session);
     filename=QTime::currentTime().toString();
     filename.replace(":","_");
     filename.replace("\n","");
     filename.append(file_extension);
     QFile file(path+session+filename);
     file.open(QIODevice::WriteOnly);
     //QString AutoInitMessage="Automatic test was initialized!...\n";
     //file.write(AutoInitMessage.toLocal8Bit());
//     // Место для теста
//     //test_func(test_number);
     file.close();
    }


void MainWindow::curve_function()
{
    qreal R;
    qreal K;
    qreal y,z;
    qreal delta_z=1;


   // int iterator=0;
    //Исходная инициализация
    //x=0;
    y=0;
    z=0;
    R=15560;
    K=0.997;


    while(y<3300)
    {
        y=qSqrt(-(K+1)*(qPow(z,2))+2*R*z);

       // printf("%l",(double)y);

        generator(y,z);

        z=z+delta_z;
       // iterator++;
    }



}

void MainWindow::generator(qreal y,qreal z)
{
    QString buffer;
    QString num;

    buffer.append("0mm ");
    num= QString::number(y,'f',3);
    buffer.append(num);
    buffer.append("mm");
    buffer.append(" ");
    num=QString::number(z,'f',0);
    buffer.append(num);
    buffer.append("mm\n");



    append_buf_in_f(buffer);
    //QFile file(path+session+filename);
    //file.open(QIODevice::Append);
    //file.write(buffer.toLocal8Bit());
    //file.close();

}

void MainWindow::append_buf_in_f(QString buf)
{
    QFile file(path+session+filename);
    file.open(QIODevice::Append);
    file.write(buf.toLocal8Bit());
    file.close();
}


void MainWindow::ferma_generator()
{
    qreal R = 0.66;
    qreal r = ((sqrt(3)/2)*R);
    createLogs(".ses");
    append_buf_in_f("$#Script: Patran 2012 64-Bit\n");
    append_buf_in_f("$#Primary mirror support Bar2-oriented generation\n");
    append_buf_in_f("STRING asm_create_grid_xyz_created_ids[VIRTUAL]\n");

    //append_buf_in_f("asm_const_grid_xyz( \"1\", \"[0.57158 0.33 0]\", \"Coord 0\",  @\nasm_create_grid_xyz_created_ids )\n");

    Block A1("A1");
    //A1.set_point_name(1,"Point 1");
    //append_buf_in_f(A1.get_point_name(1));
    //append_buf_in_f("\n");

    A1.set_point_coord(1, r,R/2,0);
    A1.set_point_coord(2,r,-R/2,0);
    A1.set_point_coord(3, 0,-R,0);
    A1.set_point_coord(4,-r,-R/2,0);
    A1.set_point_coord(5,-r,R/2,0);
    A1.set_point_coord(6,0,R,0);


    for (int i=1; i<=6; i++)
    point_creation_code_gen(i,A1.get_point_x(i),A1.get_point_y(i),A1.get_point_z(i));

}


void Block::set_point_name(int point_n, QString p_name)
{
    if (point_n == 1)
        Point_1 = p_name;
    else if (point_n == 2)
        Point_2 = p_name;
    else if (point_n == 3)
        Point_3 = p_name;
    else if (point_n == 4)
        Point_4 = p_name;
    else if (point_n == 5)
        Point_5 = p_name;
    else if (point_n == 6)
        Point_6 = p_name;
    else if (point_n == 7)
        Point_7 = p_name;
    else if (point_n == 8)
        Point_8 = p_name;
    else if (point_n == 9)
        Point_9 = p_name;
    else if (point_n == 10)
        Point_10 = p_name;
    else if (point_n == 11)
        Point_11 = p_name;
    else if (point_n == 12)
        Point_12 = p_name;
    else
        printf("wrong point number!\n");

}

QString Block::get_point_name(int point_n)
{
    if (point_n == 1)
        return Point_1;
    else if (point_n == 2)
        return Point_2;
    else if (point_n == 3)
        return Point_3;
    else if (point_n == 4)
        return Point_4;
    else if (point_n == 5)
        return Point_5;
    else if (point_n == 6)
        return Point_6;
    else if (point_n == 7)
        return Point_7;
    else if (point_n == 8)
        return Point_8;
    else if (point_n == 9)
        return Point_9;
    else if (point_n == 10)
        return Point_10;
    else if (point_n == 11)
        return Point_11;
    else if (point_n == 12)
        return Point_12;
    else
    {
        printf("wrong point number!\n");
        return "NAN";
    }
}

void Block::set_point_coord(int point_n, qreal x, qreal y, qreal z)
{
    if (point_n == 1)
    {
        x_1 = x;
        y_1 = y;
        z_1 = z;
    }
    else if (point_n == 2)
    {
        x_2 = x;
        y_2 = y;
        z_2 = z;
    }
    else if (point_n == 3)
    {
        x_3 = x;
        y_3 = y;
        z_3 = z;
    }
    else if (point_n == 4)
            {
                x_4 = x;
                y_4 = y;
                z_4 = z;
            }
    else if (point_n == 5)
            {
                x_5 = x;
                y_5 = y;
                z_5 = z;
            }
    else if (point_n == 6)
            {
                x_6 = x;
                y_6 = y;
                z_6 = z;
            }
    else if (point_n == 7)
            {
                x_7 = x;
                y_7 = y;
                z_7 = z;
            }
    else if (point_n == 8)
            {
                x_8 = x;
                y_8 = y;
                z_8 = z;
            }
    else if (point_n == 9)
            {
                x_9 = x;
                y_9 = y;
                z_9 = z;
            }
    else if (point_n == 10)
            {
                x_10 = x;
                y_10 = y;
                z_10 = z;
            }
    else if (point_n == 11)
            {
                x_11 = x;
                y_11 = y;
                z_11 = z;
            }
    else if (point_n == 12)
            {
                x_12 = x;
                y_12 = y;
                z_12 = z;
            }
    else
        printf("wrong point number!\n");
}


//Конструктор класса Block
Block::Block(QString blockname)
{
    set_blockname(blockname);
}

void Block::set_blockname(QString blockname)
{
    this->name = blockname;
}



void MainWindow::point_creation_code_gen(int point_n, qreal x, qreal y, qreal z)
{
    //QString buffer;
    QString num;

    //buffer.append("0mm ");
    num= QString::number(point_n,'f',0);


    append_buf_in_f("asm_const_grid_xyz( \"");

    append_buf_in_f(num);

    append_buf_in_f("\", \"[");

    num= QString::number(x,'f',3);
    append_buf_in_f(num);
    append_buf_in_f(" ");
    num= QString::number(y,'f',3);
    append_buf_in_f(num);
    append_buf_in_f(" ");
    num= QString::number(z,'f',3);
    append_buf_in_f(num);

    append_buf_in_f("]\", \"Coord 0\",  @\nasm_create_grid_xyz_created_ids )\n");


   // append_buf_in_f("asm_const_grid_xyz( \"1\", \"[0.57158 0.33 0]\", \"Coord 0\",  @\nasm_create_grid_xyz_created_ids )\n");
}


qreal Block::get_point_x(int point_n)
{
    if (point_n == 1)
        return x_1;
    else if (point_n == 2)
        return x_2;
    else if (point_n == 3)
        return x_3;
    else if (point_n == 4)
        return x_4;
    else if (point_n == 5)
        return x_5;
    else if (point_n == 6)
        return x_6;
    else if (point_n == 7)
        return x_7;
    else if (point_n == 8)
        return x_8;
    else if (point_n == 9)
        return x_9;
    else if (point_n == 10)
        return x_10;
    else if (point_n == 11)
        return x_11;
    else if (point_n == 12)
        return x_12;
    else
    {
        printf("wrong point number!\n");
        return 0;
    }
}

qreal Block::get_point_y(int point_n)
{
    if (point_n == 1)
        return y_1;
    else if (point_n == 2)
        return y_2;
    else if (point_n == 3)
        return y_3;
    else if (point_n == 4)
        return y_4;
    else if (point_n == 5)
        return y_5;
    else if (point_n == 6)
        return y_6;
    else if (point_n == 7)
        return y_7;
    else if (point_n == 8)
        return y_8;
    else if (point_n == 9)
        return y_9;
    else if (point_n == 10)
        return y_10;
    else if (point_n == 11)
        return y_11;
    else if (point_n == 12)
        return y_12;
    else
    {
        printf("wrong point number!\n");
        return 0;
    }
}

qreal Block::get_point_z(int point_n)
{
    if (point_n == 1)
        return z_1;
    else if (point_n == 2)
        return z_2;
    else if (point_n == 3)
        return z_3;
    else if (point_n == 4)
        return z_4;
    else if (point_n == 5)
        return z_5;
    else if (point_n == 6)
        return z_6;
    else if (point_n == 7)
        return z_7;
    else if (point_n == 8)
        return z_8;
    else if (point_n == 9)
        return z_9;
    else if (point_n == 10)
        return z_10;
    else if (point_n == 11)
        return z_11;
    else if (point_n == 12)
        return z_12;
    else
    {
        printf("wrong point number!\n");
        return 0;
    }
}
