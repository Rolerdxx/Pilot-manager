#include "ajouteper.h"
#include "ui_ajouteper.h"

ajoutePer::ajoutePer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutePer)
{
    ui->setupUi(this);
}

ajoutePer::~ajoutePer()
{
    delete ui;
}

QString ajoutePer::getNom()
{
    return ui->nomLine->text();
}

QString ajoutePer::getPrenom()
{
    return ui->prenomLine->text();
}
