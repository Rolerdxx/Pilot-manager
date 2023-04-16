
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ajouteper.h"
#include "supper.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(dbm.conn()){
        qDebug() << "Connected to database!";
    }else{
        qDebug() << "Cant connect to database";
    }
    PerRef();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PerRef()
{
    dbm.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM personne");
    model->setHeaderData(0, Qt::Horizontal, "id");
    model->setHeaderData(1, Qt::Horizontal, "nom");
    model->setHeaderData(2, Qt::Horizontal, "prenom");
    ui->tablePer->setModel(model);
    dbm.disc();
}



void MainWindow::on_ajoutePer_clicked()
{
    ajoutePer * ap = new ajoutePer;
    int i = ap->exec();
    if(i==QDialog::Accepted){
        QString nom = ap->getNom();
        QString prenom = ap->getPrenom();
        if(nom!=""&&prenom!=""){
            dbm.conn();
            if(dbm.addPer(nom,prenom)){
                statusBar()->showMessage("USER AJOUTE",3000);
                PerRef();
            }else{
                statusBar()->showMessage("Error",3000);
            }
            dbm.disc();
        }else{
            statusBar()->showMessage("un des champs est vide",3000);
        }
    }
}


void MainWindow::on_supPer_clicked()
{
    supPer * ap=new supPer;
    int i = ap->exec();
    if(i==QDialog::Accepted){
        QString id = ap->getID();
        if(id!=""){
            dbm.conn();
            if(dbm.delPer(id)){
                statusBar()->showMessage("PERSONNE SUPPRIMER",3000);
                PerRef();
            }else{
                statusBar()->showMessage("Error",3000);
            }
            dbm.disc();
        }else{
            statusBar()->showMessage("no id",3000);
        }
    }
}

