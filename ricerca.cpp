#include "ricerca.h"


Ricerca::Ricerca(Negozio* n,QWidget *parent) : db(n), QWidget(parent){
    testo=new QLineEdit(this);

    tipo=new QComboBox(this);
    QString tipoComune_e_Corsa("Bici Comuni e da corsa");
    QString tipoCorsa("Bici da corsa");
    QString tipoComune("Bici Comuni");
    tipo->addItem(tipoComune_e_Corsa);
    tipo->addItem(tipoCorsa);
    tipo->addItem(tipoComune);
    tipo->setCurrentIndex(0);
    connect(tipo,SIGNAL(currentIndexChanged(QString)),this,SLOT(Switch_tipo_ricerca(QString)));

    invia=new QPushButton("cerca");
    connect(invia,SIGNAL(clicked()),this,SLOT(esegui_ricerca()));

    QGridLayout *layout = new QGridLayout();
         // layout->setVerticalSpacing(10);
         QString label_tipo("Selezionare la tipologia.");
         layout->addWidget(new QLabel(label_tipo),0,0);
         layout->addWidget(tipo,0,1);
         QString label_txt("Inserire il testo relativo a marca o modello qui.");
         layout->addWidget(new QLabel(label_txt),1,0);
         layout->addWidget(testo,1,1);
         layout->addWidget(invia,2,0);

    tb=new QTableWidget(0,13,this);
    layout->addWidget(tb,3,0,1,2);

         setLayout(layout);
         this->show();

}
//SLOT
void Ricerca::Switch_tipo_ricerca(QString nuovo_tipo){
  esegui_ricerca(nuovo_tipo);
}

void Ricerca::esegui_ricerca(QString tipo_corrente){

 //   QString t=tipo->currentText();//.toStdString();
    QString m=testo->text();//.toStdString();
    for(int a=tb->rowCount(); a>=0; --a){
        tb->removeRow(a);
    }
    for(Container<record*>::Iteratore i=rec.begin(); i!=rec.end(); ++i){
        record* r=*i;
        delete r;
    }
    rec=Container<record*>();
    Container<Bicicletta*> aux=db->ricerca_bicicletta(tipo_corrente.toStdString(),m.toStdString());

    for(Container<Bicicletta*>::Iteratore it=aux.begin();it!=aux.end();++it){
        rec.aggiungiElemento(new record(*it,0));    // siccome questo contenitore non è modificabile trascuro
                                                    // i numeri di riga lasciandoli a 0
    }
    genera_tabella();
}



void Ricerca::genera_tabella(){

    QStringList sls;
    sls<<"Marca"<<"Modello"<<"Lunghezza"<<"Altezza"<<"Prezzo"<<"Cestino"<<"Seggiolino"<<"Portapacchi"<<"Copricatena"<<"Fanale"<<"Specialita'"<<"Materiale"<<"Peso";
    tb->setHorizontalHeaderLabels(sls);
    tb->setColumnWidth(0,90);
    tb->setColumnWidth(1,90);
    tb->setColumnWidth(2,88);
    tb->setColumnWidth(3,60);
    tb->setColumnWidth(4,80);
    tb->setColumnWidth(5,60);
    tb->setColumnWidth(6,80);
    tb->setColumnWidth(7,90);
    tb->setColumnWidth(8,90);
    tb->setColumnWidth(9,50);
    tb->setColumnWidth(10,80);
    tb->setColumnWidth(11,80);

    for(Container<record*>::Iteratore it=rec.begin();it!=rec.end();++it){
        int a=tb->rowCount();
        tb->insertRow(a);
        tb->setCellWidget(a,0, (*it)->WidgetMarca() );
        tb->setCellWidget(a,1, (*it)->WidgetModello() );
        tb->setCellWidget(a,2, (*it)->WidgetLunghezza() );
        tb->setCellWidget(a,3, (*it)->WidgetAltezza() );
        tb->setCellWidget(a,4, (*it)->WidgetPrezzo() );
        tb->setCellWidget(a,5, (*it)->WidgetCestino() );
        tb->setCellWidget(a,6, (*it)->WidgetSeggiolino() );
        tb->setCellWidget(a,7, (*it)->WidgetPortapacchi() );
        tb->setCellWidget(a,8, (*it)->WidgetCopricatena() );
        tb->setCellWidget(a,9, (*it)->WidgetFanale() );
        tb->setCellWidget(a,10, (*it)->WidgetSpecialita() );
        tb->setCellWidget(a,11, (*it)->WidgetMateriale() );
        tb->setCellWidget(a,12, (*it)->WidgetPeso() );
        //per fare in modo che non possa editare niente, disabilito il wdget della tabella dei risultati
        tb->setEnabled(false);
    }

}
