#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

#include "../Enigma_lib/Enigma.hpp"

class Widget : public QWidget
{


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void update_ui_rotor();

private:
    Q_OBJECT

    Enigma enigma;

    QGridLayout *mainLayout;

    QLabel *rotor1;
    QLabel *rotor2;

    QLineEdit *input_user;

    QPushButton *DEBUG_button_update;

};
#endif // WIDGET_H
