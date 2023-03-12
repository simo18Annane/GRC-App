/**
 * @file AfficheContact.cpp
 * @class AfficheContact
 * @brief Classe AfficheContact
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include "AfficheContact.h"
#include "ui_AfficheContact.h"

AfficheContact::AfficheContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficheContact)
{
    ui->setupUi(this);

}

AfficheContact::~AfficheContact()
{
    delete ui;
}

/**
 *@fn on_SortirButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief fermeture du widget
 *@return rien
*/
void AfficheContact::on_SortirButton_clicked()
{
    this -> close();
}

/**
 *@fn on_ModifierButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief Instancie la classe ModifContact et a travers un mc -> show() on ouvre le widget correspondant pour la modification d'un contact
 *A travers un signal on envoye le contact selectionné pour la modification au widget qui permet de modifier un contact
 *@return rien
*/
void AfficheContact::on_ModifierButton_clicked() //quand on clique sur le bouton modifier
{
    mc = new ModifContact();
    mc -> show();//ouverture d'un nouveau widget qui permet de modifier un contact
    connect(this, SIGNAL(sendmodifContact(Contact *)), mc, SLOT(getContact(Contact *)));
    connect(mc, SIGNAL(sendEntreprise(QString)), this, SLOT(recE(QString)));
    connect(mc, SIGNAL(sendMail(QString)), this, SLOT(recM(QString)));
    connect(mc, SIGNAL(sendPhone(QString)), this, SLOT(recP(QString)));
    connect(mc, SIGNAL(supp()), this, SLOT(rsupp()));
    emit sendmodifContact(nc);//envoyer le contact selectionné pour la modification au widget qui permet de modifier un contact
}

/**
 *@fn receiveContact(Contact *c)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief fonction qui permet d'afficher les données d'un contact ainsi que sont image
 *@return rien
*/
void AfficheContact::receiveContact(Contact *c) //pour afficher les données d'un contact
{
    ui->lineNom->setText(QString::fromStdString(c->getLastname()));
    ui->linePrenom->setText(QString::fromStdString(c->getFirstname()));
    ui->lineEntreprise->setText(QString::fromStdString(c->getCompany()));
    ui->lineMail->setText(QString::fromStdString(c->getMail()));
    ui->linePhone->setText(QString::fromStdString(c->getPhone()));
    ui->lineDC->setText(QString::fromStdString(c->getDC()));
    ui->lineDE->setText(QString::fromStdString(c->getDE()));
    //pour afficher l'image d'un contact
    string img=c->getPicture();
    QPixmap pixmap(img.c_str());
    QIcon ButtonIcon(pixmap);
    ui->Photo->setIcon(ButtonIcon);
    ui->Photo->setIconSize(pixmap.rect().size());
    nc=c;

}

//pour la modification du champ entreprise et mail et telephone depuis la classe basedonnee
/**
 *@fn recE(QString ct)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief fonction qui permet d'emettre un signal pour la modification du champ entreprise depuis la classe basedonnee
 *@return rien
*/
void AfficheContact::recE(QString ct)
{
    emit envE(ct);
}

/**
 *@fn recM(QString ct)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief fonction qui permet d'emettre un signal pour la modification du champ mail depuis la classe basedonnee
 *@return rien
*/
void AfficheContact::recM(QString ct)
{
    emit envM(ct);
}

/**
 *@fn recP(QString ct)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief fonction qui permet d'emettre un signal pour la modification du champ phone depuis la classe basedonnee
 *@return rien
*/
void AfficheContact::recP(QString ct)
{
    emit envP(ct);
}

/**
 *@fn rsupp()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief fonction qui permet d'emettre un signal qui supprimer un contact depuis la classe basedonnee
 *@return rien
*/
void AfficheContact::rsupp() //pour supprimer un contact depuis la classe basedonnee
{
    emit envSupp();
    this->close();
}



