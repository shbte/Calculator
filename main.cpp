#include <QApplication>

#include "QCalculator.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QCalculator* cal = QCalculator::NewInstance();
    int ret = 0;

    if(cal != NULL)
    {
        cal->show();

        ret = a.exec();

        delete cal;
    }

    return ret;
}
