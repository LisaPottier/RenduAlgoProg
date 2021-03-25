#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

std::max()

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return 2*nodeIndex +1;
}

int Heap::rightChild(int nodeIndex)
{
    return 2*nodeIndex +2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
    int i = heapSize;
    this->set(i,value);
    while(i>0 && this->get(i)>this->get((i-1)/2))
    {
        swap(this->get(i),this->get((i-1)/2));

        i=(i-1)/2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    int i_max = nodeIndex;
    if(this->get(i_max)<=(this->get(rightChild(nodeIndex))) || this->get(i_max)<=(this->get(leftChild(nodeIndex))))
    {
        if(this->get(rightChild(nodeIndex))>=this->get(nodeIndex))
        {
            swap(this->get(nodeIndex), this->get(rightChild(nodeIndex)));
            i_max=rightChild(nodeIndex);
            
        }
        else if(this->get(leftChild(nodeIndex))>=this->get(nodeIndex))
        {
            swap(this->get(nodeIndex), this->get(leftChild(nodeIndex)));
            i_max=leftChild(nodeIndex);
        }
        heapify(heapSize,this->get(i_max));
    }
}

void Heap::buildHeap(Array& numbers)
{
    for(int i=0; i<(int)numbers.size(); i++)
    {
        this->insertHeapNode(i+1,numbers.get(i));
    }  
}

void Heap::heapSort()
{
    for(int i=this->size()-1; i>=0; i--)
    {
        swap(this->get(0), this->get(i));
        this->heapify(i,0);
    }   
}
/*
//---------------------------------------------------------------
//       DEUXIEME PARTIE : HUFFMAN
//---------------------------------------------------------------

void HuffmanHeap::insertHeapNode(HuffmanHeap heap, int heapSize, char character, int frequence)
{
    int i = heapSize;
    HuffmanNode *New= new HuffmanNode(character,frequence);
    this->set(heapSize,*New);

    while(i>0 && this->get(i).frequence < this->get((i-1)/2).frequences)
    {
        swap(),(i-1)/2);

        i=(i-1)/2;
    }
}


void HuffmanHeap::insertNode(HuffmanNode tree, HuffmanNode node)
{
    if(this->isLeaf())
    {
        HuffmanNode *copie=new HuffmanNode(tree->character,tree->frequences);
        tree->character='\0';
        if(node->frequences == (tree->frequences)/2){
            this->left = node;
            this->right = copie;
        }else{
            this->left = copie;
            this->right = node;
        }
    }
    else
    {
         if(node->frequences == (tree->frequences)/2){
            insertNode(tree->left,node);
        }else{
            insertNode(tree->right,node);
        }
    }
    tree->frequences+=node->frequences;
}

void HuffmanNode::processCodes(HuffmanNode tree)
{
    parentCode=tree->code;
    if(!tree->isLeaf())
    {
        tree->left->processCodes(parentCode + "0");
        tree->right->processCodes(parentCode + "1");
    }
}


void HuffmanNode::charFrequences(string data, Array& frequences)
{
   int l= data.size();
   for(int i=0; i<l ; i++)
   {
       frequences.get((int)data[i])++;
   }
}

void Heap::huffmanHeap(Array& frequences, HuffmanHeap heap)
{
    int size=0;

    for (int i=0; i<frequences.size(); i++)
    {
        if(frequences.get(i)!=0)
        {
            heap.insertHeapNode(size,frequences.get(i));
            size++;
        }
    }

}

void Heap::huffmanDict(HuffmanHeap heap, HuffmanNode* tree, int heapSize)
{
    HuffmanNode* dict = new HuffmanNode(heap.get(0).character, heap.get(0).frequences);
    
    for(int i=1; i<heapSize; i++){
        dict->insertNode(tree,new HuffmanNode(heap.get(i).character, heap.get(i).frequences));
    }
}

*/
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
