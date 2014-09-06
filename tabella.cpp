#include "tabella.h"

tabella::tabella(Negozio *n, QWidget *parent) : ptrNegozio(n), QTableWidget(0,15,parent){
    QStringList sls;
    sls<<"Marca"<<"Modello"<<"Lunghezza"<<"Altezza"<<"Quantita'"<<"Prezzo"<<"Cestino"<<"Seggiolino"<<"Portapacchi"<<"Copricatena"<<"Fanale"<<"Specialita'"<<"Materiale"<<"Peso"<<"Elimina";
    setHorizontalHeaderLabels(sls);
    setColumnWidth(0,90);
    setColumnWidth(1,90);
    setColumnWidth(2,88);
    setColumnWidth(3,60);
    setColumnWidth(4,70);
    setColumnWidth(5,80);
    setColumnWidth(6,60);
    setColumnWidth(7,80);
    setColumnWidth(8,90);
    setColumnWidth(9,90);
    setColumnWidth(10,50);
    setColumnWidth(11,80);
    setColumnWidth(12,80);
    setColumnWidth(13,80);
    aggiorna();
}


void tabella::inserisci_riga(record* riga){
    int a=rowCount();
    QTableWidget::insertRow(a);
    setCellWidget(a,0, riga->WidgetMarca() );
    setCellWidget(a,1, riga->WidgetModello() );
    setCellWidget(a,2, riga->WidgetLunghezza() );
    setCellWidget(a,3, riga->WidgetAltezza() );
    setCellWidget(a,4, riga->WidgetQuantita() );
    setCellWidget(a,5, riga->WidgetPrezzo() );
    setCellWidget(a,6, riga->WidgetCestino() );
    setCellWidget(a,7, riga->WidgetSeggiolino() );
    setCellWidget(a,8, riga->WidgetPortapacchi() );
    setCellWidget(a,9, riga->WidgetCopricatena() );
    setCellWidget(a,10, riga->WidgetFanale() );
    setCellWidget(a,11, riga->WidgetSpecialita() );
    setCellWidget(a,12, riga->WidgetMateriale() );
    setCellWidget(a,13, riga->WidgetPeso() );
    setCellWidget(a,14, riga->WidgetElimina());
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
        righe.aggiungiElemento(r);
        inserisci_riga(r);
    }
}
