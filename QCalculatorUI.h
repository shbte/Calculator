#ifndef QCALCULATORUI_H
#define QCALCULATORUI_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class QCalculatorUI : public QWidget
{
protected:
    QLineEdit* m_edit;
    QPushButton* m_buttons[20];

    // 二阶构造模式
    QCalculatorUI();
    bool construct();

public:
    static QCalculatorUI* NewInstance();

    void show();

    ~QCalculatorUI();
};

#endif  // QCALCULATORUI_H
