#include "confirmationdialog.h"

ConfirmationDialog::ConfirmationDialog(QWidget *parent, QString text)
    : QDialog(parent)
{
    //hardcoding go brtt
    this->layout = new QVBoxLayout();
    this->label = new QLabel();
    this->label->setText(text);
    this->layout->addWidget(this->label);
    this->buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(this->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(this->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    this->layout->addWidget(this->buttonBox);
    this->setLayout(this->layout);
}

ConfirmationDialog::~ConfirmationDialog()
{
    delete this->layout;
    delete this->label;
    delete this->buttonBox;
}
