#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "FormContact.h"
#include "AfficheContact.h"
#include "FormInteraction.h"
#include "RechercheContact.h"
#include "basedonnee.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    FormContact * fc;
    AfficheContact * ac;
    FormInteraction * fi;
    RechercheContact * rc;
    basedonnee  *bd;
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void afficherList();//pour remplir la qlistWidget
    //json
    void json();


signals:
    void select(string);//pour envoyer l'id du contact qui a été selectionné dans qlistWidget à la classe basedonnee
    void selectC(string);//pour envoyer l'id du contact qui a été selectionné dans qlistWidget à la classe basedonnee
    void envoyer(QString, QString, string);//envoyer la premiere date et la deuxieme date et l'id du contact selectionné à la classe basedonne
    void envNB();

private slots:
    void on_actionAjouter_contact_triggered();//pour ajouter un contact

    void on_listContact_doubleClicked();//quand on clique deux fois sur un element dans la qlistWidget

    void on_AjouterInteractionButton_clicked();//pour ajouter une interaction

    void on_AfficheInteractionButton_clicked();//pour afficher une interaction

    void on_AfficheTaches_clicked();//pour afficher les taches de chaque contact

    void on_actionRecherche_triggered();//pour rechercher un contact


    void on_showButton_clicked();//pour chercher un contact entre deux dates

public slots:
    void updatelistContact();//pour mettre a jour la qlistWidget
    void recLI(list<Interaction *>, Contact *);//pour afficher les interactions de chaque contact
    void recMessageLI(QString, Contact *);//message a afficher au cas ou aucune interaction existe  pour le contact
    void recLCIT(map<Interaction *, list<Tache *>>, Contact *);//pour afficher les taches de chaque interaction et les interactions de chaque contact
    void recMessageLITI(QString, Contact *);//message a afficher au cas ou aucune interaction existe pour le contact
    void recLIDA(map<Interaction *, list<Tache *>>, Contact *);//afficher les taches de chaque interaction et les interaction de chaque contact entre deux dates données
    void recMessageLIDA(QString, Contact *);//message a afficher au cas ou aucune interaction existe pour le contact
    void NBrec(int);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
