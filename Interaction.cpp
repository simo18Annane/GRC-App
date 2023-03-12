/**
 * @file Interaction.cpp
 * @class Interaction
 * pas d'heritage pour le moment
 * @brief Classe Interaction
 * @struct sdate
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include <iostream>

#include "Interaction.h"

using namespace std;

//constructeurs
Interaction::Interaction()
{
    setDateInteraction();
    setContent("null");
    setDI(toStringDI());
}

Interaction::Interaction(const string &c, const string &dateI)
{
    this -> setDateInteraction();
    this -> setContent(c);
    this -> setDI(dateI);
}

Interaction::~Interaction()
{
    //pas de corps dans ce destructeur pour le moment
}

//accesseurs
/**
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief accesseurs de la classe Interaction
*/
string Interaction::getContent() const
{
    return this -> content;
}

struct sdateAuto Interaction::getDateInteraction() const
{
    return this -> dateInteraction;
}

string Interaction::getDI() const
{
    return this ->di;
}

/*
list<Tache> Interaction::getLT() const
{
    return this -> lt;
}
*/

//mutateurs
/**
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief mutateurs de la classe Interaction
*/
void Interaction::setContent(const string &c)
{
    this -> content = c;
}

void Interaction::setDateInteraction()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateInteraction.jour = ymd.day();
    this -> dateInteraction.mois = ymd.month();
    this -> dateInteraction.annee = ymd.year();
}

void Interaction::setDI(const string &dateI)
{
    this ->di=dateI;
}

//fonctions
/*
void Interaction::addInteractionTache(const Tache &t)
{
    this -> getLT().push_back(t);
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
ostream& operator<<(ostream &o, const Interaction &i)
{
    o << i.getContent() << " "; // << i.getDateInteraction().jour << "/" << i.getDateInteraction().mois << "/" << i.getDateInteraction().annee;
    return o;
}

/*
int main()
{
    return 0;
}
*/

/**
 *@fn toStringDI()
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief surcharge de l'operateur <<
 *@return string
*/
string Interaction::toStringDI()
{
    return to_string(this->dateInteraction.jour.operator unsigned int())+"/"+to_string(this->dateInteraction.mois.operator unsigned int())+"/"+to_string(this->dateInteraction.annee.operator int());
}
