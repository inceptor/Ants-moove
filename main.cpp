#include <iostream>
#include "Fourmiliere.h"

using namespace std;

int main()
{
    int x = 0, y = 0, nbF = 0;

    cout << "Bienvenue dans Rotor Router" << endl;

    cout << "Quel est la hauteur du plateau : ";
    cin >> x;

    cout << "Quel est la largeur du plateau : ";
    cin >> y;

    cout << "Quel est le nombre de fourmi de votre fourmiliere : ";
    cin >> nbF;

    Plateau plat(x,y);
    Fourmiliere f(plat);

    cout << endl;
    f.affiche();
    cout << endl;

    for(int i = 0; i < (nbF - 1); i++)
    {
        f.ajout();
        f.affiche();
    }

    f.stats();

    return 0;
}
