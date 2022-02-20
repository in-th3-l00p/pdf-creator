#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AddDialog; }
QT_END_NAMESPACE

class AddDialog: public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    QString getPath();

private slots:
    void on_browseButton_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
