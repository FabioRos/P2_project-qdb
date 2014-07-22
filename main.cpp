#include <iostream>
#include "container.h"
#include "negozio.h"


#include <QApplication>
#include <QIcon>

using namespace std;

#include <iostream>
#include "container.h"
#include "finestra_principale.h"
/*
int main(int argc, char* argv[]){



    QApplication app(argc,argv);

    Negozio rivenditore;
    Finestra_Principale Pannello(rivenditore,0);

    Pannello.show();    //show() è virtuale di qWidget e implementato da qMainWindow
    QObject::connect(qApp,SIGNAL(lastWindowClosed()),qApp,SLOT(quit()));
    return QApplication::exec();









*/

int main(){
    //cout << "OK" << endl;


    //Container<int> DB;

    //cout<< DB.aggiungiElemento(1);

    //DB.cercaElemento(1);


  /*  Bicicletta b;
    //cout<< b;
    Bicicletta b2("Pinarello","Dogma",58,56,10,350);*/
   /* cout<<" Marca b2:"<<b2.getMarca()<<endl;
    cout<<" Modello b2:"<<b2.getModello()<<endl;
    cout<<" Altezza b2:"<<b2.getAltezza()<<endl;
    cout<<" Lunghezza b2:"<<b2.getLunghezza()<<endl;
    cout<<" Prezzo b2:"<<b2.getPrezzo()<<endl;

    cout<<" Quantità b2:"<<b2.getQuantita()<<endl;
    b2.togli(5);
    cout<<" Quantità b2:"<<b2.getQuantita()<<endl;
    //b2.togli(10);
*/
    //b2.aggiungi(-6);
    //cout<<" Quantità b2:"<<b2.getQuantita()<<endl;

    /*  Container<Bicicletta> Negozio;
    cout<<" vuoto? " <<Negozio.isEmpty()<<endl;

    Negozio.aggiungiElemento(b2);

    cout<<" vuoto? " <<Negozio.isEmpty()<<endl;

    Negozio.stampa();*/

    Bicicletta b1;
    BiciDaCorsa b2;
    BiciComuni b3(true,false,false,true,true);
//    b1.stampa();
//    b2.stampa();
//    b3.stampa();
    Negozio n;
    n.inserisci_bicicletta(b1);
    n.inserisci_bicicletta(b2);
    n.inserisci_bicicletta(b3);
    cout<<n.isEmpty();
    n.stampa();
    n.salva_dati();
    cout<< b1.serializza();
    cout<< b2.serializza();
    cout<< b3.serializza();
    b1.parse(b1.serializza());
}
