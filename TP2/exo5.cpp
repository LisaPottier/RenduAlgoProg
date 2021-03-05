#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	if(origin.size()<=1)
	{return;}

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split
	for(int i=0;i<(first.size()); i++)
	{
		first[i]=origin[i];
	}
	for(int i=0;i<(second.size()); i++)
	{
		second[i]=origin[first.size()+i];
	}
	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second);
	// merge
	merge(first,second,origin);
}

void merge(Array& first, Array& second, Array& result)
{
	int rang_first=0;
	int rang_second=0;
	for(int i=0; i<result.size();i++)
	{
		//verifions que le rang ne sort pas du tableau
		if(rang_second>=second.size())
		{
			result[i]=first[rang_first];
			rang_first++;
		}
		else if(rang_first>=first.size())
		{
			result[i]=second[rang_second];
			rang_second++;
		}
		
		else
		{
			if(first[rang_first]<=second[rang_second])
			{
				result[i]=first[rang_first];
				rang_first++;
			}
			else{
				result[i]=second[rang_second];
				rang_second++;
			}
		}
	}
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
