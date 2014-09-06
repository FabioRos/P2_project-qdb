#ifndef RECORD_H
#define RECORD_H

#include <QtGui>


#include "bicicletta.h"
#include "bicicomuni.h"
#include "bicidacorsa.h"
#include "container.h"
#include "negozio.h"
/**
 * @brief Classe che gestisce i record in comune a tutte le bici
 */
class record: public QObject    //per poter usare i connect
{
private:
    Q_OBJECT
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
    QPushButton* elimina;

    int n_riga;
    Bicicletta* ptrQuestaBici;
    Negozio* shop;
private slots:  //solo ad uso di questa classe
    //QLineEdit
    void marca_changed ( QString);
    void modello_changed ( QString);
    void specialita_changed ( QString);
    void materiale_changed ( QString);
    //QDoubleSpinBox
    void lunghezza_changed(double d );
    void altezza_changed(double d );
    void prezzo_changed(double d );
    void peso_changed(double d );
    //QCheckBox -> stateChanged(int)
    void cestino_changed(int d );
    void seggiolino_changed(int d );
    void portapacchi_changed(int d );
    void copricatena_changed(int d );
    void fanale_changed(int d );
    void eliminariga();
signals:
    void eliminariga(record*);

public:
    record(Bicicletta* /*,int*/);
    ~record();
    QWidget* WidgetMarca()const;
    QWidget* WidgetModello()const;
    QWidget* WidgetLunghezza()const;
    QWidget* WidgetAltezza()const;
    QWidget* WidgetQuantita()const;
    QWidget* WidgetPrezzo()const;
    QWidget* WidgetCestino()const;
    QWidget* WidgetSeggiolino()const;
    QWidget* WidgetPortapacchi()const;
    QWidget* WidgetCopricatena()const;
    QWidget* WidgetFanale()const;
    QWidget* WidgetSpecialita()const;
    QWidget* WidgetMateriale()const;
    QWidget* WidgetPeso()const;
    QWidget* WidgetElimina();
};




#endif // RECORD_H
