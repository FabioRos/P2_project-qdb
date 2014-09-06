#include "inserimento.h"

Inserimento::Inserimento(Negozio *n, QWidget *parent) :  negozio(n), QWidget(parent){
    tipo=new QComboBox();
    QString tipoCorsa("Bici da corsa");
    QString tipoComune("Bici Comuni");
    tipo->addItem(tipoCorsa);
    tipo->addItem(tipoComune);
    tipo->setCurrentIndex(1);
    connect(tipo,SIGNAL(currentIndexChanged(QString)),this,SLOT(Switch_tipo(QString)));
    marca=new QLineEdit();
    modello=new QLineEdit();
    lunghezza=new QDoubleSpinBox();
    altezza=new QDoubleSpinBox();
    prezzo=new QDoubleSpinBox();
    prezzo->setMaximum(99999);
    //Campi di Bici Comuni
    cestino=new QCheckBox();
    seggiolino=new QCheckBox();
    portapacchi=new QCheckBox();
    copricatena=new QCheckBox();
    fanale=new QCheckBox();
    //Campi di Bici da Corsa
    specialita=new QLineEdit();
    materiale=new QLineEdit();
    peso=new QDoubleSpinBox();
        specialita->setEnabled(false);
        materiale->setEnabled(false);
        peso->setEnabled(false);

    //bottone inserimento
     inserisci=new QPushButton("inserisci");
     connect(inserisci,SIGNAL(clicked()),this,SLOT(Inserisci_nel_db()));
    // connect(elimina,SIGNAL(clicked()),this,SLOT(eliminariga()));

      QGridLayout *layout = new QGridLayout();
           // layout->setVerticalSpacing(10);
           QString label_tipo("Tipo");
           layout->addWidget(new QLabel(label_tipo),0,0);
           layout->addWidget(tipo,0,1);
           QString label_marca("Marca");
           layout->addWidget(new QLabel(label_marca),1,0);
           layout->addWidget(marca,1,1);
           QString label_modello("Modello");
           layout->addWidget(new QLabel(label_modello),2,0);
           layout->addWidget(modello,2,1);
           QString label_lunghezza("Lunghezza");
           layout->addWidget(new QLabel(label_lunghezza),3,0);
           layout->addWidget(lunghezza,3,1);
           QString label_altezza("altezza");
           layout->addWidget(new QLabel(label_altezza),4,0);
           layout->addWidget(altezza,4,1);
           QString label_prezzo("Prezzo");
           layout->addWidget(new QLabel(label_prezzo),5,0);
           layout->addWidget(prezzo,5,1);
           QString label_cestino("cestino");
           layout->addWidget(new QLabel(label_cestino),6,0);
           layout->addWidget(cestino,6,1);
           QString label_seggiolino("Seggiolino");
           layout->addWidget(new QLabel(label_seggiolino),7,0);
           layout->addWidget(seggiolino,7,1);
           QString label_portapacchi("Portapacchi");
           layout->addWidget(new QLabel(label_portapacchi),8,0);
           layout->addWidget(portapacchi,8,1);
           QString label_copricatena("Copricatena");
           layout->addWidget(new QLabel(label_copricatena),9,0);
           layout->addWidget(copricatena,9,1);
           QString label_fanale("Fanale");
           layout->addWidget(new QLabel(label_fanale),10,0);
           layout->addWidget(fanale,10,1);
           QString label_specialita("specialita");
           layout->addWidget(new QLabel(label_specialita),11,0);
           layout->addWidget(specialita,11,1);
           QString label_materiale("Materiale");
           layout->addWidget(new QLabel(label_materiale),12,0);
           layout->addWidget(materiale,12,1);
           QString label_peso("Peso");
           layout->addWidget(new QLabel(label_peso),13,0);
           layout->addWidget(peso,13,1);

           layout->addWidget(inserisci,14,0);
           setLayout(layout);
           this->show();


}

void Inserimento::Switch_tipo(QString qs){
    if(qs=="Bici da corsa"){
        specialita->setEnabled(true);
        materiale->setEnabled(true);
        peso->setEnabled(true);
        cestino->setEnabled(false);
        seggiolino->setEnabled(false);
        portapacchi->setEnabled(false);
        copricatena->setEnabled(false);
        fanale->setEnabled(false);
    }
    else if(qs=="Bici Comuni"){
        specialita->setEnabled(false);
        materiale->setEnabled(false);
        peso->setEnabled(false);
        cestino->setEnabled(true);
        seggiolino->setEnabled(true);
        portapacchi->setEnabled(true);
        copricatena->setEnabled(true);
        fanale->setEnabled(true);
    }
}


void Inserimento::Inserisci_nel_db(){
    string marca_ = marca->text().toStdString();
    string modello_ = modello->text().toStdString();
    float lunghezza_= static_cast<float>(lunghezza->value());
    float altezza_= static_cast<float>(altezza->value());
    double prezzo_= prezzo->value();

    //bici comuni
    bool cestino_=cestino->isChecked();
    bool seggiolino_= seggiolino->isChecked();
    bool portapacchi_ =portapacchi->isChecked();
    bool copricatena_ =copricatena->isChecked();
    bool fanale_ =fanale->isChecked();
    //bici da corsa
    string specialita_ = specialita->text().toStdString();
    string materiale_ = materiale->text().toStdString();
    double peso_= peso->value();

    string tipo_=tipo->currentText().toStdString();
    if(tipo_== "Bici da corsa"){
        BiciDaCorsa* aux=new BiciDaCorsa(marca_,modello_,lunghezza_,altezza_,prezzo_,specialita_,materiale_,peso_);
        negozio->inserisci_bicicletta(*aux);
    }else if(tipo_ == "Bici Comuni"){
        BiciComuni* aux=new BiciComuni(marca_,modello_,lunghezza_,altezza_,prezzo_,cestino_,seggiolino_,portapacchi_,copricatena_,fanale_);
        negozio->inserisci_bicicletta(*aux);
    }
    emit aggiunta_bici();


}
