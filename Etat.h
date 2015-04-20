#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

enum {OUEST = 1, NORD = 2, EST = 3, SUD = 4};

class Etat{

private:
    bool occupe;
    int direction;

public:
    Etat();
    Etat(bool o,int d);
    bool get_o();
    int get_d();
    void set_o(bool o);
    void set_d(int d);
    void modif_d();
};

#endif // ETAT_H_INCLUDED
