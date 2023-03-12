#ifndef AFFICHETACHES_H
#define AFFICHETACHES_H

#include <QWidget>

namespace Ui {
class AfficheTaches;
}

class AfficheTaches : public QWidget
{
    Q_OBJECT

public:
    explicit AfficheTaches(QWidget *parent = nullptr);
    ~AfficheTaches();

private slots:
    void on_RetourButton_clicked();

private:
    Ui::AfficheTaches *ui;
};

#endif // AFFICHETACHES_H
