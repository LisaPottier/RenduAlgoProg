#include <QApplication>
#include <QString>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

#include <tp5.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


std::vector<string> TP5::names(
{
    "Steeve", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Theo", "Vincent", "Paul", "Zoe", "Julien",
    "Fanny", "Jeanne", "Elo","Lisa"
});

unsigned long int hash_str(string key)
{
    // return an unique hash id from key
    int h;
    int keySize=key.size();
    for(int k=0; k<keySize; k++)
    {
        h+=key[k]*pow(127,keySize-k);
    }     
    return h;
}

struct MapNode : public BinaryTree
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value) : BinaryTree (value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash_str(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {
        if(this->key_hash<node->key_hash)
        {
            if(this->right)
            {
                this->right->insertNode(node);
            }
            else
            {
                this->right=node;
                return;
            }
        }
        else if(this->key_hash>=node->key_hash )
        {
            if(this->left)
            {
                this->left->insertNode(node);
            }
            else
            {
                this->left=node;
                return;
            }
        }
    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

    virtual ~MapNode() {}
    QString toString() const override {return QString("%1:\n%2").arg(QString::fromStdString(key)).arg(value);}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

struct Map
{
    Map() {
        this->root = nullptr;
    }

    /**
     * @brief insert create a node and insert it to the map
     * @param key
     * @param value
     */
    void insert(string key, int value)
    {
        MapNode* node=new MapNode(key, value);
        node->key=key;
        node->value=value;
        node->key_hash=hash_str(key);
        node->left=NULL;
        node->right=NULL;
        if(this->root)
        {
            this->root->insertNode(node);
        }
        else{
            this->root=node;
        }
    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    int get(string key)
    {
        unsigned long int hash_key = hash_str(key);
        MapNode *current=this->root;
        while(current)
        {
            if(hash_key == current->key_hash)
            {
                return current->value;
            }

            if(hash_key < current->key_hash)
            {
                current=current->left;
            }
            else if(hash_key > current->key_hash)
            {
                current = current->right;
            }
        }
        return -1;
    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
	Map map;

    map.insert("Yolo", 20);
    for (std::string& name : TP5::names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
        }
    }

    qDebug("map[\"Margot\"]=%d\n", map.get("Margot"));
    qDebug("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    qDebug("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    qDebug("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    qDebug("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    qDebug("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));


    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new MapWindow(*map.root);
    w->show();
    return a.exec();
}
