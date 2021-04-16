#include <tp5.h>
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;


std::vector<string> TP5::names(
{
    "Steeve", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Theo", "Vincent", "Paul", "Zoe", "Julien",
    "Fanny", "Jeanne", "Elo","Lisa"
});


int HashTable::hash(std::string word)
{
    // use this->size() to get HashTable size
    int taille=(int)this->size();
    int val=(int)word[0];
    if(val<taille)
    {
        return val;
    }
    return val%taille;
}

void HashTable::insert(std::string word)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    this->set(hash(word),word);
}

/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fiil
 * @param names array of names to insert
 * @param namesCount size of names array
 */
void buildHashTable(HashTable& table, std::string* names, int namesCount)
{
        for(int i=0; i<namesCount; i++)
        {
            table.insert(names[i]);
        }
}

bool HashTable::contains(std::string word)
{
    int index=hash(word);
    if(this->get(index)==word)
    {return true;}
    return false;
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 10;
	w = new HashWindow();
	w->show();

	return a.exec();
}
