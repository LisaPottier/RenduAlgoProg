#include "tp3.h"
#include <QApplication>
#include <time.h>
//ok avec les test du main
MainWindow* w = nullptr;
using std::size_t;


int binarySearch(Array& array, int toSearch)
{
	int start= 0;
	int end=array.size();
	while(start<end)
	{
		int mid=(start+end)/2;
		if(toSearch > array[mid])
		{
			start=mid+1;
		}
		else if(toSearch <array[mid])
		{
			end=mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
    indexMin = indexMax = -1;
	int start= 0;
	int end=array.size();
	while(start<end)
	{
		int mid=(start+end)/2;
		if(toSearch > array[mid])
		{
			start=mid+1;
		}
		else if(toSearch <array[mid])
		{
			end=mid;
		}
		else
		{
			indexMin=mid;
			end=indexMin;
		}
	}
	if(indexMin!=-1)
	{
	end++;
	start=indexMin;
	indexMax=indexMin;
	while(start<end)
	{
		int mid=(start+end)/2;
		//le cas toSearch > array[mid] n'apparait jamais car on est dans la partie du tableau (trié) après toSearch

		if(toSearch < array[mid])
		{
			end=mid;
		}
		else
		{
			indexMax=mid;
			end=indexMax;
		}	
	}
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
