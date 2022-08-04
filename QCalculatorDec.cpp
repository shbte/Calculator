#include "QCalculatorDec.h"

// 判断: 判断数字或者小数点
bool QCalculatorDec::isDigitOrDot(QString s)
{
    return (isNumber(s) || (s == "."));
}

// 判断: 是否为元算符或者括号
bool QCalculatorDec::isSymbol(QString s)
{
    return (isOperator(s) || isLeftBracket(s) || isRightBracket(s));
}

// 判断: 是否为一个数字
bool QCalculatorDec::isNumber(QString s)
{
    bool ret = false;

    s.toDouble(&ret);

    return ret;
}

bool QCalculatorDec::isSign(QString s)
{
    return ((s == "+") || (s == "-"));
}

bool QCalculatorDec::isOperator(QString s)
{
    return (isSign(s) || s == "*" || s == "/");
}

bool QCalculatorDec::isLeftBracket(QString s)
{
    return (s == "(");
}

bool QCalculatorDec::isRightBracket(QString s)
{
    return (s == ")");
}

int QCalculatorDec::priority(QString s)
{
    int ret = 0;

    if(isSign(s))
    {
        ret = 1;
    }
    else if(s == "*" || s == "/")
    {
        ret = 2;
    }
    else
    {
        // TODO...
    }

    return ret;
}

bool QCalculatorDec::mathBracket(QQueue< QString >& exp)
{
    bool ret = false;

    int len = exp.length();

    if(len > 0)
    {
        QStack< QString > stack;

        for(int i = 0; i < len; i++)
        {
            QString s = exp[i];

            if(isLeftBracket(s))
            {
                stack.push(s);
            }
            else if(isRightBracket(s))
            {
                if(stack.length() > 0)
                {
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
            else
            {
                // TODO...
            }
        }

        ret = stack.isEmpty();
    }
    else
    {
        // TODO...
    }

    return ret;
}

QString QCalculatorDec::calculate(QQueue< QString >& exp) {}
QString QCalculatorDec::calculate(QString ls, QString op, QString rs) {}
bool QCalculatorDec::transform(QQueue< QString >& exp, QQueue< QString >& out) {}

// 分离算法, 将运算表达式进行分离
QQueue< QString > QCalculatorDec::split(const QString& exp)
{
    QQueue< QString > ret;

    QString pre = "";
    QString number = "";

    int len = exp.length();

    for(int i = 0; i < len; i++)
    {
        QString s = exp[i];

        // 判断是否为数字(数字或者小数点)
        if(isDigitOrDot(s))
        {
            number += s;
        }
        // 判断是否为符号(符号位, 运算符, 括号)
        else if(isSymbol(s))
        {
            // 将得到的数字加入返回队列, 因为该符号已不可能为数字一部分
            if(!number.isEmpty())
            {
                ret.enqueue(number);

                // 清空数字, 为保存下一数字作准备
                number.clear();
            }

            // 判断是否为符号位(当前为正负号, 且前一位为: 空 左括号 运算符)
            if(isSign(s) && (s == "" || isLeftBracket(s) || isOperator(s)))
            {
                number = s;
            }
            else
            {
                // 将非符号位符号加入返回队列
                ret.enqueue(s);
            }
        }

        // 更新前一字符
        pre = s;
    }

    // 最后不为符号(右括号)而为数字时, 加入返回队列
    if(!number.isEmpty())
    {
        ret.enqueue(number);
    }

    return ret;
}

// 无参构造函数
QCalculatorDec::QCalculatorDec()
{
    m_exp = "";
    m_result = "";

    QString s = "+9+(-3--1)*-5";
    QQueue< QString > ret = split(s);

    for(int i = 0; i < ret.length(); i++)
    {
        qDebug() << ret[i];
    }
}

bool QCalculatorDec::expression(const QString& exp) {}
QString QCalculatorDec::expression() {}
QString QCalculatorDec::result() {}

QCalculatorDec::~QCalculatorDec() {}
