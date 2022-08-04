#include <QApplication>

#include "QCalculatorDec.h"
#include "QCalculatorUI.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QCalculatorDec* pcal = new QCalculatorDec();

    QCalculatorUI* cal = QCalculatorUI::NewInstance();
    int ret = 0;

    if(cal != NULL)
    {
        cal->show();

        qDebug() << "x=" << cal->x() << "y=" << cal->y() << "width=" << cal->width() << "height=" << cal->height();
        qDebug() << "geometry.x=" << cal->geometry().x() << "geometry.y=" << cal->geometry().y() << "geometry.width=" << cal->geometry().width()
                 << "geometry.height=" << cal->geometry().height();
        qDebug() << "frameGeometry.x=" << cal->frameGeometry().x() << "frameGeometry.y=" << cal->frameGeometry().y() << "frameGeometry.width=" << cal->frameGeometry().width()
                 << "frameGeometry.height=" << cal->frameGeometry().height();

        ret = a.exec();

        delete cal;
    }

    return ret;
}
