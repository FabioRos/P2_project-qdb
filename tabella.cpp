#include "tabella.h"

tabella::tabella(Negozio *n, QWidget *parent) : ptrNegozio(n), QTableWidget(0,14,parent){
    QStringList sls;
    sls<<"Marca"<<"Modello"<<"Lunghezza"<<"Altezza"<<"Prezzo"<<"Cestino"<<"Seggiolino"<<"Portapacchi"<<"Copricatena"<<"Fanale"<<"Specialita'"<<"Materiale"<<"Peso"<<"Elimina";
    setHorizontalHeaderLabels(sls);
    setColumnWidth(0,90);
    setColumnWidth(1,90);
    setColumnWidth(2,88);
    setColumnWidth(3,60);
    setColumnWidth(4,80);
    setColumnWidth(5,60);
    setColumnWidth(6,80);
    setColumnWidth(7,90);
    setColumnWidth(8,90);
    setColumnWidth(9,50);
    setColumnWidth(10,80);
    setColumnWidth(11,80);
    setColumnWidth(12,80);
    aggiorna();
}


void tabella::inserisci_riga(record* riga){
    int a=rowCount();
    QTableWidget::insertRow(a);
    setCellWidget(a,0, riga->WidgetMarca() );
    setCellWidget(a,1, riga->WidgetModello() );
    setCellWidget(a,2, riga->WidgetLunghezza() );
    setCellWidget(a,3, riga->WidgetAltezza() );
    setCellWidget(a,4, riga->WidgetPrezzo() );
    setCellWidget(a,5, riga->WidgetCestino() );
    setCellWidget(a,6, riga->WidgetSeggiolino() );
    setCellWidget(a,7, riga->WidgetPortapacchi() );
    setCellWidget(a,8, riga->WidgetCopricatena() );
    setCellWidget(a,9, riga->WidgetFanale() );
    setCellWidget(a,10, riga->WidgetSpecialita() );
    setCellWidget(a,11, riga->WidgetMateriale() );
    setCellWidget(a,12, riga->WidgetPeso() );
    setCellWidget(a,13, riga->WidgetElimina());
    setCurrentCell(a,0);
}

void tabella::aggiorna(){
  Container<Bicicletta*> db=ptrNegozio->getAll();
    //pulisco tutta la tabella
    for(int a=rowCount(); a>=0; --a){
        QTableWidget::removeRow(a);
    }
    for(Container<record*>::Iteratore i=righe.begin();i!=righe.end();++i){
        delete *i;
    }

    //ora ripopolo con i nuovi
    for(Container<Bicicletta*>::Iteratore i=db.begin();i!=db.end();++i){
        record* r=new record(*i);
        connect(r,SIGNAL(eliminariga(record*)),this,SLOT(eliminaRiga(record*)));
        righe.aggiungiElemento(r);
        inserisci_riga(r);
    }
}

void tabella::eliminaRiga(record *r){
    int i = QTableWidget::currentRow();
    Bicicletta * tmp = ptrNegozio->getBicicletta(i);
    righe.rimuoviElemento(r);
    ptrNegozio->rimuovi_bicicletta(*tmp);
    QTableWidget::removeRow(i);
}

