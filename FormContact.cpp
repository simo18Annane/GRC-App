/**
 * @file FormContact.cpp
 * @class FormContact
 * @brief Classe FormContact
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include "FormContact.h"
#include "ui_FormContact.h"

#include "Contact.h"

FormContact::FormContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormContact)
{
    ui->setupUi(this);
}

FormContact::~FormContact()
{
    delete ui;
}

/**
 *@fn on_PhotoButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de parcourir le gestionnaire de fichiers afin de selectionner une image
 *@return rien
*/
void FormContact::on_PhotoButton_clicked()
{
    this -> path = QFileDialog::getOpenFileName(this, "Photo", "//home");
}

/**
 *@fn on_AnnulerButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de fermer le widget
 *@return rien
*/
void FormContact::on_AnnulerButton_clicked()
{
    this -> close();
}

/**
 *@fn on_EnregistrerButton_clicked()
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief permet l'enregistrement d'un contact dans la BD et la MAJ de la liste de contact
 *@return rien
*/
void FormContact::on_EnregistrerButton_clicked()
{
    Contact * c = new Contact();
    c -> setLastname((ui -> NomEdit -> text()).toStdString());
    c -> setFirstname((ui -> PrenomEdit -> text()).toStdString());
    c -> setCompany((ui -> EntrepriseEdit -> text()).toStdString());
    c -> setMail((ui -> MailEdit -> text()).toStdString());
    c -> setPhone((ui -> PhoneEdit -> text()).toStdString());
    c -> setPicture(this -> path.toStdString());
    c -> setDateOfCreation();
    emit enregistrerContact(c);
    emit updateList();
    this -> close();
}

