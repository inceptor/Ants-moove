#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "Etat.h"

class Plateau{

private:
    Etat** tab;
    int hauteur, largeur;

public:
    Plateau();
    Plateau(int h, int l);
    Plateau(const Plateau & PlateauCopy);
    Plateau& operator++();
    Plateau& operator=(Plateau const& PlateauCopy);
    ~Plateau();

    void affiche();
    Etat& get_case(int i, int j);
    int get_h();
    int get_l();
};

#endif // PLATEAU_H_INCLUDED
