#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QBoxLayout>
#include <string>

#include "../Enigma_Core/Enigma.hpp"
#include "../Enigma_Core/turing.hpp"

class Widget : public QWidget
{


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setUp_enigma();

    void setUp_labelRotor();
    void update_labelRotors();

public slots:
    void code();
    void decode();
    void decodeTuring();

private:
    Q_OBJECT

    QGridLayout *layoutMain;
    QBoxLayout *layoutRotors;

    QLabel *labelRotors1;
    QLabel *labelRotors2;
    QLabel *labelRotors3;

    QLineEdit *inputUser;
    QPushButton *codeInput;
    QPushButton *decodeInput;

    QLineEdit *inputUserLitteral;
    QPushButton *turingInput;;

    Enigma enigma;

};
#endif // WIDGET_H
