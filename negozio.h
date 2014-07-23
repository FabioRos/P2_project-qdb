#ifndef NEGOZIO_H
#define NEGOZIO_H

#include "bicicletta.h"
#include "bicidacorsa.h"
#include "bicicomuni.h"
#include "container.h"


/* ____ per r/w _____ */
#include <fstream>
#include <iostream>

#define NOME_FILE "file.dat" //define ripetuto in Bicicletta


class Negozio
{
public:

    Negozio();
    void inserisci_bicicletta(const Bicicletta&);
    void rimuovi_bicicletta(const Bicicletta&);
    void modifica_bicicletta(const Bicicletta&);
    Container<Bicicletta> cerca_bicicletta(string) const;    //Restituisco un contenitore con i puntatori
    void stampa() const;
    bool isEmpty();


    //r/w

    void salva_dati();  //sul serialize manda le cose senza il tipo iniziale, usao per capire e chiama quello giusto!
    void carica_dati(const char*)  throw(Ecc_File_Non_Trovato);
   // string getLineByFile(string,int) const;
    //static string OttieniToken(string s);

private:
    Container<Bicicletta*> shop;
};


ostream& operator << (ostream&, const Negozio&);













#endif // NEGOZIO_H
