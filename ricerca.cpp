#include "ricerca.h"

Ricerca::Ricerca(Negozio* n,QWidget *parent) : db(n), QWidget(parent){

    testo=new QLineEdit(this);
    invia=new QPushButton("cerca");
    tipo=new QComboBox(this);
    QString tipoCorsa("Bici da corsa");
    QString tipoComune("Bici Comuni");
    tipo->addItem(tipoCorsa);
    tipo->addItem(tipoComune);
    tipo->setCurrentIndex(1);
    //connect(tipo,SIGNAL(currentIndexChanged(QString)),this,SLOT(Switch_tipo(QString)));

    QGridLayout *layout = new QGridLayout();
         // layout->setVerticalSpacing(10);
         QString label_tipo("Selezionare la tipologia.");
         layout->addWidget(new QLabel(label_tipo),0,0);
         layout->addWidget(tipo,0,1);
         QString label_txt("Inserire il testo qui.");
         layout->addWidget(new QLabel(label_txt),1,0);
         layout->addWidget(testo,1,1);
         layout->addWidget(invia,2,0);



         setLayout(layout);
         this->show();

}
