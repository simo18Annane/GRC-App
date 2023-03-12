#include "AfficheTaches.h"
#include "ui_AfficheTaches.h"

AfficheTaches::AfficheTaches(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficheTaches)
{
    ui->setupUi(this);
}

AfficheTaches::~AfficheTaches()
{
    delete ui;
}

void AfficheTaches::on_RetourButton_clicked()
{
    this -> close();
}

