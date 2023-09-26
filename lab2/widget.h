#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_invert_stateChanged(int arg1);

    void on_weight_clicked();

    void on_length_clicked();

    void on_choice_clicked();

    void on_weight_released();

    void on_length_released();

    void on_choice_released();

    void on_weight_toggled(bool checked);

    void on_length_toggled(bool checked);

    void on_choice_toggled(bool checked);

    void on_clear_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_convert_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
