#include "negozio.h"

/*

  E' una clase che mi serve per avere un controllo più customizzato del container
  riguardo alla classe Bicicletta offrendo funzionalità non generiche e quindo non
  comprendibili nel container.

*/

Negozio::Negozio(){}

void Negozio::inserisci_bicicletta(const Bicicletta& b){
            shop.aggiungiElemento(const_cast<Bicicletta*>(&b));
}



bool Negozio::isEmpty(){
    return shop.isEmpty();
}

void Negozio::rimuovi_bicicletta(const Bicicletta& b){
    shop.rimuoviElemento(const_cast<Bicicletta*>(&b));
}

void Negozio::modifica_bicicletta(const Bicicletta& b){
    modifica_bicicletta(b);
}

void Negozio::carica_dati(string str="") const throw(Ecc_File_Non_Trovato){
    if(str=="")throw(Ecc_File_Non_Trovato());

}

void Negozio::stampa() const{ // da testare


    for (Container<Bicicletta*>::Iteratore it=shop.begin(); it != shop.end(); it++){
        //cout<<typename(this->shop[it]);
        (this->shop[it])->stampa();
        std::cout<<endl;
    }


}



void Negozio::salva_dati(/*string s*/){     //TESTING
    /*QFile output;
        output.open(stdout, QIODevice::WriteOnly);
    //! [write output]
    //! [start stream]
        QXmlStreamWriter stream(&output);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
    //! [start stream]
        stream.writeDTD("<!DOCTYPE xbel>");
        stream.writeStartElement("xbel");
        stream.writeAttribute("version", "1.0");
        stream.writeStartElement("folder");
        stream.writeAttribute("folded", "no");
    //! [write element]
        stream.writeStartElement("bookmark");
        stream.writeAttribute("href", "http://qt.nokia.com/");
        stream.writeTextElement("title", "Qt Home");
        stream.writeEndElement(); // bookmark
    //! [write element]
        stream.writeEndElement(); // folder
        stream.writeEndElement(); // xbel
    //! [finish stream]
        stream.writeEndDocument();
    //! [finish stream]
    //! [write output]
        output.close();*/

}
