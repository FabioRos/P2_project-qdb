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
    connect(ins,SIGNAL(aggiunta_bici()),tb,SLOT(aggiorna()));
    connect(ins,SIGNAL(aggiunta_bici()),this,SLOT(aggiuntabici()));


    QStatusBar* barra_footer=new QStatusBar(this);
    elimina=new QPushButton("elimina",this);
    barra_footer->addWidget(elimina);
    setStatusBar(barra_footer);
    connect(mng_schede,SIGNAL(currentChanged(int)),this,SLOT(disabilita_status_bar(int)));
    connect(elimina,SIGNAL(clicked()),tb,SLOT(eliminaRiga()));
}

void Finestra_Principale::aggiuntabici()
{
    mng_schede->setCurrentIndex(0);

}

void Finestra_Principale::disabilita_status_bar(int i){
    if(i!=0)
        elimina->setVisible(false);
    else
        elimina->setVisible(true);
}
