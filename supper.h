#ifndef SUPPER_H
#define SUPPER_H

#include <QDialog>

namespace Ui {
class supPer;
}

class supPer : public QDialog
{
    Q_OBJECT

public:
    explicit supPer(QWidget *parent = nullptr);
    ~supPer();

    QString getID();

private:
    Ui::supPer *ui;
};

#endif // SUPPER_H
