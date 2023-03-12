/**
 * @file basedonnee.cpp
 * @class basedonnee
 * @brief Classe basedonnee
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include "basedonnee.h"



basedonnee::basedonnee(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("//home/simo/Documents/era/Projet_CDAA/projet.sqlite");
    db.open();

}

basedonnee::~basedonnee()
{
    db.close();
}

/**
 *@fn ajouterContact(Contact *c)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief pour ajouter un nouveau contact dans la bd
 *@return rien
*/
void basedonnee::ajouterContact(Contact *c) //pour ajouter un nouveau contact dans la bd
{
    QSqlQuery query;
    query.prepare("INSERT INTO Contact (nom, prenom, entreprise, mail, telephone, photo, dateC, dateM) VALUES ( :n, :p, :e, :m, :t, :ph, :dc, :dm)");
    query.bindValue(":n", QString::fromStdString(c->getLastname()));
    query.bindValue(":p", QString::fromStdString(c->getFirstname()));
    query.bindValue(":e", QString::fromStdString(c->getCompany()));
    query.bindValue(":m", QString::fromStdString(c->getMail()));
    query.bindValue(":t", QString::fromStdString(c->getPhone()));
    query.bindValue(":ph", QString::fromStdString(c->getPicture()));
    query.bindValue(":dc", QString::fromStdString(c->toStringDC()));
    query.bindValue(":dm", QString::fromStdString(c->toStringDE()));
    query.exec();
}

/**
 *@fn reception(string i)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief reception
 *@return rien
*/
void basedonnee::reception(string i)
{
    idC=i;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("SELECT * from Contact WHERE idContact="+s+";");
    query.exec();
    while(query.next())
    {
        QString ln= QString(query.value(1).toString());
        QString fn= QString(query.value(2).toString());
        QString e= QString(query.value(3).toString());
        QString m= QString(query.value(4).toString());
        QString t= QString(query.value(5).toString());
        QString ph= QString(query.value(6).toString());
        QString dc= QString(query.value(7).toString());
        QString de= QString(query.value(8).toString());
        c= new Contact(ln.toStdString(), fn.toStdString(), e.toStdString(), m.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());

    }
    emit envoyerContact(c);
}

/*
void basedonnee::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET entreprise=:e WHERE idContact=2;");
    query.bindValue(":e", QString::fromStdString("bayern"));
    query.exec();
}
*/

/**
 *@fn receiveEntreprise(QString e)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief reception du champ entreprise
 *@return rien
*/
void basedonnee::receiveEntreprise(QString e)
{
    c=new Contact();
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("UPDATE Contact SET entreprise=:e, dateM=:mdf WHERE idContact="+s+";");
    query.bindValue(":e", e);
    query.bindValue(":mdf", QString::fromStdString(c->toStringDE()));
    query.exec();
    reception(idC);
}

/**
 *@fn receiveMail(QString m)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief reception du champ mail
 *@return rien
*/
void basedonnee::receiveMail(QString m)
{
    c=new Contact();
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("UPDATE Contact SET mail=:m, dateM=:mdf WHERE idContact="+s+";");
    query.bindValue(":m", m);
    query.bindValue(":mdf", QString::fromStdString(c->toStringDE()));
    query.exec();
    reception(idC);
}

/**
 *@fn receivePhone(QString p)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief reception du champ phone
 *@return rien
*/
void basedonnee::receivePhone(QString p)
{
    c=new Contact();
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("UPDATE Contact SET telephone=:p, dateM=:mdf WHERE idContact="+s+";");
    query.bindValue(":p", p);
    query.bindValue(":mdf", QString::fromStdString(c->toStringDE()));
    query.exec();
    reception(idC);
}

/**
 *@fn r2supp()
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief suppression
 *@return rien
*/
void basedonnee::r2supp()
{
    list<QString> idI;
    list<QString> idT;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;

    query.prepare(("DELETE FROM Contact WHERE idContact="+s+";"));
    query.exec();
    query.prepare(("DELETE FROM Interaction WHERE idContact="+s+";"));
    query.exec();
}

/**
 *@fn recN(QString nom)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet la recherche d'un contact par son nom dans la BD et le renvoyer avec un signal
 *@return rien
*/
void basedonnee::recN(QString nom)
{
    bool verif=false;
    QSqlQuery query;
    query.prepare("SELECT * from Contact WHERE nom='"+nom+"';");
    query.exec();
    while(query.next())
    {
        QString ln= QString(query.value(1).toString());
        QString fn= QString(query.value(2).toString());
        QString e= QString(query.value(3).toString());
        QString m= QString(query.value(4).toString());
        QString t= QString(query.value(5).toString());
        QString ph= QString(query.value(6).toString());
        QString dc= QString(query.value(7).toString());
        QString de= QString(query.value(8).toString());

        c= new Contact(ln.toStdString(), fn.toStdString(), e.toStdString(), m.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());
        verif=true;
    }
    if(verif)
    {
        emit envoyerContact(c);
    }
    else
    {
        emit message("Impossible de trouver le Contact");
    }
}

/**
 *@fn recE(QString ent)
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief permet la recherche d'un contact par son entreprise dans la BD et le renvoyer avec un signal
 *@return rien
*/
void basedonnee::recE(QString ent)
{
    bool verif=false;
    QSqlQuery query;
    query.prepare("SELECT * from Contact WHERE entreprise='"+ent+"';");
    query.exec();
    while(query.next())
    {
        QString ln= QString(query.value(1).toString());
        QString fn= QString(query.value(2).toString());
        QString e= QString(query.value(3).toString());
        QString m= QString(query.value(4).toString());
        QString t= QString(query.value(5).toString());
        QString ph= QString(query.value(6).toString());
        QString dc= QString(query.value(7).toString());
        QString de= QString(query.value(8).toString());
        c= new Contact(ln.toStdString(), fn.toStdString(), e.toStdString(), m.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());
        verif=true;
    }
    if(verif)
    {
        emit envoyerContact(c);
    }
    else
    {
        emit message("Impossible de trouver le Contact");
    }
}

/**
 *@fn recD(QString date)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief permet la recherche d'un contact par sa date dans la BD et le renvoyer avec un signal
 *@return rien
*/
void basedonnee::recD(QString date)
{
    bool verif=false;
    list<Contact *> lc;
    QSqlQuery query;
    query.prepare("SELECT * from Contact WHERE dateC='"+date+"';");
    query.exec();
    while(query.next())
    {
        QString ln= QString(query.value(1).toString());
        QString fn= QString(query.value(2).toString());
        QString e= QString(query.value(3).toString());
        QString m= QString(query.value(4).toString());
        QString t= QString(query.value(5).toString());
        QString ph= QString(query.value(6).toString());
        QString dc= QString(query.value(7).toString());
        QString de= QString(query.value(8).toString());
        c= new Contact(ln.toStdString(), fn.toStdString(), e.toStdString(), m.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());
        lc.push_back(c);
        verif=true;
    }
    if(verif)
    {
        emit sendLC(lc);
    }
    else
    {
        emit message("aucun contact n'a été cré dans cette date");
    }
}

/**
 *@fn recID(string i)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief permet la recherche d'un contact par son ID dans la BD
 *@return rien
*/
void basedonnee::recID(string i)
{
    idC=i;
}

/**
 *@fn recInteraction(Interaction *I)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief ajouter une interaction a la base de donnée
 *@return rien
*/
void basedonnee::recInteraction(Interaction *I) //ajouter une interaction a la base de donnée
{
    QSqlQuery query;
    query.prepare("INSERT INTO Interaction (idContact, contenu, dateInteraction) VALUES ( :c, :t, :d)");
    query.bindValue(":c", QString::fromStdString(idC));
    query.bindValue(":t", QString::fromStdString(I->getContent()));
    query.bindValue(":d", QString::fromStdString(I->getDI()));
    query.exec();

    //InterTodo
    QString inter=QString::fromStdString(I->getContent());
    query.prepare("SELECT * from Interaction WHERE contenu='"+inter+"';");
    query.exec();
    while(query.next())
    {
        QString id=QString(query.value(0).toString());
        idI=id.toStdString();
    }
}

/**
 *@fn recTache(Tache *T)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief ajouter une tache a la base de donnée
 *@return rien
*/
void basedonnee::recTache(Tache *T) //ajouter une tache a la base de donnée
{
    QSqlQuery query;
    query.prepare("INSERT INTO Todo (contenu, dateTodo) VALUES ( :t, :d)");
    query.bindValue(":t", QString::fromStdString(T->getAction()));
    query.bindValue(":d", QString::fromStdString(T->getDT()));
    query.exec();

    //InterTodo
    QString inter=QString::fromStdString(T->getAction());
    query.prepare("SELECT * from Todo WHERE contenu='"+inter+"';");
    query.exec();
    while(query.next())
    {
        QString id=QString(query.value(0).toString());
        idT=id.toStdString();
    }

    //remplir bd de InterTodo
    query.prepare("INSERT INTO InterTodo (idTodo, idInteraction) VALUES ( :t, :i)");
    query.bindValue(":t", QString::fromStdString(idT));
    query.bindValue(":i", QString::fromStdString(idI));
    query.exec();
}

/**
 *@fn recIDCI(string i)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief recherche d'interactions par ID de contact
 *@return rien
*/
void basedonnee::recIDCI(string i)
{
    idC=i;
    bool verif=false;
    list<Interaction *> li;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    //selection interaction
    query.prepare("SELECT * from Interaction WHERE idContact="+s+";");
    query.exec();
    while(query.next())
    {
        QString in=QString(query.value(2).toString());
        QString din=QString(query.value(3).toString());
        I=new Interaction(in.toStdString(),din.toStdString());
        li.push_back(I);
        verif=true;
    }


    //selectionner Contact
    query.prepare("SELECT * from Contact WHERE idContact="+s+";");
    query.exec();
    while(query.next())
    {
        QString ln=QString(query.value(1).toString());
        QString fn=QString(query.value(2).toString());
        c=new Contact(ln.toStdString(), fn.toStdString());
    }

    if(verif)
    {
        emit sendLI(li,c);
    }
    else
    {
        emit messageLI("//Ce contact n'a aucune interaction.", c);
    }

}

/**
 *@fn recIDCIT(string i)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief recherche d' interaction/tache par ID de contact
 *@return rien
*/
void basedonnee::recIDCIT(string i)
{
    map<Interaction *, list<Tache *>> it;
    list<Tache *> lt;
    idC=i;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    bool verifI=false;
    query.prepare("SELECT * from Interaction WHERE idContact="+s+";");
    query.exec();
    while(query.next())
    {
        QString idi=QString(query.value(0).toString());
        QString in=QString(query.value(2).toString());
        QString din=QString(query.value(3).toString());
        QSqlQuery quer;
        quer.prepare("SELECT * from InterTodo WHERE idInteraction="+idi+";");
        quer.exec();
        while(quer.next())
        {
            QString idt=QString(quer.value(1).toString());
            QSqlQuery qr;
            qr.prepare("SELECT * from Todo WHERE idTodo="+idt+";");
            qr.exec();
            while(qr.next())
            {
                QString ct=QString(qr.value(1).toString());
                QString dt=QString(qr.value(2).toString());
                T=new Tache(ct.toStdString(), dt.toStdString());
                lt.push_back(T);
            }

        }
        I=new Interaction(in.toStdString(), din.toStdString());
        it[I]=lt;
        lt.clear();
        verifI=true;
    }

    //selectionner Contact
    query.prepare("SELECT * from Contact WHERE idContact="+s+";");
    query.exec();
    while(query.next())
    {
        QString ln=QString(query.value(1).toString());
        QString fn=QString(query.value(2).toString());
        c=new Contact(ln.toStdString(), fn.toStdString());
    }

    if(verifI)
    {
        emit sendLCIT(it,c);
    }
    else
    {
        emit messageLITI("//ce Contact n'a aucune interaction", c);
    }


}

/**
 *@fn recdda(QString du, QString au, string i)
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief recherche d'interactions par date
 *@return rien
*/
void basedonnee::recdda(QString du, QString au, string i)
{
    map<Interaction *, list<Tache *>> it;
    list<Tache *> lt;
    idC=i;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    bool verif=false;
    query.prepare("SELECT * from Interaction WHERE idContact="+s+" and dateInteraction between '"+du+"' and '"+au+"';");
    query.exec();
    while(query.next())
    {
        QString idi=QString(query.value(0).toString());
        QString in=QString(query.value(2).toString());
        QString din=QString(query.value(3).toString());
        QSqlQuery quer;
        quer.prepare("SELECT * from InterTodo WHERE idInteraction="+idi+";");
        quer.exec();
        while(quer.next())
        {
            QString idt=QString(quer.value(1).toString());
            QSqlQuery qr;
            qr.prepare("SELECT * from Todo WHERE idTodo="+idt+";");
            qr.exec();
            while(qr.next())
            {
                QString ct=QString(qr.value(1).toString());
                QString dt=QString(qr.value(2).toString());
                T=new Tache(ct.toStdString(), dt.toStdString());
                lt.push_back(T);
            }

        }
        I=new Interaction(in.toStdString(), din.toStdString());
        it[I]=lt;
        lt.clear();
        verif=true;
    }

    //selectionner Contact
    query.prepare("SELECT * from Contact WHERE idContact="+s+";");
    query.exec();
    while(query.next())
    {
        QString ln=QString(query.value(1).toString());
        QString fn=QString(query.value(2).toString());
        c=new Contact(ln.toStdString(), fn.toStdString());
    }


    if(verif)
    {
        emit sendLIDA(it,c);
    }
    else
    {
        emit messageLIDA("//Ce contact n'a aucune interaction entre ces deux dates", c);
    }

}

/**
 *@fn remplirJson()
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief remplir JSON
 *@return QJsonArray
*/
QJsonArray basedonnee::remplirJson()
{

    QJsonArray tab;
    QSqlQuery query;
    query.prepare("SELECT * from Contact");
    if(!query.exec())
    {
        qDebug() << "error";
    }
    else
    {
        while(query.next())
        {
            QVariantMap map;
            map.insert("Nom: ",query.value(1));
            map.insert("Prenom: ",query.value(2));
            map.insert("Entreprise: ",query.value(3));
            map.insert("Mail: ",query.value(4));
            map.insert("Telephone: ",query.value(5));
            map.insert("date de creation: ",query.value(6));
            tab.push_back(QJsonObject::fromVariantMap(map));
        }
    }
    return tab;

}

void basedonnee::recNB()
{
    int nb=0;
    QSqlQuery query;
    query.prepare("SELECT COUNT (*) from Contact");
    query.exec();
    if(query.next())
    {
        nb=query.value(0).toInt();
    }
    emit NB(nb);
}
