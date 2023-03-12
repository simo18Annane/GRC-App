/**
 * @file Tache.cpp
 * @class Tache
 * @brief Classe Tache
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include <iostream>

#include "Tache.h"

using namespace std;

//constructeurs
Tache::Tache()
{
    setDateAction();
	setAction("NULL");
    setDT(toStringDT());
}

Tache::Tache(const string &a, const string &dateT)
{
    this->setDateAction();
    this -> setAction(a);
    this -> setDT(dateT);
}

/*
Tache::Tache(const string &a)
{
    this -> setAction(a);
    this -> setCheck(true);
}
*/

Tache::~Tache()
{
    //pas de corps dans ce destructeur pour le moment
}

//accesseurs
/**
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief accesseurs de la classe Tache
*/
string Tache::getAction() const
{
    return this -> action;
}

struct sdateAuto Tache::getDateAction() const
{
    return this -> dateAction;
}

string Tache::getDT() const
{
    return this->dt;
}

/*
bool Tache::getCheck() const
{
    return this -> check;
}
*/

//mutateurs
/**
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief mutateurs de la classe Tache
*/
void Tache::setAction(const string &a)
{
    this -> action = a;
}

void Tache::setDateAction()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateAction.jour = ymd.day();
    this -> dateAction.mois = ymd.month();
    this -> dateAction.annee = ymd.year();
}

void Tache::setDT(const string &dateT)
{
    this->dt=dateT;
}

/*
void Tache::setCheck(const bool &c)
{
    this -> check = c;
}
*/

//fonctions amie 
/**
 *@fn operator<<
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief surcharge de l'operateur <<
 *@return ostream&
*/
ostream& operator<<(ostream &o, const Tache &t)
{
    //petit check pour varier l'affichage, avec ou sans format de date, suivant la nature de la tache, si elle contient une date ou non
    //if(t.getCheck() == false)
    {
        struct sdateAuto d = t.getDateAction();
	    o << "@todo" << " " << t.getAction() << " " << "@date" << " " << d.jour << "/" << d.mois << "/" << d.annee;
    }
    /*else
    {
        o << "@todo" << " " << t.getAction();
    }*/
    return o;
} 

//fonctions
/**
 *@fn toStringDT()
 *@author Annane Mohamed
 *@author Bahous Mohamed Aymene
 *@brief fonction toString pour la date
 *@return ostream&
*/
string Tache::toStringDT()
{
    return to_string(this->dateAction.jour.operator unsigned int())+"/"+to_string(this->dateAction.mois.operator unsigned int())+"/"+to_string(this->dateAction.annee.operator int());
}
