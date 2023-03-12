#ifndef AFFICHECONTACT_H
#define AFFICHECONTACT_H

#include <QWidget>

#include "Contact.h"
#include "ModifContact.h"

namespace Ui {
class AfficheContact;
}

class AfficheContact : public QWidget
{
    Q_OBJECT

    ModifContact * mc;

    Contact * nc;




public:
    explicit AfficheContact(QWidget *parent = nullptr);
    ~AfficheContact();

signals:
    void sendmodifContact(Contact *);
    void envE(QString);
    void envM(QString);
    void envP(QString);
    void envSupp();

public slots:
    void receiveContact(Contact *);
    void recE(QString);
    void recM(QString);
    void recP(QString);
    void rsupp();

private slots:
    void on_SortirButton_clicked();

    void on_ModifierButton_clicked();

private:
    Ui::AfficheContact *ui;
};

#endif // AFFICHECONTACT_H
