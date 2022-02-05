#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QGridLayout(this);

    rotor1 = new QLabel;
    mainLayout->addWidget(rotor1, 0, 0);
    rotor2 = new QLabel;
    mainLayout->addWidget(rotor2, 0, 1);

    QString alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    rotor1->setText(alphabet);
    rotor2->setText(alphabet);

    input_user = new QLineEdit;
    //input_user->


    DEBUG_button_update = new QPushButton;
    connect(DEBUG_button_update, &QPushButton::pressed, this, &Widget::update_ui_rotor);
    DEBUG_button_update->setText(QString("update rotor"));
    mainLayout->addWidget(DEBUG_button_update, 2, 0);
    //update_ui_rotor();
}

Widget::~Widget()
{
}

void Widget::update_ui_rotor()
{
    QLabel* table_label_rotors[] = {rotor1, rotor2};
    char* table_rotors = enigma.get_rotors();


    for (int i = 0; i < 2; i++) {
        QString str;
        for (int c = 0; c < 26; c++) {
            str.append(table_rotors[c]);
        }
        table_label_rotors[i]->setText(str);
    }
}
