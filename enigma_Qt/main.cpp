
#include "widget.h"

#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QString styleSheet("QLabel{color:blue}");
    app.setStyleSheet(styleSheet);
    Widget widget;
    widget.show();
    return app.exec();
}
