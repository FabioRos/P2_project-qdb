#ifndef RICERCA_H
#define RICERCA_H

#include <QtGui>
#include "negozio.h"
#include "record.h"
#include <string>

class Ricerca : public QWidget
{
    Q_OBJECT
    Negozio* db;
    Container<record*> rec;
    QComboBox* tipo;
    QLineEdit* testo;  //cerco tra marca e modello
    QPushButton* invia;
    QTableWidget* tb;
    void genera_tabella();
public:
    explicit Ricerca(Negozio* n, QWidget *parent = 0);

signals:

public slots:
    void Switch_tipo_ricerca(QString nuovo_tipo);
    void esegui_ricerca(QString);
};

#endif // RICERCA_H
