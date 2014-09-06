#include "finestra_principale.h"

Finestra_Principale::Finestra_Principale(Negozio& n, QWidget *parent) :shop(&n),mng_schede(new QTabWidget(this)) ,QMainWindow(parent){

    setCentralWidget(mng_schede);
    mng_schede->setMinimumHeight(600);
    mng_schede->setMinimumWidth(1212);
    mng_schede->addTab(new tabella(&n,this),"resoconto");  //index==0
    mng_schede->addTab(new QWidget(),"aggiungi");   //index==1

    //al posto di new QWidget devo mettere poi il Widget giusto che devo richiamare li
}
