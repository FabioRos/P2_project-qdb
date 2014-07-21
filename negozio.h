#ifndef NEGOZIO_H
#define NEGOZIO_H

#include "bicicletta.h"
#include "bicidacorsa.h"
#include "bicicomuni.h"
#include "container.h"


/* ____ per r/w _____ */
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>

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
    void salva_dati(/*string*/);
    void carica_dati(string) const throw(Ecc_File_Non_Trovato);
    //DEVO CENTRALIZZARE IL NOME DEL FILE DI OUTPUT
private:
    Container<Bicicletta*> shop;
};


ostream& operator << (ostream&, const Negozio&);













#endif // NEGOZIO_H
