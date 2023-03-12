#ifndef TACHE_H
#define TACHE_H

#include <iostream>
#include <string>
#include <chrono>

#include "date/date.h"
#include "date/chrono_io.h"
#include "sdateAuto.h"


using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
using namespace std;

class Tache
{
private:
    //attributs
    string action;
    string dt;
    struct sdateAuto dateAction;
    //bool check = false;
public:
    //constructeurs
    Tache();
    Tache(const string &, const string &);
    //Tache(const string &);
    ~Tache();
    //accesseurs
    string getAction() const;
    string getDT() const;
    struct sdateAuto getDateAction() const;
    //bool getCheck() const;
    //mutateurs
    void setAction(const string &);
    void setDT(const string &);
    void setDateAction();
    //void setCheck(const bool &);
    //fonctions amie 
	friend ostream& operator<<(ostream &, const Tache &);
    //fonctions
    string toStringDT();
    //...
};

#endif
