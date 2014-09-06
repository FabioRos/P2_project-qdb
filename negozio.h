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
    Container<Bicicletta*> cerca_bicicletta(const Bicicletta&) const;    //Restituisco un contenitore con i puntatori
    Bicicletta* getBicicletta(int) const;
    Container<Bicicletta*> getAll() const;
    //fai cerca per marca, tipo, ....

    void stampa() const;
    bool isEmpty() const;


private:
    Container<Bicicletta*> shop;
};


ostream& operator << (ostream&, const Negozio&);













#endif // NEGOZIO_H
