#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "adddialog.h"
#include "confirmationdialog.h"
#include "pdf.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    //creating the dialog that helps the user add a new image
    AddDialog dialog(this);
    dialog.exec();
    if (dialog.result() != QDialog::Accepted) //exited
        return;

    //adding
    this->ui->imageList->addItem(dialog.getPath());
}

QListWidgetItem *MainWindow::getSelectedItem()
{
    QList<QListWidgetItem*> list = this->ui->imageList->selectedItems();
    if (!list.length())
        return NULL;
    return list[0];
}

//removes selected item
void MainWindow::on_removeButton_clicked()
{
    QListWidgetItem* selected = this->getSelectedItem();
    if (!selected)
        return;

    ConfirmationDialog dialog(this, "Are you sure you want to delete the selected image?");
    dialog.exec();

    if (dialog.result())
    {
        this->ui->imageList->removeItemWidget(selected);
        delete selected;
    }
}


void MainWindow::on_upButton_clicked() //todo: better shifting
{
    //getting the selected item
    QListWidgetItem *selected = this->getSelectedItem();
    if (!selected)
        return;

    //checking if the item can be shifted
    int selectedRow = this->ui->imageList->row(selected);
    if (!selectedRow)
        return;

    //shifting
    QListWidgetItem *upperItem = this->ui->imageList->takeItem(selectedRow - 1);
    this->ui->imageList->removeItemWidget(selected);
    this->ui->imageList->removeItemWidget(upperItem);
    this->ui->imageList->insertItem(selectedRow - 1, selected);
    this->ui->imageList->insertItem(selectedRow, upperItem);
}


void MainWindow::on_downButton_clicked()
{
    //getting the selected item
    QListWidgetItem *selected = this->getSelectedItem();
    if (!selected)
        return;

    //checking if the item can be shifted
    int selectedRow = this->ui->imageList->row(selected);
    if (selectedRow == this->ui->imageList->size().height() - 1)
        return;

    //shifting
    QListWidgetItem *lowerItem = this->ui->imageList->takeItem(selectedRow + 1);
    this->ui->imageList->removeItemWidget(selected);
    this->ui->imageList->removeItemWidget(lowerItem);
    this->ui->imageList->insertItem(selectedRow + 1, selected);
    this->ui->imageList->insertItem(selectedRow, lowerItem);

}

void MainWindow::on_actionNew_triggered()
{
    ConfirmationDialog dialog(this, "Are you sure you want to create a new dialog?");

    dialog.exec();
    if (dialog.result())
        this->ui->imageList->clear();
}

void MainWindow::on_actionQuit_triggered()
{
    ConfirmationDialog dialog(this, "Are you sure you want to close the application?");

    dialog.exec();
    if (dialog.result())
        this->destroy();
}

void MainWindow::on_actionExport_triggered()
{
    //getting the save path
    QString pathDialog = QFileDialog::getSaveFileName(this, "Export document", "", "PDFs (*.pdf)");

    if (pathDialog != "") {
        qDebug() << "test\n";
        PDFCreator creator(this->ui->imageList);
        creator.createPDF(pathDialog.toStdString());
    }
}


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_AddFiles_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, "Open", "", "Images (*.png *.jpg *.jpeg)");
    if (!files.size())
        return;

    //adding
    for (auto &path: files)
        this->ui->imageList->addItem(path);
}




















