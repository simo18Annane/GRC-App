/**
 * @file Contact.cpp
 * @class Contact
 * pas d'heritage pour le moment
 * @brief Classe Contact
 * @struct sdate
 * @author Bahous Mohamed Aymene
 * @author Annane Mohamed
 * @author Binome
 * @date 16/12/2022
 * Jalon final
*/

#include <iostream>

#include "Contact.h"

using namespace std;

//constructeurs
Contact::Contact()
{
    this -> setLastname("null");
    this -> setFirstname("null");
    this -> setCompany("null");
    this -> setMail("null");
    this -> setPhone("null");
    this -> setPicture("null");
    this -> setDateOfCreation();
    this -> setDateOfEdit();
    this -> setDC(toStringDC());
    this->setDE(toStringDE());
}

Contact::Contact(const string &l, const string &f, const string &c, const string &m, const string &ph, const string &pi, const string &datec, const string &datee)
{
    this -> setLastname(l);
    this -> setFirstname(f);
    this -> setCompany(c);
    this -> setMail(m);
    this -> setPhone(ph);
    this -> setPicture(pi);
    //this -> setDateOfCreation();
    //this -> setDateOfEdit();
    this->setDC(datec);
    this->setDE(datee);
}

Contact::Contact(const string &ln, const string &fn)
{
    this -> setLastname(ln);
    this -> setFirstname(fn);
}

//destructeur
Contact::~Contact()
{
    //pas de corps dans ce destructeur
}

//accesseurs
/**
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief accesseurs de la classe Contact
*/
int Contact::getId() const
{
    return this -> id;
}

string Contact::getLastname() const
{
    return this -> lastname;
}

string Contact::getFirstname() const
{
    return this -> firstname;
}

string Contact::getCompany() const
{
    return this -> company;
}

string Contact::getMail() const
{
    return this -> mail;
}

string Contact::getPhone() const
{
    return this -> phone;
}

string Contact::getPicture() const
{
    return this -> picture;
}

string Contact::getDC() const
{
    return this->dc;
}

string Contact::getDE() const
{
    return this->de;
}

struct sdateAuto Contact::getDateOfCreation() const
{
    return this -> dateOfCreation;
}

struct sdateAuto Contact::getDateOfEdit() const
{
    return this -> dateOfEdit;
}

/*
list<Interaction> Contact::getLI() const
{
    return this -> li;
}
*/

//mutateurs
/**
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief mutateurs de la classe Contact
 *@return rien
*/
void Contact::setId(const int &i)
{
    this -> id = i;
}

void Contact::setLastname(const string &l)
{
    this -> lastname = l;
}

void Contact::setFirstname(const string &f)
{
    this -> firstname = f;
}

void Contact::setCompany(const string &c)
{
    this -> company = c;
}

void Contact::setMail(const string &m)
{
    this -> mail = m;
}

void Contact::setPhone(const string &ph)
{
    this -> phone = ph;
}

void Contact::setPicture(const string &pi)
{
    this -> picture = pi;
}

void Contact::setDC(const string &datec)
{
    this->dc=datec;
}

void Contact::setDE(const string &datee)
{
    this->de=datee;
}

void Contact::setDateOfCreation()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateOfCreation.jour = ymd.day();
    this -> dateOfCreation.mois = ymd.month();
    this -> dateOfCreation.annee = ymd.year();
}

void Contact::setDateOfEdit()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateOfEdit.jour = ymd.day();
    this -> dateOfEdit.mois = ymd.month();
    this -> dateOfEdit.annee = ymd.year();
}

//fonctions
/*
void Contact::addContactInteraction(const Interaction &i)
{
    this -> li.push_back(i);
}
*/

//fonction amie
/**
 *@fn operator<<
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief surcharge de l'operateur <<
 *@return ostream&
*/
ostream& operator<<(ostream &o, const Contact &c)
{
    o << c.getLastname() << " " << c.getFirstname() << "\n" << c.getCompany() << "\n" << c.getMail() << "\n" << c.getPhone() << "\n" << c.getPicture() << "\n" << c.getDateOfCreation().jour << "/" << c.getDateOfCreation().mois << "/" << c.getDateOfCreation().annee << "\n" << c.getDateOfEdit().jour << "/" << c.getDateOfEdit().mois << "/" << c.getDateOfEdit().annee << "\n";
    return o;
}

/**
 *@fn toStringDC()
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief fonction toString pour la date de creation du contact
 *@return string
*/
string Contact::toStringDC()
{
    return to_string(this->dateOfCreation.jour.operator unsigned int())+"/"+to_string(this->dateOfCreation.mois.operator unsigned int())+"/"+to_string(this->dateOfCreation.annee.operator int());

}

/**
 *@fn toStringDE()
 *@author Bahous Mohamed Aymene
 *@author Annane Mohamed
 *@brief fonction toString pour la date de modification du contact
 *@return string
*/
string Contact::toStringDE()
{
    return to_string(this->dateOfEdit.jour.operator unsigned int())+"/"+to_string(this->dateOfEdit.mois.operator unsigned int())+"/"+to_string(this->dateOfEdit.annee.operator int());
}
