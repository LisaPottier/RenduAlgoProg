#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <iostream>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct BinarySearchTree : public BinaryTree
{    
    BinarySearchTree* left;
    BinarySearchTree* right;
    int value;

    BinarySearchTree* createNode(int value) {
        return new BinarySearchTree(value);
    }

    void initNode(int value)
    {
        // init initial node without children
        
        this->value=value;
        this->left=NULL;
        this->right=NULL;

    }

    void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if(this->value>value) //la value est plus petite de le noeud -> on regarde le fils de gauche
        {
            if(this->left)//si on est pas encore sur une feuille
            {
                this->left->insertNumber(value);
            }
            else
            {
                this->left=createNode(value);//on crée directement un nouveau noeud à la feuille
                return;
            }
        }
        else
        {
            if(this->right)
            {
                this->right->insertNumber(value);
            }
            else
            {
                this->right=createNode(value);
                return;
            }
        }

    }

    uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int compteur_left=1;
        int compteur_right=1;

        if(this->right)
        {
            compteur_right+=(this->right)->height();
        }
        if(this->left)
        {
            compteur_left+=(this->left)->height();
        }

        if(compteur_right>compteur_left)
        {
            return compteur_right;
        }
        else
        {
            return compteur_left;
        }
    }

    uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int nb_child=1;//la racine est comptée dans les enfants

        if(this->left)
        {
            nb_child+=(this->left)->nodesCount();
        }
        if(this->right)
        {
            nb_child+=(this->right)->nodesCount();
        }
        return nb_child;
    }

    bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->left || this ->right)
        {return false;}
        else
        {return true;}
    }

    void allLeaves(BinarySearchTree* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
        if(this->isLeaf())
        {
            leaves[leavesCount]=this;
            leavesCount++;
        }
        else
        {
            if(this->left)
            {
                this->left->allLeaves(leaves,leavesCount);
            }
            if(this->right)
            {
                this->right->allLeaves(leaves,leavesCount);
            }
        }

    }

    void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if(this->left)
        {
            this->left->inorderTravel(nodes,nodesCount);
        }
        nodes[nodesCount]=this;
        nodesCount++;
        if(this->right)
        {
            this->right->inorderTravel(nodes,nodesCount);
        }
    }

    void preorderTravel(Node* nodes[], uint& nodesCount) {//refaire
        // fill nodes array with all nodes with preorder travel
        nodes[nodesCount]=this;
        nodesCount++;
        if(this->left)
        {
            this->left->inorderTravel(nodes,nodesCount);
        }

        if(this->right)
        {
            this->right->inorderTravel(nodes,nodesCount);
        }

    }

    void postorderTravel(Node* nodes[], uint& nodesCount) {//refaire
        // fill nodes array with all nodes with postorder travel

        if(this->left)
        {
            this->left->inorderTravel(nodes,nodesCount);
        }

        if(this->right)
        {
            this->right->inorderTravel(nodes,nodesCount);
        }
        nodes[nodesCount]=this;
        nodesCount++;

    }

    BinarySearchTree* find(int value) {
        // find the node containing value
        BinarySearchTree * current = this;
        while(current)
        {
            if(current->value==value)
            {return current;}

            if(current->value > value)
            {
                if(current->left)
                {current = current->left;}
                else
                {return nullptr;}
            }

            else if(current->value < value)
            {
                if(current->right)
                {current=current->right;}
                else
                {return nullptr;}
            }
        }
        return nullptr;
    }

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }


    BinarySearchTree(int value) : BinaryTree(value) {initNode(value);}
    ~BinarySearchTree() {}
    int get_value() const {return value;}
    BinarySearchTree* get_left_child() const {return left;}
    BinarySearchTree* get_right_child() const {return right;}
};

/*BinarySearchTree* createNode(int value) {
    return new BinarySearchTree(value);
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<BinarySearchTree>();
    w->show();

    return a.exec();
}
