#include "AfficheInteraction.h"
#include "ui_AfficheInteraction.h"

AfficheInteraction::AfficheInteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficheInteraction)
{
    ui->setupUi(this);
}

AfficheInteraction::~AfficheInteraction()
{
    delete ui;
}


void AfficheInteraction::on_RetourButton_clicked()
{
    this -> close();
}

