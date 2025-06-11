#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QRadioButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btn_bilgi_clicked();


    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    bool MezuniyetSorgula();


    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;

};
#endif // DIALOG_H
