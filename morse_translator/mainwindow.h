#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

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

    void on_pbLoad_clicked();

    void on_pbSave_clicked();

    void on_inpTEdit_textChanged();

private:
    Ui::MainWindow *ui;

     QString inp_str;
     bool isMorse, containLetter{false};

};
#endif // MAINWINDOW_H
