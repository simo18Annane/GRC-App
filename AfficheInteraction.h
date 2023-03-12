#ifndef AFFICHEINTERACTION_H
#define AFFICHEINTERACTION_H

#include <QWidget>

namespace Ui {
class AfficheInteraction;
}

class AfficheInteraction : public QWidget
{
    Q_OBJECT

public:
    explicit AfficheInteraction(QWidget *parent = nullptr);
    ~AfficheInteraction();

private slots:

    void on_RetourButton_clicked();

private:
    Ui::AfficheInteraction *ui;
};

#endif // AFFICHEINTERACTION_H
