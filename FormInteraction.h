#ifndef FORMINTERACTION_H
#define FORMINTERACTION_H

#include <QWidget>
#include <QDebug>

#include "Interaction.h"
#include "Tache.h"

namespace Ui {
class FormInteraction;
}

class FormInteraction : public QWidget
{
    Q_OBJECT

private:
    Interaction *I;
    Tache *T;

public:
    explicit FormInteraction(QWidget *parent = nullptr);
    ~FormInteraction();

signals:
    void envoyerInteraction(Interaction *);
    void envoyerTache(Tache *);

private slots:

    void on_AnnulerButton_clicked();

    void on_saveIButton_clicked();

    void on_AjoutButton_clicked();

    void on_newIButton_clicked();

private:
    Ui::FormInteraction *ui;
};

#endif // FORMINTERACTION_H
