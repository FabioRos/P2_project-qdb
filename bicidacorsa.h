#ifndef BICIDACORSA_H
#define BICIDACORSA_H

#include <iostream>
#include "bicicletta.h"

using namespace std;

class BiciDaCorsa : public Bicicletta
{
public:
    BiciDaCorsa();
    BiciDaCorsa(const Bicicletta& b,string,string,double);
    BiciDaCorsa(string,string,float,float,double,string,string,double);
    bool operator==(const BiciDaCorsa&) const;
    void stampa() const;
    string getSpecialita() const;
    string getMateriale() const;
    double getPeso() const;
    void setSpecialita(string);
    void setMateriale(string);
    void setPeso(double);
    void modifica(const Bicicletta&);
private:
    string specialita;    //crono, strada, Pista
    string materiale;
    double peso;

};

#endif // BICIDACORSA_H
