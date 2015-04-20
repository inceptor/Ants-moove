#ifndef FOURMI_H_INCLUDED
#define FOURMI_H_INCLUDED

#include "Plateau.h"

class Fourmi{

private:
    int i, j;
    int d;

public:
    Fourmi(Plateau& plat);
    int get_d();
    friend bool operator<(const Fourmi& a, const Fourmi& b);
};

#endif // FOURMI_H_INCLUDED
