#ifndef INSERIMENTO_H
#define INSERIMENTO_H

#include <QWidget>
#include <QtGui>
#include "negozio.h"
#include "bicicomuni.h"
#include "bicidacorsa.h"

class Inserimento : public QWidget
{
    Q_OBJECT
    QComboBox* tipo;
    QLineEdit* marca;
    QLineEdit* modello;
    QDoubleSpinBox* lunghezza;
    QDoubleSpinBox* altezza;
    QDoubleSpinBox* prezzo;
    //Campi di Bici Comuni
    QCheckBox* cestino, *seggiolino, *portapacchi, *copricatena, *fanale;
    //Campi di Bici da corsa
    QLineEdit* specialita;
    QLineEdit* materiale;
    QDoubleSpinBox* peso;
    QPushButton* inserisci;

    Negozio* negozio;

public:
    explicit Inserimento(Negozio *n,QWidget *parent = 0);

signals:
    void aggiunta_bici();
public slots:
     void Switch_tipo(QString);
     void Inserisci_nel_db();

};

#endif // INSERIMENTO_H
