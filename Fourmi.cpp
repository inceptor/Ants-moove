#include <iostream>
#include "Fourmi.h"

using namespace std;


Fourmi::Fourmi(Plateau& plat)
{
    i = (plat.get_h() / 2);
    j = (plat.get_l() / 2);

    for(d = 0; plat.get_case(i,j).get_o() != false; d++)
    {
        //Etape 1 : changement de direction
        plat.get_case(i,j).modif_d();

        //Etape 2 : on avance en fonction de la direction
        switch (plat.get_case(i,j).get_d()){
        case NORD:
            i--;
            break;
        case SUD:
            i++;
            break;
        case OUEST:
            j--;
            break;
        case EST:
            j++;
            break;
        }
    }

    plat.get_case(i,j).set_o(true);
}


int Fourmi::get_d()
{
    return d;
}


bool operator<(const Fourmi& a, const Fourmi& b)
{
    return a.d < b.d;
}
