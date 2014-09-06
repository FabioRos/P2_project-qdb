#ifndef RICERCA_H
#define RICERCA_H

#include <QtGui>
#include "negozio.h"

class Ricerca : public QWidget
{
    Q_OBJECT
    Negozio* db;

     QComboBox* tipo;
     QLineEdit* testo;  //cerco tra marca e modello
     QPushButton* invia;
public:
    explicit Ricerca(Negozio* n, QWidget *parent = 0);

signals:

public slots:

};

#endif // RICERCA_H
