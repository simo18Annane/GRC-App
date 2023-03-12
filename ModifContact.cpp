/**
 * @file ModifContact.cpp
 * @class ModifContact
 * @brief Classe ModifContact
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include "ModifContact.h"
#include "ui_ModifContact.h"

ModifContact::ModifContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifContact)
{
    ui->setupUi(this);
}

ModifContact::~ModifContact()
{
    delete ui;
}

/**
 *@fn getContact(Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher les données du contact avant de les modifier
 *@return rien
*/
void ModifContact::getContact(Contact *c) //pour afficher les données du contact avant de les modifier
{
    ui->NomEdit_2->setText(QString::fromStdString(c->getLastname()));
    ui->PrenomEdit_2->setText(QString::fromStdString(c->getFirstname()));
    ui->EntrepriseEdit_2->setText(QString::fromStdString(c->getCompany()));
    ui->MailEdit_2->setText(QString::fromStdString(c->getMail()));
    ui->PhoneEdit_2->setText(QString::fromStdString(c->getPhone()));
}

/**
 *@fn on_EnregistrerButton_2_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'enregistrer les modifications
 *@return rien
*/
void ModifContact::on_EnregistrerButton_2_clicked() //quand on clique sur le bouton enregistrer
{
    bool entreprise = ui->EntrepriseEdit_2->text().isEmpty();
    bool mail = ui->MailEdit_2->text().isEmpty();
    bool phone = ui->PhoneEdit_2->text().isEmpty();

    if(!entreprise)
    {
        emit sendEntreprise(ui->EntrepriseEdit_2->text());
    }
    if(!mail)
    {
        emit sendMail(ui->MailEdit_2->text());
    }
    if(!phone)
    {
        emit sendPhone(ui->PhoneEdit_2->text());
    }
    this->close();

}

/**
 *@fn on_AnnulerButton_2_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de fermer le qwidget
 *@return rien
*/
void ModifContact::on_AnnulerButton_2_clicked() //quand on clique sur le bouton annuler
{
    this->close();
}

/**
 *@fn on_AnnulerButton_2_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de supprimer le contact et fermer le qwidget
 *@return rien
*/
void ModifContact::on_SupprimerButton_clicked() //quand on clique sur le bouton supprimer
{
    emit supp();
    this->close();
}
