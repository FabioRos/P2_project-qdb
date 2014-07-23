#include "finestra_principale.h"

Finestra_Principale::Finestra_Principale(Negozio& n, QWidget *parent) :shop(&n),mng_schede(new QTabWidget(this)) ,QMainWindow(parent){

    setCentralWidget(mng_schede);
    mng_schede->setMinimumHeight(600);
    mng_schede->setMinimumWidth(800);
    mng_schede->addTab(new QWidget(),"resoconto");
    mng_schede->addTab(new QWidget(),"aggiungi");
    mng_schede->addTab(new QWidget(),"rimuovi");
    mng_schede->addTab(new QWidget(),"ricerca");
    mng_schede->addTab(new QWidget(),"modifica");

    //al posto di new QWidget devo mettere poi il Widget giusto che devo richiamare li
}

