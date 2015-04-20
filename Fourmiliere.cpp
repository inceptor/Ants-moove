#include <iostream>
#include <algorithm>
#include "Fourmiliere.h"

using namespace std;

int Fourmiliere::nb = 0;

Fourmiliere::Fourmiliere(Plateau& plat)
{
    plateau = &plat;
    popu.push_back(Fourmi(plat));
    nb++;
}


void Fourmiliere::ajout()
{
    popu.push_back(Fourmi(*plateau));
    nb++;
}


void Fourmiliere::affiche()
{
    cout << "Fourmi numero " << nb << endl << endl;

    plateau->affiche();

    cout << "Distance parcourue par cette fourmi : " << popu.at(nb-1).get_d() << endl << endl;
}


void Fourmiliere::stats()
{
    stat(0,nb-1);
}


void Fourmiliere::stat(int n, int m)
{
    int minimum = popu.at(n).get_d() , maximum = popu.at(n).get_d(), moyenne = popu.at(n).get_d(), numMin = 0, numMax = 0;

    vector<Fourmi>::iterator i;

    for(int i = n+1; i <= m; i++)
    {
        if(popu.at(i).get_d() > maximum)
        {
            maximum = popu.at(i).get_d();
            numMax = i;
        }
        else if(popu.at(i).get_d() < minimum)
        {
            minimum = popu.at(i).get_d();
            numMin = i;
        }

        moyenne += popu.at(i).get_d();
    }

    moyenne /= (m - n);


    cout << "La moyenne est : " << moyenne << endl;
    cout << "Le maximum est : " << maximum << " Qui est la fourmi numero " << numMax + 1 << endl;
    cout << "Le minimum est : " << minimum << " Qui est la fourmi numero " << numMin + 1 << endl;
}
