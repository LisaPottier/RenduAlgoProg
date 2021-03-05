#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	// bubbleSort
	bool cont = true;
	while(cont)
	{
		cont=false;
		for(int i=0; i<toSort.size()-1; i++)
		{
			if (toSort[i]>toSort[i+1])
			{
				toSort.swap(i+1, i);
				cont=true;
			}
		}
	}
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
