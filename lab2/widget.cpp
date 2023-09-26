#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_invert_stateChanged(int arg1)
{
    if(arg1==2)
    {
        ui->label->setText("<-");
    }
    else
    {
        ui->label->setText("->");
    }
}


void Widget::on_weight_clicked()
{
    ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
    ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
    ui->input->addItem("Кілограми");
    ui->input->addItem("Грами");
    ui->input2->addItem("Тонна");
    ui->input2->addItem("Фунти");
}


void Widget::on_length_clicked()
{
    ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
    ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
    ui->input->addItem("Міліметри");
    ui->input->addItem("Метри");
    ui->input2->addItem("Сантимерти");
    ui->input2->addItem("Дециметри");
}


void Widget::on_choice_clicked()
{
    ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
    ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
    ui->input->addItem("Міліметри");
    ui->input->addItem("Метри");
    ui->input2->addItem("Сантимерти");
    ui->input2->addItem("Дециметри");
    ui->input->addItem("Кілограми");
    ui->input->addItem("Грами");
    ui->input2->addItem("Тонна");
    ui->input2->addItem("Фунти");
}


void Widget::on_weight_released()
{
    ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
    ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
}


void Widget::on_length_released()
{
    ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
    ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
}


void Widget::on_choice_released()
{
    ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
    ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
}


void Widget::on_weight_toggled(bool checked)
{
    if(!checked){
        ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
        ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
    }
}


void Widget::on_length_toggled(bool checked)
{
    if(!checked){
        ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
        ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
    }
}


void Widget::on_choice_toggled(bool checked)
{
    if(!checked){
        ui->input->removeItem(0); ui->input->removeItem(1); ui->input->removeItem(2); ui->input->removeItem(3);
        ui->input2->removeItem(0); ui->input2->removeItem(1); ui->input2->removeItem(2); ui->input2->removeItem(3);
    }
}


void Widget::on_clear_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
}


void Widget::on_spinBox_valueChanged(int arg1)
{
    ui->textEdit->setFont(QFont("Arial", arg1));
    ui->textEdit_2->setFont(QFont("Arial", arg1));
    ui->label->setFont(QFont("Arial", arg1));
}


void Widget::on_convert_clicked()
{
    double inputing = ui->textEdit->toPlainText().toInt();
    double inputing2 = ui->textEdit_2->toPlainText().toInt();
    int comboBoxIndex = ui->input->currentIndex();
    int comboBox2Index = ui->input2->currentIndex();
    double answer = 0;
    QString arrow = ui->label->text();
    //start weight
    if(arrow == "->"){
        if(ui->weight->isChecked()){
            if (comboBoxIndex==0 && comboBox2Index==0){
                answer = inputing/1000;
            }
            if (comboBoxIndex==0 && comboBox2Index==1){
                answer = inputing*2.205;
            }
            if (comboBoxIndex==1 && comboBox2Index==0){
                answer = inputing/10000000;
            }
            if (comboBoxIndex==1 && comboBox2Index==1){
                answer = inputing*0.00205;
            }
            ui->textEdit_2->setText(QString::number(answer));
        }
        if(ui->length->isChecked()){
            if (comboBoxIndex==0 && comboBox2Index==0){
                answer = inputing/10;
            }
            if (comboBoxIndex==0 && comboBox2Index==1){
                answer = inputing/100;
            }
            if (comboBoxIndex==1 && comboBox2Index==0){
                answer = inputing*100;
            }
            if (comboBoxIndex==1 && comboBox2Index==1){
                answer = inputing*10;
            }
            ui->textEdit_2->setText(QString::number(answer));
        }
        else if(ui->choice->isChecked()){
            if (comboBoxIndex==0 && comboBox2Index==0){
                answer = inputing/10;
            }
            if (comboBoxIndex==0 && comboBox2Index==1){
                answer = inputing/100;
            }
            if (comboBoxIndex==1 && comboBox2Index==0){
                answer = inputing*100;
            }
            if (comboBoxIndex==1 && comboBox2Index==1){
                answer = inputing*10;
            }
            if (comboBoxIndex==2 && comboBox2Index==2){
                answer = inputing/1000;
            }
            if (comboBoxIndex==2 && comboBox2Index==3){
                answer = inputing*2.205;
            }
            if (comboBoxIndex==3 && comboBox2Index==2){
                answer = inputing/10000000;
            }
            if (comboBoxIndex==3 && comboBox2Index==3){
                answer = inputing*0.00205;
            }
            ui->textEdit_2->setText(QString::number(answer));

        }
    }
        else if (arrow == "<-"){
            if (comboBoxIndex==0 && comboBox2Index==0){
                answer = inputing2*1000;
            }
            if (comboBoxIndex==0 && comboBox2Index==1){
                answer = inputing2/2.205;
            }
            if (comboBoxIndex==1 && comboBox2Index==0){
                answer = inputing2*10000000;
            }
            if (comboBoxIndex==1 && comboBox2Index==1){
                answer = inputing2/0.00205;
            }
            ui->textEdit->setText(QString::number(answer));
        }
        if(ui->length->isChecked()){
            if (comboBoxIndex==0 && comboBox2Index==0){
                answer = inputing2*10;
            }
            if (comboBoxIndex==0 && comboBox2Index==1){
                answer = inputing2*100;
            }
            if (comboBoxIndex==1 && comboBox2Index==0){
                answer = inputing2/100;
            }
            if (comboBoxIndex==1 && comboBox2Index==1){
                answer = inputing2/10;
            }
            ui->textEdit->setText(QString::number(answer));
        }
        else if(ui->choice->isChecked()){
            if (comboBoxIndex==0 && comboBox2Index==0){
                answer = inputing2*10;
            }
            if (comboBoxIndex==0 && comboBox2Index==1){
                answer = inputing2*100;
            }
            if (comboBoxIndex==1 && comboBox2Index==0){
                answer = inputing2/100;
            }
            if (comboBoxIndex==1 && comboBox2Index==1){
                answer = inputing2/10;
            }
            if (comboBoxIndex==2 && comboBox2Index==2){
                answer = inputing2*1000;
            }
            if (comboBoxIndex==2 && comboBox2Index==3){
                answer = inputing2/2.205;
            }
            if (comboBoxIndex==3 && comboBox2Index==2){
                answer = inputing2*10000000;
            }
            if (comboBoxIndex==3 && comboBox2Index==3){
                answer = inputing2/0.00205;
            }
            ui->textEdit->setText(QString::number(answer));
        }

}



