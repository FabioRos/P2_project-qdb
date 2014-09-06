#include "finestra_principale.h"

Finestra_Principale::Finestra_Principale(Negozio& n, QWidget *parent) :shop(&n),mng_schede(new QTabWidget(this)) ,QMainWindow(parent){

    setCentralWidget(mng_schede);
    mng_schede->setMinimumHeight(600);
    mng_schede->setMinimumWidth(1143);
    Inserimento* ins=new Inserimento(&n, this);
    tabella* tb=new tabella(&n,this);
    Ricerca* ric=new Ricerca(&n,this);
    mng_schede->addTab(tb,"resoconto");         //index==0
    mng_schede->addTab(ins,"aggiungi");         //index==1
    mng_schede->addTab(ric,"ricerca");          //index==2

    //al posto di new QWidget devo mettere poi il Widget giusto che devo richiamare li

    connect(ins,SIGNAL(aggiunta_bici()),tb,SLOT(aggiorna()));
}
