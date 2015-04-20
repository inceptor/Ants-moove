#ifndef FOURMILIERE_H_INCLUDED
#define FOURMILIERE_H_INCLUDED

#include <vector>
#include "Fourmi.h"

class Fourmiliere {

private:
    Plateau* plateau;
    std::vector<Fourmi> popu;
    static int nb;

public:
    Fourmiliere(Plateau& plat);
    void ajout();
    void affiche();
    void stats();
    void stat(int n, int m);

};

#endif // FOURMILIERE_H_INCLUDED
