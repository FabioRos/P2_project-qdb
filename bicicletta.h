#ifndef BICICLETTA_H
#define BICICLETTA_H

#define NOME_FILE "file.dat"

#include <iostream>
#include <string>
#include "eccezioni.h"
#include <sstream>  //serve per salvare i numeri in formato stringa
#include "utilita.h"

using namespace std;

class Bicicletta
{
protected:
    Bicicletta();
    Bicicletta(string,string,float,float,int,double);
public: 
    virtual ~Bicicletta();  //perche se voglio distruggere una bici da corsa con un punt
                            //a bicicletta dealloca solo la parte della bicicletta e non
                            //quella relativa al sottoggetto (bicidacorsa - bicicletta)

    string getMarca() const throw();
    string getModello() const throw();
    float getLunghezza() const throw();
    float getAltezza() const throw();
    int getQuantita() const throw();
    double getPrezzo() const throw();
    void aggiungi(int)throw(Ecc_num_negativo_inaspettato);                        //aumento la quatità
    void togli(int) throw(Ecc_num_negativo_inaspettato, Ecc_tolti_troppi);        //diminuisco la quantità
    void setMarca(string);
    void setModello(string);
    void setLunghezza(float);
    void setAltezza(float);
    void setPrezzo(double)throw(Ecc_num_negativo_inaspettato);

    //così posso invocarlo con i sottoggetti che hanno tipo dinamico diverso
    virtual bool operator==(const Bicicletta&) const;
    virtual void stampa() const;
    void modifica(string ma, string mo, float l, float a, int q, double p);
    virtual void modifica(const Bicicletta&);



    virtual string serializza() const;
    static Bicicletta* parse(const string&); // creo una bicicletta con new e ritorno il puntatore
private:
    string marca;
    string modello;
    float lunghezza;
    float altezza;
    int quantita;
    double prezzo;
};

ostream& operator << (ostream&, const Bicicletta&);

#endif // BICICLETTA_H
