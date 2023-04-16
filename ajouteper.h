#ifndef AJOUTEPER_H
#define AJOUTEPER_H

#include <QDialog>

namespace Ui {
class ajoutePer;
}

class ajoutePer : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutePer(QWidget *parent = nullptr);
    ~ajoutePer();

    QString getNom();
    QString getPrenom();

private:
    Ui::ajoutePer *ui;
};

#endif // AJOUTEPER_H
