#include <iostream>
#include "Plateau.h"

using namespace std;

Plateau::Plateau() : hauteur(9), largeur(15)
{
    tab = new Etat*[hauteur];
    for (int i = 0; i < hauteur; i++)
        tab[i] = new Etat[largeur];
}


Plateau::Plateau(int h, int l)
{
    hauteur = ((h%2 == 1) ? h : 9);
    largeur = ((l%2 == 1) ? l : 15);

    tab = new Etat*[hauteur];
    for (int i = 0; i < hauteur; i++)
        tab[i] = new Etat[largeur];
}

Plateau::Plateau(const Plateau & PlateauCopy)
   : hauteur(PlateauCopy.hauteur), largeur(PlateauCopy.largeur), tab(0)
{
    tab = new Etat*[hauteur];
    for(int i = 0; i < hauteur; i++)
    {
        tab[i] = new Etat[largeur];
        for(int j = 0; j < largeur; j++)
            tab[i][j] = PlateauCopy.tab[i][j];
    }
}

Plateau& Plateau::operator++()
{
    //copie du tableau
    Plateau copyPlat(*this);

    //supression de l'état du tableau au sein du Plateau
    for(int i = 0; i < hauteur; i++)
        delete tab[i];
    delete tab;

    //création d'un nouveau tableau en affectant la nouvelle modification
    hauteur += 2;
    largeur += 2;

    tab = new Etat*[hauteur];
    for (int i = 0; i<hauteur; i++)
        tab[i] = new Etat[largeur];

    //on centre par la même occasion le tableau
    for(int i = 0; i < copyPlat.get_h(); i++)
    {
        for(int j = 0; j < copyPlat.get_l(); j++){
            tab[i+1][j+1].set_d(copyPlat.get_case(i,j).get_d());
            tab[i+1][j+1].set_o(copyPlat.get_case(i,j).get_o());
        }
    }

    return *this;
}

Plateau& Plateau::operator=(Plateau const& PlateauCopy)
{
    hauteur = PlateauCopy.hauteur;
    largeur = PlateauCopy.largeur;

    for(int i = 0; i < hauteur; i++)
        delete tab[i];
    delete tab;

    tab = new Etat*[hauteur];
    for(int i = 0; i < hauteur; i++)
    {
        tab[i]=new Etat[largeur];
        for(int j = 0; j < largeur; j++)
            tab[i][j] = PlateauCopy.tab[i][j];
    }

    return *this;
}

Plateau::~Plateau()
{
    for(int i = 0; i < hauteur; i++)
        delete tab[i];
    delete tab;
}


void Plateau::affiche()
{
    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            switch (tab[i][j].get_d())
            {
            case NORD:
                cout << ((tab[i][j].get_o() == true) ? "N" : "n");
                break;
            case SUD:
                cout << ((tab[i][j].get_o() == true) ? "S" : "s");
                break;
            case EST:
                cout << ((tab[i][j].get_o() == true) ? "E" : "e");
                break;
            case OUEST:
                cout << ((tab[i][j].get_o() == true) ? "O" : "o");
                break;
            }
        }
        cout << endl;
    }
}


Etat& Plateau::get_case(int i, int j)
{
    return tab[i][j];
}


int Plateau::get_h()
{
    return hauteur;
}


int Plateau::get_l()
{
    return largeur;
}
