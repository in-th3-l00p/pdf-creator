#ifndef CONFIRMATIONDIALOG_H
#define CONFIRMATIONDIALOG_H

#include <QObject>
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>

//hardcoded dialog because im lazy
class ConfirmationDialog: public QDialog
{
    Q_OBJECT

public:
    ConfirmationDialog(QWidget *parent = nullptr, QString text = "");
    ~ConfirmationDialog();

private:
    //ui thangss
    QVBoxLayout *layout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
};

#endif // CONFIRMATIONDIALOG_H
