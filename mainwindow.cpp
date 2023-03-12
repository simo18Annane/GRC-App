/**
 * @file mainwindow.cpp
 * @class mainwindow
 * @brief Classe mainwindow
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/


#include <QDebug>

//Json
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bd = new basedonnee();//instanciation de la classe basedonnee qui permet d'ouvrir la base de donnée
    afficherList();//pour remplir la qlistWidget
    json();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 *@fn afficherList()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet le remplissage de qlistWidget
 *@return rien
*/
void MainWindow::afficherList() //pour remplir qlistWidget
{
    connect(this, SIGNAL(envNB()), bd, SLOT(recNB()));
    connect(bd, SIGNAL(NB(int)), this, SLOT(NBrec(int)));
    QSqlQuery query;
    query.prepare("SELECT * from Contact");
    query.exec();
    while(query.next())
    {
        //recuperer l'id, nom et prenom de chaque contact du tableau Contact de la base de donnée
        QString l=QString(query.value(0).toString()+"-"+query.value(1).toString()+" "+query.value(2).toString());
        ui -> listContact ->addItem(l);
    }
    emit envNB();
}

//quand on clique sur ajouter contact
/**
 *@fn on_actionAjouter_contact_triggered()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet l'ajout de contact a travers l'ouverture du qwidget definit
 *@return rien
*/
void MainWindow::on_actionAjouter_contact_triggered()
{
    fc = new FormContact();
    fc -> show();//ouverture du nouveau widget qui permet d'ajouter un contact
    connect(fc, SIGNAL(enregistrerContact(Contact *)), bd, SLOT(ajouterContact(Contact *)));
    connect(fc ,SIGNAL(updateList()), this, SLOT(updatelistContact()));//mise a jour de qlistWidget apres l'ajout d'un contact
}

/**
 *@fn on_listContact_doubleClicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet l'ouverture du qwidget responsable de l'affichage des donnees du contact
 *@return rien
*/
void MainWindow::on_listContact_doubleClicked() //quand on clique deux fois sur qlistWidget
{

    ac = new AfficheContact();
    ac -> show();//ouverture d'un nouveau widget qui permet d'afficher les données du contact selectionné
    connect(this, SIGNAL(select(string)), bd, SLOT(reception(string)));
    connect(bd, SIGNAL(envoyerContact(Contact *)), ac, SLOT(receiveContact(Contact *)));
    connect(ac, SIGNAL(envE(QString)), bd, SLOT(receiveEntreprise(QString)));
    connect(ac, SIGNAL(envM(QString)), bd, SLOT(receiveMail(QString)));
    connect(ac, SIGNAL(envP(QString)), bd, SLOT(receivePhone(QString)));
    connect(ac, SIGNAL(envSupp()), bd, SLOT(r2supp()));
    connect(ac, SIGNAL(envSupp()), this, SLOT(updatelistContact()));
    //recuperation de l'id du contact qui a été selectionné dans la qlistWidget
    string l=ui->listContact->currentItem()->text().toStdString();
    string nv="";
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }
    }
    emit select(nv);//envoyer l'id du contact selectionné via un signal à la classe basedonnee

}

/**
 *@fn on_AjouterInteractionButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet l'ouverture d'un nouveau widget qui va nous permettre d'ajouter une nouvelle interaction et des taches pour chaque interaction
 *@return rien
*/
void MainWindow::on_AjouterInteractionButton_clicked() //quand on clique sur le bouton ajouterIntercation
{
    fi = new FormInteraction();
    fi -> show();
    //recuperation de l'id du contact qui a été selectionné dans la qlistWidget
    string l=ui->listContact->currentItem()->text().toStdString();
    string nv="";
    connect(this, SIGNAL(selectC(string)), bd, SLOT(recID(string)));
    connect(fi, SIGNAL(envoyerInteraction(Interaction *)), bd, SLOT(recInteraction(Interaction *)));
    connect(fi, SIGNAL(envoyerTache(Tache *)), bd, SLOT(recTache(Tache *)));
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }
    }
    emit selectC(nv);//envoyer l'id du contact qui a été selectionné via un signal à la classe basedonnee
}

/**
 *@fn on_AfficheInteractionButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet l'ouverture d'un nouveau widget qui affiche les interactions
 *@return rien
*/
void MainWindow::on_AfficheInteractionButton_clicked() //quand on clique sur afficherInteraction
{
    connect(this, SIGNAL(selectC(string)), bd, SLOT(recIDCI(string)));
    connect(bd, SIGNAL(sendLI(list<Interaction *>, Contact *)), this, SLOT(recLI(list<Interaction *>, Contact *)));
    connect(bd, SIGNAL(messageLI(QString, Contact *)), this, SLOT(recMessageLI(QString, Contact *)));
    //recuperation de l'id du contact qui a été selectionné dans la qlistWidget
    string l=ui->listContact->currentItem()->text().toStdString();
    string nv="";
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }
    }
    emit selectC(nv);//envoyer l'id du contact qui a été selectionné dans la qlistWidget à la classe basedonnee

}

/**
 *@fn on_AfficheTaches_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet l'ouverture d'un nouveau widget qui affiche les taches
 *@return rien
*/
void MainWindow::on_AfficheTaches_clicked() //quand on clique sur le bouton afficheTaches
{
    connect(this, SIGNAL(selectC(string)), bd, SLOT(recIDCIT(string)));
    connect(bd, SIGNAL(sendLCIT(map<Interaction *, list<Tache *>>, Contact *)), this, SLOT(recLCIT(map<Interaction *, list<Tache *>>, Contact *)));
    connect(bd, SIGNAL(messageLITI(QString, Contact *)), this, SLOT(recMessageLITI(QString, Contact *)));
    //recuperation de l'id du contact selectionné
    string l=ui->listContact->currentItem()->text().toStdString();
    string nv="";
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }
    }
    emit selectC(nv);

}

/**
 *@fn on_actionRecherche_triggered()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet l'ouverture d'un nouveau widget qui permet la recherche de contacts
 *@return rien
*/
void MainWindow::on_actionRecherche_triggered() //quand on clique sur recherche
{
    rc = new RechercheContact();
    rc -> show();//ouverture du nouveau widget qui va nous permettre de rechercher un contact
    connect(rc, SIGNAL(envN(QString)), bd, SLOT(recN(QString)));
    connect(rc, SIGNAL(envE(QString)), bd, SLOT(recE(QString)));
    connect(rc, SIGNAL(envD(QString)), bd, SLOT(recD(QString)));
    connect(bd, SIGNAL(envoyerContact(Contact *)), rc, SLOT(receptionC(Contact *)));
    connect(bd, SIGNAL(message(QString)), rc, SLOT(recMessage(QString)));
    connect(bd, SIGNAL(sendLC(list<Contact *>)), rc, SLOT(recLC(list<Contact *>)));
}

/**
 *@fn updatelistContact()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet la MAJ de qlistWidget
 *@return rien
*/
void MainWindow::updatelistContact() //update qlistWidget
{
    connect(this, SIGNAL(envNB()), bd, SLOT(recNB()));
    connect(bd, SIGNAL(NB(int)), this, SLOT(NBrec(int)));
    ui->listContact->clear();
    afficherList();
    json();
    emit envNB();

}

/**
 *@fn recLI(list<Interaction *> li, Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher les interactions de chaque contact
 *@return rien
*/
void MainWindow::recLI(list<Interaction *> li, Contact *c) //pour afficher les interactions de chaque contact
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getLastname()+" "+c->getFirstname()));
    for(auto &i : li)
    {
        ui->textEdit->append(QString::fromStdString(i->getContent()+" "+i->getDI()));
    }
}

/**
 *@fn recMessageLI(QString m, Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher un message au cas ou aucune interaction existe pour le contact
 *@return rien
*/
void MainWindow::recMessageLI(QString m, Contact *c) //message a afficher au cas ou aucune interaction existe pour le contact
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getLastname()+" "+c->getFirstname()));
    ui->textEdit->append(m);
}

/**
 *@fn recLCIT(map<Interaction *, list<Tache *>> it, Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher les taches de chaque interaction et les interactions de chaque contact
 *@return rien
*/
void MainWindow::recLCIT(map<Interaction *, list<Tache *>> it, Contact *c) //pour afficher les taches de chaque interaction et les interactions de chaque contact
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getLastname()+" "+c->getFirstname()));
    for(auto &i : it)//recuperation du key du hash map
    {
        ui->textEdit->append(QString::fromStdString("Interaction: "+i.first->getContent()+" date: "+i.first->getDI()));
        ui->textEdit->append(QString::fromStdString("les taches:"));
        for(auto &l : i.second)//recuperation des valeurs du hashmap
        {
            ui->textEdit->append(QString::fromStdString(l->getAction()+" "+l->getDT()));
        }
        ui->textEdit->append("");
    }
}

/**
 *@fn recMessageLITI(QString m, Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher un message a afficher au cas ou aucune interaction existe pour le contact
 *@return rien
*/
void MainWindow::recMessageLITI(QString m, Contact *c) //message a afficher au cas ou aucune interaction existe pour le contact
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getLastname()+" "+c->getFirstname()));
    ui->textEdit->append(m);
}

/**
 *@fn on_showButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher
 *@return rien
*/
void MainWindow::on_showButton_clicked() //quand on clique sur le bouton showButton
{
    connect(this, SIGNAL(envoyer(QString, QString, string)), bd, SLOT(recdda(QString, QString, string)));
    connect(bd, SIGNAL(sendLIDA(map<Interaction *, list<Tache *>>, Contact *)), this, SLOT(recLIDA(map<Interaction *, list<Tache *>>, Contact *)));
    connect(bd, SIGNAL(messageLIDA(QString, Contact*)), this, SLOT(recMessageLIDA(QString, Contact *)));
    //recuperation de l'id du contact qui a été selectionne dans qlistWidget
    string l=ui->listContact->currentItem()->text().toStdString();
    string nv="";
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }
    }
    QString dateDu=ui->dateDu->text();
    QString dateAu=ui->dateAu->text();
    emit envoyer(dateDu,dateAu,nv);
}

/**
 *@fn recLIDA(map<Interaction *, list<Tache *>> it, Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher les taches de chaque interaction et les interaction de chaque contact entre deux dates données
 *@return rien
*/
void MainWindow::recLIDA(map<Interaction *, list<Tache *>> it, Contact *c) //afficher les taches de chaque interaction et les interaction de chaque contact entre deux dates données
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getLastname()+" "+c->getFirstname()));
    for(auto &i : it)//recuperation du key du hash map
    {
        ui->textEdit->append(QString::fromStdString("Interaction: "+i.first->getContent()+" date: "+i.first->getDI()));
        ui->textEdit->append(QString::fromStdString("les taches:"));
        for(auto &l : i.second)//recuperation des valeurs du hashmap
        {
            ui->textEdit->append(QString::fromStdString(l->getAction()+" "+l->getDT()));
        }
        ui->textEdit->append("");
    }
}

/**
 *@fn recMessageLIDA(QString m, Contact *c)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'afficher un message au cas ou aucune interaction existe pour le contact
 *@return rien
*/
void MainWindow::recMessageLIDA(QString m, Contact *c) //message a afficher au cas ou aucune interaction existe pour le contact
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getLastname()+" "+c->getFirstname()));
    ui->textEdit->append(m);
}

/**
 *@fn json()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de remplir le fichier JSON
 *@return rien
*/
void MainWindow::json() //json
{
    QJsonDocument document;
    document.setArray(bd->remplirJson());
    QFile fichier("//home/simo/Documents/era/Projet_CDAA/text.json");
    fichier.open(QFile::WriteOnly);
    fichier.write(document.toJson());
}

void MainWindow::NBrec(int nb){
    ui->nbC->clear();
    ui->nbC->setText(QString::number(nb));
}
