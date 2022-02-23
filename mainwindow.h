#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionQuit_triggered();

    void on_actionExport_triggered();

    void on_AddFiles_clicked();

private:
    Ui::MainWindow *ui;
    QListWidgetItem *getSelectedItem();
};
#endif // MAINWINDOW_H
