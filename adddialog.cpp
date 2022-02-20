#include "adddialog.h"
#include "./ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialog)
{
    this->ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete this->ui;
}

QString AddDialog::getPath()
{
    return this->ui->pathEdit->text();
}

void AddDialog::on_browseButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter("Image Files (*.png *.jpg *.jpeg)");
    dialog.exec();
    if (!dialog.result())
        return;

    QString path = dialog.selectedFiles()[0];
    this->ui->pathEdit->setText(path);
}

