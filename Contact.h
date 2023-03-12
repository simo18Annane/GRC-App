#ifndef CONTACT_H
#define CONTACT_H

#include <chrono>
#include <iostream>
#include <string>
#include <list>

#include "sdateAuto.h"
#include "date/date.h"
#include "date/chrono_io.h"
//#include "Interaction.h"
//#include "Interaction.cpp"
//#include "Tache.h"

using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
using namespace std;

class Contact
{

private:
    //attributs
    int id;
    string lastname;
    string firstname;
    string company;
    string mail;
    string phone;
    string picture;
    string dc=" ";
    string de=" ";
    struct sdateAuto dateOfCreation;
    struct sdateAuto dateOfEdit;
    //list<Interaction> li;
public:
    //constructeurs
    Contact();
    Contact(const string &, const string &);
     Contact(const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &);
    //destructeur
    ~Contact();
    //accesseurs
    int getId() const;
    string getLastname() const;
    string getFirstname() const;
    string getCompany() const;
    string getMail() const;
    string getPhone() const;
    string getPicture() const;
    string getDC() const;
    string getDE() const;
    struct sdateAuto getDateOfCreation() const;
    struct sdateAuto getDateOfEdit() const;
    //list<Interaction> getLI() const;
    //mutateurs
    void setId(const int &);
    void setLastname(const string &);
    void setFirstname(const string &);
    void setCompany(const string &);
    void setMail(const string &);
    void setPhone(const string &);
    void setPicture(const string &);
    void setDC(const string &);
    void setDE(const string &);
    void setDateOfCreation();
    void setDateOfEdit();
    //fonction
    string toStringDC();
    string toStringDE();
    //void addContactInteraction(const Interaction &);
    //fonction amie
    friend ostream& operator<<(ostream &, const Contact&);

};

#endif // CONTACT_H

