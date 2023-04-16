
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void PerRef();

private slots:
    void on_ajoutePer_clicked();

    void on_supPer_clicked();

private:
    Ui::MainWindow *ui;
    dbmanager dbm;
};

#endif // MAINWINDOW_H
