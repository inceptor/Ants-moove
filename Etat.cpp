#include <iostream>
#include "Etat.h"

using namespace std;

Etat::Etat() : occupe(false), direction(OUEST)
{
    //all done
}


Etat::Etat(bool o,int d)
{
    set_o(o);
    set_d(d);
}


bool Etat::get_o()
{
    return occupe;
}


int Etat::get_d()
{
    return direction;
}


void Etat::set_o(bool o)
{
    occupe = o;
}


void Etat::set_d(int d)
{
    direction = (d >= 1 && d <= 4) ? d : 1;

}


void Etat::modif_d()
{
    direction = ( (direction+1) > 4 ) ? 1 : direction + 1;
}
