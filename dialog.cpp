#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_bilgi_clicked()
{
    QString ogrenci_isim = ui-> lineEdit-> text();
    QString ogrenci_soyad = ui->lineEdit_2->text();
    QString ogrenci_bolum = ui->lineEdit_3->text();
    QMessageBox::information(this, "Öğrenci Bilgileri", +"Ad: " + ogrenci_isim + "\n" + "Soyad: "+ ogrenci_soyad  +"\n" +"Bölüm: "+ ogrenci_bolum, "OK");

}

void Dialog::on_radioButton_clicked()
{
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setEnabled(false);
}

void Dialog::on_radioButton_2_clicked()
{
    ui->groupBox_2->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
}

bool Dialog::MezuniyetSorgula()
{
    bool secenek1 = false;
    bool secenek2 = false;

    int checkboxSayisi = 0;
    int isaretliCheckboxSayisi = 0;

    if(ui->radioButton->isChecked())
    {
        secenek1 = ui->radioButton_6->isChecked();
        QObjectList children = ui->groupBox_3->children();
        checkboxSayisi = children.size();
        for (int i = 0; i < checkboxSayisi; ++i)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox *>(children[i]);
            if (checkBox)
            {
                if (checkBox->isChecked())
                {
                    isaretliCheckboxSayisi++;
                }
            }
        }
        if (isaretliCheckboxSayisi == checkboxSayisi)
        {
            secenek2 = true;
        }
    }
    else if(ui->radioButton_2->isChecked())
    {
        secenek1 = ui->radioButton_11->isChecked();
        QObjectList children = ui->groupBox_5->children();
        checkboxSayisi = children.size();
        for (int i = 0; i < checkboxSayisi; ++i)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox *>(children[i]);
            if (checkBox)
            {
                if (checkBox->isChecked())
                {
                    isaretliCheckboxSayisi++;
                }
            }
        }
        if (isaretliCheckboxSayisi == checkboxSayisi)
        {
            secenek2 = true;
        }
    }

    return secenek1 && secenek2;
}

void Dialog::on_pushButton_2_clicked()
{
    bool mezuniyet_durumu = MezuniyetSorgula();

    QString mesaj;
    if (ui->radioButton->isChecked())
    {
        mesaj = "Lisans mezuniyet durumu: ";
    }
    else if (ui->radioButton_2->isChecked())
    {
        mesaj = "Lisansüstü mezuniyet durumu: ";
    }
    else
    {
        mesaj = "Mezuniyet durumu: ";
    }

    if (mezuniyet_durumu)
    {
        mesaj += "Öğrenci mezun";
    }
    else
    {
        mesaj += "Öğrenci mezun olamaz";
    }

    QMessageBox::information(this, "Mezuniyet Durumu", mesaj, QMessageBox::Ok);
}


