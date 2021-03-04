#include <iostream>

using namespace std;

//---------------------------------------------
//                  STRUCTURES
//---------------------------------------------
struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

struct DynaTableau{
    int taille;
    int capacite;
    int * donnee;

};

//-------------------------------------------------
//                 LISTES           
//-------------------------------------------------
void initialise(Liste* liste)
{
    liste=(Liste*)malloc(sizeof(liste));
}

bool est_vide(const Liste* liste)
{
    if(not liste->premier)
    {
        return false;
    }
    return true;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* current= liste->premier;
    if(liste){
        if (current->suivant == NULL && current->donnee == NULL){
            current->donnee = valeur;
            current->suivant = NULL;
        }
        else
        {        
            while(current->suivant)
            {
                current=current->suivant;
            }
            Noeud * ajout = (Noeud*)malloc(sizeof(struct Noeud));
    
            current->suivant = ajout;
            ajout->donnee=valeur;
            ajout->suivant=NULL;
        }
    }
}

void affiche(const Liste* liste)
{
    Noeud* current = liste->premier;
    while(current)
    {
        std::cout << current->donnee << " ";
        current=current->suivant;
    }
}

int recupere(const Liste* liste, int n)
{
    Noeud* current= liste->premier;
    for(int count=0; count<n ; count++)
    {
        current=current->suivant;
    }
    return current->donnee;
    
    return 0;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* current = liste->premier;
    int i =0;
    while(current)
    {
        if(current->donnee==valeur)
        {
            return i;
        }
        i++;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* current=liste->premier;
    for(int i =0; i<n ; i++)
    {
        if(current->suivant)
        {
            current=current->suivant;
        }
        else
        {
            std::cout << " n est trop grand!"<< endl;
        }
    }
    current->donnee=valeur;
}


//-------------------------------------------------
//                 TABLEAUX           
//-------------------------------------------------

void initialise(DynaTableau* tableau, int capacite) //ok
{   
    tableau=(DynaTableau*)malloc(capacite*sizeof(int));
    tableau->capacite=capacite;
    for (int i = 0; i <capacite; i++) 
    {
        tableau->donnee[i]=NULL;
    }
}

bool est_vide(const DynaTableau* tableau)
{
    if(tableau->taille==0)
    {
        return true;
    }
    return false;
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if((tableau->taille) >= (tableau->capacite))
    {  
        tableau=(DynaTableau*)realloc(tableau, tableau->capacite+1);
        tableau->capacite++;
    }

    (tableau->taille)++;
    tableau->donnee[tableau->taille]=valeur;
}

void affiche(const DynaTableau* tableau)
{
    for(int i =0 ; i<tableau->taille; i++)
    {
        std::cout<< tableau->donnee[i]<< " ";
    }
    std::cout << "\n";
}

int recupere(const DynaTableau* tableau, int n)
{
    if(n<tableau->taille)
    {
        return tableau->donnee[n];
    }
    return 0;
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i =0 ; i<tableau->taille ; i++)
    {
        if (tableau->donnee[i]==valeur)
        {
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if(n<tableau->taille)
    {
        tableau->donnee[n]=valeur;
    }
    else
    {
        std::cout << " n est trop grand"<< std::endl;
    }
}

//----------------------------------------------
//                  FILE
//----------------------------------------------
void pousse_file(Liste* liste, int valeur)//on ajoute une valeur au debut de la file 
{
    Noeud * temp = (Noeud*)malloc(sizeof(struct Noeud));
    Noeud * temp2 = (Noeud*)malloc(sizeof(struct Noeud));
    temp = liste->premier;
    temp2->donnee = temp->donnee;
    temp2->suivant = temp->suivant;
    liste->premier->donnee = valeur;
    liste->premier->suivant = temp2;
}

void retire_file(Liste *liste)//on enlève la derniere valeur de la file
{
  Noeud *current = liste->premier;
  if(current)
  {
    if (current->suivant == NULL && current->donnee == NULL)
    {
        current->donnee = NULL;
        current->suivant = NULL;//la file est deja vide donc rien ne change
    }
    else
    {
      while (current->suivant->suivant)
      {
        current  = current->suivant;
      }
      current->suivant=NULL;
    }
  }
}
//-----------------------------------------------
//                  PILE
//-----------------------------------------------

void pousse_pile(DynaTableau* tab, int valeur)//on met la nouvelle valeur à la toute fin
{
    if(tab->taille>=tab->capacite)
    {  
        tab=(DynaTableau*)realloc(tab, tab->capacite+1);
        tab->capacite++;
    }
    (tab->taille)++;
    tab->donnee[tab->taille]=valeur;
}

int retire_pile(DynaTableau* tab)//on renvoie la derniere valeur(celle qui a été mise en dernier)
{
    return tab->donnee[tab->taille];
}


//------------------------------------------------

int main()
{
    Liste *liste;
    initialise(liste);
    DynaTableau *tableau;
    initialise(tableau, 5);

    if (!est_vide(liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau (ini)" << std::endl;
    }
    std::cout <<"avant boucle"<<endl;
    for (int i=1; i<=7; i++) {
        ajoute(liste, i*7);
        ajoute(tableau, i*5);
    }

    if (est_vide(liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau(ajoute)" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(liste);
    affiche(tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(tableau, 15) << std::endl;

    stocke(liste, 4, 7);
    stocke(tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(liste);
    affiche(tableau);
    std::cout << std::endl;

    DynaTableau *pile; // DynaTableau pile;
    Liste *file; // Liste file;

    initialise(pile,10);
    initialise(file);

    for (int i=1; i<=7; i++) {
        pousse_file(file, i);
        pousse_pile(pile, i);
    }

    int compteur = 10;
    while(!est_vide(file) && compteur > 0)
    {
        retire_file(file);
        affiche(file);
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(pile) && compteur > 0)
    {
        retire_pile(pile);
        affiche(pile);
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}