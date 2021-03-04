#include "tp1.h"
#include <QApplication>
#include <time.h>

Point initPoint(int x, int y){
    Point init;
    init.x=x;
    init.y=y;
    return init;
}

void carreeComplexe(Point * point)
{
    point->x=point->x*point->x;
    point->y=point->y*point->y;
}

void additionComplexe(Point *z, Point point)
{
    z->x += point.x;
    z->y += point.y;
}

int isMandelbrot(Point z, int n, Point point){
    switch (n)
    {
    case 0:
        return 0;
    
    default:
        carreeComplexe(&z);
        additionComplexe(&z,point);
        if(sqrt(pow(z.x,2) + pow(z.y,2))>2)
        {
            return 1;
        }
        else{
            return isMandelbrot(z,n-1,point);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



