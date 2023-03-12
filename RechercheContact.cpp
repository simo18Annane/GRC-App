/**
 * @file RechercheContact.cpp
 * @class RechercheContact
 * @brief Classe RechercheContact
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include "RechercheContact.h"
#include "ui_RechercheContact.h"

RechercheContact::RechercheContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RechercheContact)
{
    ui->setupUi(this);
    on_checkNE_clicked();
}

RechercheContact::~RechercheContact()
{
    delete ui;
}

/**
 *@fn on_searchButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de faire la recherche suivant l'option choisit
 *@return rien
*/
void RechercheContact::on_searchButton_clicked()
{
    QString info=ui->infoC->text();
    string crit=ui->critereC->currentText().toStdString();
    ui->resultat->setText(" ");
    //qDebug() << info;
    //qDebug() << crit;
    if(crit=="Nom")
    {
        emit envN(info);
    }
    if(crit=="Entreprise")
    {
        emit envE(info);
    }
}

/**
 *@fn receptionC(Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher le contact recherche
 *@return rien
*/
void RechercheContact::receptionC(Contact *c)
{
    ui->resultat->setText(QString::fromStdString("Nom: "+c->getLastname()));
    ui->resultat->append(QString::fromStdString("Prenom: "+c->getFirstname()));
    ui->resultat->append(QString::fromStdString("Entreprise: "+c->getCompany()));
    ui->resultat->append(QString::fromStdString("Mail: "+c->getMail()));
    ui->resultat->append(QString::fromStdString("Telephone: "+c->getPhone()));
    ui->resultat->append(QString::fromStdString("Date de creation: "+c->getDC()));
}

/**
 *@fn recMessage(QString m)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher un message quand le contact n'est pas trouve
 *@return rien
*/
void RechercheContact::recMessage(QString m)
{
    ui->resultat->setText(m);
}

/**
 *@fn on_checkNE_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de rendre les options pour la recherche Nom/entreprise accessibles, et rend les autres options inaccessibles
 *@return rien
*/
void RechercheContact::on_checkNE_clicked()
{
    ui->sdcButton->setEnabled(false);
    ui->checkD->setChecked(false);
    ui->searchButton->setEnabled(true);
    ui->checkNE->setChecked(true);
}

/**
 *@fn on_checkD_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de rendre les options pour la recherche par date accessibles, et rend les autres options inaccessibles
 *@return rien
*/
void RechercheContact::on_checkD_clicked()
{
    ui->sdcButton->setEnabled(true);
    ui->checkNE->setChecked(false);
    ui->searchButton->setEnabled(false);
    ui->checkD->setChecked(true);
}

/**
 *@fn on_sdcButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de
 *@return rien
*/
void RechercheContact::on_sdcButton_clicked()
{
    ui->resultat->setText(" ");
    QString date=ui->dateCEdit->text();
    string l=date.toStdString();
    string nl="";
    if(l[0]=='0')
    {
        for(__SIZE_TYPE__ i=1;i<l.size();i++)
        {
            nl+=l[i];
        }
        date=QString::fromStdString(nl);
    }
    emit envD(date);
}

/**
 *@fn recLC(list<Contact *> lc)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher le/s contact/s recherche depuis la liste des contacts
 *@return rien
*/
void RechercheContact::recLC(list<Contact *> lc)
{
    for(auto &c : lc)
    {
        ui->resultat->append(QString::fromStdString("Nom: "+c->getLastname()));
        ui->resultat->append(QString::fromStdString("Prenom: "+c->getFirstname()));
        ui->resultat->append(QString::fromStdString("Entreprise: "+c->getCompany()));
        ui->resultat->append(QString::fromStdString("Mail: "+c->getMail()));
        ui->resultat->append(QString::fromStdString("Telephone: "+c->getPhone()));
        ui->resultat->append(QString::fromStdString("Date de creation: "+c->getDC()));
        ui->resultat->append(" ");
    }
}
