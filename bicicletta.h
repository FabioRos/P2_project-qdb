#ifndef BICICLETTA_H
#define BICICLETTA_H


#include <iostream>
#include <string>
#include "eccezioni.h"
#include <sstream>  //serve per salvare i numeri in formato stringa


using namespace std;

class Bicicletta
{
protected:
    Bicicletta();
    Bicicletta(string,string,float,float,double);
public: 
    virtual ~Bicicletta();  //perche se voglio distruggere una bici da corsa con un punt
                            //a bicicletta dealloca solo la parte della bicicletta e non
                            //quella relativa al sottoggetto (bicidacorsa - bicicletta)

    string getMarca() const throw();
    string getModello() const throw();
    float getLunghezza() const throw();
    float getAltezza() const throw();

    double getPrezzo() const throw();
    void setMarca(string);
    void setModello(string);
    void setLunghezza(float);
    void setAltezza(float);
    void setPrezzo(double)throw(Ecc_num_negativo_inaspettato);

    //così posso invocarlo con i sottoggetti che hanno tipo dinamico diverso
    virtual bool operator==(const Bicicletta&) const;
    virtual void stampa() const;
    void modifica(string ma, string mo, float l, float a, double p);
    virtual void modifica(const Bicicletta&);

private:
    string marca;
    string modello;
    float lunghezza;
    float altezza;
    double prezzo;
};

ostream& operator << (ostream&, const Bicicletta&);

#endif // BICICLETTA_H
