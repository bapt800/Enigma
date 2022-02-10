#include "widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setUp_enigma();

    layoutMain = new QGridLayout(this);
    layoutRotors = new QBoxLayout(QBoxLayout::TopToBottom);

    setUp_labelRotor();
    layoutMain->addLayout(layoutRotors, 0, 0, 1, 2);

    inputUser = new QLineEdit();
    layoutMain->addWidget(inputUser, 1, 0, 1, 2);

    codeinput = new QPushButton(QString("Code"));
    connect(codeinput, &QPushButton::pressed, this, &Widget::code);
    layoutMain->addWidget(codeinput, 2, 0, 1, 1);

    decodeinput = new QPushButton(QString("Decode"));
    connect(decodeinput, &QPushButton::pressed, this, &Widget::decode);
    layoutMain->addWidget(decodeinput, 2, 1, 1, 1);
}

Widget::~Widget()
{
}

void Widget::setUp_enigma()
{
    struct rotors_Settings rotorsSet((char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 8,
                               (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 4,
                               (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 12);
    enigma.set_rotors_settings(rotorsSet);
}

void Widget::setUp_labelRotor()
{


    labelRotors1 = new QLabel();
    labelRotors2 = new QLabel();
    labelRotors3 = new QLabel();

    layoutRotors->addWidget(labelRotors1);
    layoutRotors->addWidget(labelRotors2);
    layoutRotors->addWidget(labelRotors3);


    update_labelRotors();
}

void Widget::update_labelRotors()
{
    struct rotors_Settings settings = enigma.get_rotors_settings();
    QString QsRotor;
    QString index;

    QsRotor.append("Rotor I   ");
    for (int i=0; i<26; i++) {
        QsRotor.push_back(settings._rotor1_table[i]);
    }
    QsRotor.append("  Index: ");
    QsRotor.append(index.number(settings._rotor1_index));
    labelRotors1->setText(QsRotor);

    QsRotor.clear();
    QsRotor.append("Rotor II  ");
    for (int i=0; i<26; i++) {
        QsRotor.push_back(settings._rotor3_table[i]);
    }
    QsRotor.append("  Index: ");
    QsRotor.append(index.number(settings._rotor3_index));
    labelRotors2->setText(QsRotor);

    QsRotor.clear();
    QsRotor.append("Rotor III ");
    for (int i=0; i<26; i++) {
        QsRotor.push_back(settings._rotor3_table[i]);
    }
    QsRotor.append("  Index: ");
    QsRotor.append(index.number(settings._rotor3_index));
    labelRotors3->setText(QsRotor);

}

void Widget::code()
{
    QString msgToCode(inputUser->text());
    QString msgBlack(QString::fromStdString(enigma.code(msgToCode.toStdString())));
    inputUser->setText(msgBlack);
}

void Widget::decode()
{
    QString msgBlack(inputUser->text());
    QString msgToDecode(QString::fromStdString(enigma.decode(msgBlack.toStdString())));
    qDebug()<<msgBlack<<msgToDecode;

    inputUser->setText(msgToDecode);
}












