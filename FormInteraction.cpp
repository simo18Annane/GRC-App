/**
 * @file FormInteraction.cpp
 * @class FormInteraction
 * @brief Classe FormInteraction
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include "FormInteraction.h"
#include "ui_FormInteraction.h"

FormInteraction::FormInteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInteraction)
{
    ui->setupUi(this);
    ui->AjoutButton->setEnabled(false);
}

FormInteraction::~FormInteraction()
{
    delete ui;
}

/**
 *@fn on_AnnulerButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de fermer le widget
 *@return rien
*/
void FormInteraction::on_AnnulerButton_clicked()
{
    this -> close();
}

/**
 *@fn on_saveIButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'enregistrer l'interaction
 *@return rien
*/
void FormInteraction::on_saveIButton_clicked()
{
    I=new Interaction();
    I->setContent(ui->titreEdit->text().toStdString());
    emit envoyerInteraction(I);
    ui->saveIButton->setEnabled(false);
    ui->AjoutButton->setEnabled(true);
    ui->m1Label->setText("Interaction ajouter avec succes");

}

/**
 *@fn on_AjoutButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet d'ajouter l'interaction
 *@return rien
*/
void FormInteraction::on_AjoutButton_clicked()
{
    QString tache=ui->contenu->toPlainText();
    string sx=tache.toStdString();
    string todo;
    string date;
    bool verifd=false;
    __SIZE_TYPE__ i=0; int nb=0;
    while(nb<3 && i<sx.size())
    {
        if(sx[i]=='@')
        {
            nb++;
            i=i+5;
        }
        else
        {
            if(nb==1)
            {
                todo+=sx[i];
            }
            if(nb==2)
            {
                date+=sx[i];
                verifd=true;
            }
        }
        i++;
    }
    if(verifd)
    {
        T=new Tache(todo,date);
    }
    else
    {
        T=new Tache(todo,I->getDI());
    }
    emit envoyerTache(T);
    ui->contenu->clear();
    ui->m2Label->setText("Tache ajouter avec succes");
}

/**
 *@fn on_newIButton_clicked()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet de reinitialiser les champs d'ecriture dans le widget
 *@return rien
*/
void FormInteraction::on_newIButton_clicked()
{
    ui->AjoutButton->setEnabled(false);
    ui->saveIButton->setEnabled(true);
    ui->titreEdit->clear();
    ui->m1Label->clear();
    ui->m2Label->clear();
}
