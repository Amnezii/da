#include "widget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(500, 500);
    QLabel label("Текст"); // Об’явлення незмiнного текстового поля
    QFont font = label.font(); // Получаем текущий шрифт из QLabel
    font.setPointSize(20); // Устанавливаем желаемый размер шрифта (например, 16)
    label.setFont(font);
    QPushButton button("Кнопка"); // Об’явлення кнопки
    QLineEdit textedit; // Поле для введення тексту
    QHBoxLayout layout(&w); // Об’явлення контейнеру
    layout.addWidget(&label); // Додавання вiджетiв у контейнер
    layout.addWidget(&button);
    layout.addWidget(&textedit);
    label.setMaximumSize(300, 50);
    button.setMaximumSize(300, 50);
    textedit.setMaximumSize(300, 50);
    w.show();
    w.setWindowTitle("Заголовок");
    QPushButton *newButton = new QPushButton("Ще одна", &w);
    newButton->move(150, 150);
    newButton->show();
    return a.exec();
}
