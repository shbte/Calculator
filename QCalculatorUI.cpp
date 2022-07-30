#include "QCalculatorUI.h"

// 构造函数
QCalculatorUI::QCalculatorUI() : QWidget(NULL, Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint)
{
    m_edit = new QLineEdit(this);
}

// 构造函数
bool QCalculatorUI::construct()
{
    bool ret = false;
    const char* btnText[20] = { "7", "8", "9", "+", "(", "4", "5", "6", "-", ")", "1", "2", "3", "*", "<-", "0", ".", "=", "/", "C" };

    if(m_edit != NULL)
    {
        // 输出框: 大小, 基于窗口的偏移量
        m_edit->resize(240, 30);
        m_edit->move(10, 10);

        // 属性: 只读, 向右对齐
        m_edit->setReadOnly(true);
        m_edit->setAlignment(Qt::AlignRight);

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                m_buttons[i * 5 + j] = new QPushButton(this);

                if(m_buttons[i * 5 + j] != NULL)
                {
                    // 按钮大小, 基于窗口的偏移量
                    m_buttons[i * 5 + j]->resize(40, 40);
                    m_buttons[i * 5 + j]->move(10 + (10 + 40) * j, 50 + (10 + 40) * i);

                    // 按钮文本
                    m_buttons[i * 5 + j]->setText(btnText[i * 5 + j]);
                }
            }
        }

        ret = true;
    }

    return ret;
}

// 实例函数
QCalculatorUI* QCalculatorUI::NewInstance()
{
    QCalculatorUI* ret = new QCalculatorUI();

    if((ret == NULL) || (!ret->construct()))
    {
        delete ret;

        ret = NULL;
    }

    return ret;
}

void QCalculatorUI::show()
{
    QWidget::show();

    move(1200, 300);
    setFixedSize(frameGeometry().width(), frameGeometry().height());
}

// 析构函数
QCalculatorUI::~QCalculatorUI()
{
    delete m_edit;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            delete m_buttons[i * 5 + j];
        }
    }
}
