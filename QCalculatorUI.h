#ifndef QCALCULATORUI_H
#define QCALCULATORUI_H

#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

// QCalculatorUI间接继承QObject
class QCalculatorUI : public QWidget
{
    // 自定义类起始处添加Q_OBJECT
    Q_OBJECT;

private:
    QLineEdit* m_edit;
    QPushButton* m_buttons[20];

    // 二阶构造模式
    QCalculatorUI();
    bool construct();

    // 关联函数
private slots:
    void onButtonClicked();

public:
    static QCalculatorUI* NewInstance();

    void show();

    ~QCalculatorUI();
};

#endif  // QCALCULATORUI_H
