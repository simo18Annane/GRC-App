#ifndef RECHERCHECONTACT_H
#define RECHERCHECONTACT_H

#include <QWidget>
#include <QDebug>
#include <QString>

#include "Contact.h"

namespace Ui {
class RechercheContact;
}

class RechercheContact : public QWidget
{
    Q_OBJECT

public:
    explicit RechercheContact(QWidget *parent = nullptr);
    ~RechercheContact();

signals:
    void envN(QString);
    void envE(QString);
    void envD(QString);


public slots:
    void receptionC(Contact *);
    void recMessage(QString);
    void recLC(list<Contact *>);

private slots:
    void on_searchButton_clicked();

    void on_checkNE_clicked();

    void on_checkD_clicked();

    void on_sdcButton_clicked();

private:
    Ui::RechercheContact *ui;
};

#endif // RECHERCHECONTACT_H
