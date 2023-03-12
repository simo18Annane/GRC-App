#ifndef MODIFCONTACT_H
#define MODIFCONTACT_H

#include <QWidget>
#include <QDebug>

#include "Contact.h"

namespace Ui {
class ModifContact;
}

class ModifContact : public QWidget
{
    Q_OBJECT


public:
    explicit ModifContact(QWidget *parent = nullptr);
    ~ModifContact();

private:
    Ui::ModifContact *ui;

signals:
    void sendEntreprise(QString);//pour modifier entreprise
    void sendMail(QString);//pour modifier mail
    void sendPhone(QString);//pour modifier le telephone
    void supp();//pour supprimer Contact

public slots:
    void getContact(Contact *);//pour afficher les données du contact avant de les modifier

private slots:
    void on_EnregistrerButton_2_clicked();
    void on_AnnulerButton_2_clicked();
    void on_SupprimerButton_clicked();
};

#endif // MODIFCONTACT_H
