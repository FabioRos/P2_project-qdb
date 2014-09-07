#include "record.h"

record::record(Bicicletta* b, int riga_corrente=0):ptrQuestaBici(b),n_riga(riga_corrente){
    if(!b) throw errore();
    marca=new QLineEdit(QString::fromStdString(b->getMarca()));
    //ora connetto il segnale "textChanged(QString)" di 'marca' con il mio SLOT "marca_changed(Qstring)"
    connect(marca,SIGNAL(textChanged(QString)),this,SLOT(marca_changed(QString)));
    modello=new QLineEdit(QString::fromStdString(b->getModello()));
    connect(modello,SIGNAL(textChanged(QString)),this,SLOT(modello_changed(QString)));
    lunghezza=new QDoubleSpinBox();
    lunghezza->setValue(b->getLunghezza());
    connect(lunghezza,SIGNAL(valueChanged(double)),this,SLOT(lunghezza_changed(double)));
    altezza=new QDoubleSpinBox();
    altezza->setValue(b->getAltezza());
    connect(altezza,SIGNAL(valueChanged(double)),this,SLOT(altezza_changed(double)));
    prezzo=new QDoubleSpinBox();
    prezzo->setMaximum(99999);
    prezzo->setValue(b->getPrezzo());
    connect(prezzo,SIGNAL(valueChanged(double)),this,SLOT(prezzo_changed(double)));
    //Campi di Bici Comuni
    cestino=new QCheckBox();
    connect(cestino,SIGNAL(stateChanged(int)),this,SLOT(cestino_changed(int)));
    seggiolino=new QCheckBox();
    connect(seggiolino,SIGNAL(stateChanged(int)),this,SLOT(seggiolino_changed(int)));
    portapacchi=new QCheckBox();
    connect(portapacchi,SIGNAL(stateChanged(int)),this,SLOT(portapacchi_changed(int)));
    copricatena=new QCheckBox();
    connect(copricatena,SIGNAL(stateChanged(int)),this,SLOT(copricatena_changed(int)));
    fanale=new QCheckBox();
    connect(fanale,SIGNAL(stateChanged(int)),this,SLOT(fanale_changed(int)));
    //Campi di Bici da Corsa
    specialita=new QLineEdit();
     connect(specialita,SIGNAL(textChanged(QString)),this,SLOT(specialita_changed(QString)));
    materiale=new QLineEdit();
     connect(materiale,SIGNAL(textChanged(QString)),this,SLOT(materiale_changed(QString)));
    peso=new QDoubleSpinBox();
    BiciComuni* bcom=dynamic_cast<BiciComuni*>(ptrQuestaBici);
    BiciDaCorsa* brun=dynamic_cast<BiciDaCorsa*>(ptrQuestaBici);
    if(bcom){
        specialita->setEnabled(false);
        materiale->setEnabled(false);
        peso->setEnabled(false);
        cestino->setChecked(bcom->getCestino());
        seggiolino->setChecked(bcom->getSeggiolino());
        portapacchi->setChecked(bcom->getPortapacchi());
        copricatena->setChecked(bcom->getCopricatena());
        fanale->setChecked(bcom->getFanale());
    }
    if(brun){
        specialita->setText(QString::fromStdString(brun->getSpecialita()));
        materiale->setText(QString::fromStdString(brun->getMateriale()));
        peso->setValue(brun->getPeso());
        cestino->setEnabled(false);
        seggiolino->setEnabled(false);
        portapacchi->setEnabled(false);
        copricatena->setEnabled(false);
        fanale->setEnabled(false);
    }
}

record::~record(){
    delete marca;
    delete modello;
    delete lunghezza;
    delete altezza;
    delete prezzo;
    delete cestino;
    delete seggiolino;
    delete portapacchi;
    delete copricatena;
    delete fanale;
    delete specialita;
    delete materiale;
    delete peso;
}

//definizione slots
void record::marca_changed ( QString txt){
    ptrQuestaBici->setMarca(txt.toStdString());
}

void record::modello_changed ( QString txt){
    ptrQuestaBici->setModello(txt.toStdString());
}

void record::specialita_changed ( QString txt){
   BiciDaCorsa* p=dynamic_cast<BiciDaCorsa*>(ptrQuestaBici);
   if (p)
    p->setSpecialita(txt.toStdString());
}
void record::materiale_changed ( QString txt){
    BiciDaCorsa* p=dynamic_cast<BiciDaCorsa*>(ptrQuestaBici);
       if (p)
        p->setMateriale(txt.toStdString());
}

void record::lunghezza_changed(double d ){
    ptrQuestaBici->setLunghezza(d);
}
void record::altezza_changed(double d ){
    ptrQuestaBici->setAltezza(d);
}
void record::prezzo_changed(double d ){
    ptrQuestaBici->setPrezzo(d);
}
void record::peso_changed(double d ){
    BiciDaCorsa* p=dynamic_cast<BiciDaCorsa*>(ptrQuestaBici);
       if (p)
        p->setPeso(d);
}

void record::cestino_changed(int d ){
    BiciComuni* p=dynamic_cast<BiciComuni*>(ptrQuestaBici);
       if (p)
        p->setCestino(d);
}
void record::seggiolino_changed(int d ){
    BiciComuni* p=dynamic_cast<BiciComuni*>(ptrQuestaBici);
       if (p)
        p->setSeggiolino(d);
}
void record::portapacchi_changed(int d ){
    BiciComuni* p=dynamic_cast<BiciComuni*>(ptrQuestaBici);
       if (p)
        p->setPortapacchi(d);
}
void record::copricatena_changed(int d ){
    BiciComuni* p=dynamic_cast<BiciComuni*>(ptrQuestaBici);
       if (p)
        p->setCopricatena(d);
}
void record::fanale_changed(int d ){
    BiciComuni* p=dynamic_cast<BiciComuni*>(ptrQuestaBici);
       if (p)
        p->setFanale(d);
}

/*Definizione Widgets*/

QWidget *record::WidgetMarca() const{
    return marca;
}
QWidget *record::WidgetModello() const{
    return modello;
}
QWidget *record::WidgetLunghezza() const{
    return lunghezza;
}
QWidget *record::WidgetAltezza() const{
    return altezza;
}
QWidget *record::WidgetPrezzo() const{
    return prezzo;
}
QWidget *record::WidgetCestino() const{
    return cestino;
}
QWidget *record::WidgetSeggiolino() const{
    return seggiolino;
}
QWidget *record::WidgetPortapacchi() const{
    return portapacchi;
}
QWidget *record::WidgetCopricatena() const{
    return copricatena;
}
QWidget *record::WidgetFanale() const{
    return fanale;
}
QWidget *record::WidgetSpecialita() const{
    return specialita;
}
QWidget *record::WidgetMateriale() const{
    return materiale;
}
QWidget *record::WidgetPeso() const{
    return peso;
}

int record::get_n_riga() const{
    return n_riga;
}

