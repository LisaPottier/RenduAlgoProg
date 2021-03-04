#include "./../lib/tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);

int power(int value, int n)
{
    Context _("power", value, n);
    switch (n)
    {
    case 0:
        return 1;
        break;
    
    default:
        return value*power(value, n-1);
        break;
    }


    return_and_display(1);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new PowerWindow(power); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}
