#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "translator.cpp"

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

void MainWindow::on_pbLoad_clicked()
{
    this->ui->inpTEdit->clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выберите файл для перевода"),
                                                                        "",
                                                                        tr("Текстовый документ (*.txt)"));

    if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно прочесть файл!"));
                return;
            }
            QTextStream in(&file);
            this->ui->inpTEdit->setText(in.readAll());
            file.close();
        }
}

void MainWindow::on_pbSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить результат перевода"), "",
        tr("Текстовый файл (*.txt)"));

        if (fileName != "") {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно записать файл!"));
                return;
            } else {
                QTextStream stream(&file);
                stream << this->ui->outTEdit->toPlainText();
                stream.flush();
                file.close();
            }
        }
}

void MainWindow::on_inpTEdit_textChanged()
{
    containLetter=false;
    inp_str = this->ui->inpTEdit->toPlainText();
    if(!inp_str.isEmpty())
    {
        auto itr = inp_str.begin();
        auto end = inp_str.end();

        while(itr!=end)
        {
            if((*itr==' ' || *itr=='.' || *itr=='_')&& !containLetter)
            {
                this->ui->inpLabel->setText("Morse");
                isMorse = true;
            }
            else
            {
                containLetter=true;
               this->ui->inpLabel->setText("Non Morse");
                isMorse = false;
            }
            ++itr;
        }

        if(isMorse){inp_str.append(' ');}

        this->ui->outTEdit->setText(translate(inp_str, isMorse));

        this->ui->pbSave->setEnabled(true);
        this->ui->outLabel->setEnabled(true);
        this->ui->outTEdit->setEnabled(true);
    }
    else
    {
        this->ui->outTEdit->clear();
        this->ui->pbSave->setEnabled(false);
        this->ui->outLabel->setEnabled(false);
        this->ui->outTEdit->setEnabled(false);
        this->ui->inpLabel->setText("Введите текст");
    }
}
