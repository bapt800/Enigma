#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

#include "../Enigma_Core/Enigma.hpp"

class Widget : public QWidget
{


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:

private:
    Q_OBJECT

    Enigma enigma;

};
#endif // WIDGET_H
