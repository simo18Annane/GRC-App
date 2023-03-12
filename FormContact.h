#ifndef FORMCONTACT_H
#define FORMCONTACT_H

#include <QWidget>
#include <QFileDialog>

#include "Contact.h"

namespace Ui {
class FormContact;
}

class FormContact : public QWidget
{
    QString path;
    Q_OBJECT

public:

    explicit FormContact(QWidget *parent = nullptr);
    ~FormContact();

signals:
    void enregistrerContact(Contact *);
    void updateList();

private slots:

    void on_PhotoButton_clicked();

    void on_AnnulerButton_clicked();

    void on_EnregistrerButton_clicked();

private:
    Ui::FormContact *ui;
};

#endif // FORMCONTACT_H
