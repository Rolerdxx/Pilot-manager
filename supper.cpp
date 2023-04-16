#include "supper.h"
#include "ui_supper.h"

supPer::supPer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supPer)
{
    ui->setupUi(this);
}

supPer::~supPer()
{
    delete ui;
}

QString supPer::getID()
{
    return ui->lineEdit->text();
}
