#include "QCalculatorDec.h"

// 数字或小数点判断函数
bool QCalculatorDec::isDigitOrDot(QString s)
{
    return (isNumber(s) || (s == "."));
}

// 符号判断函数
bool QCalculatorDec::isSymbol(QString s)
{
    return (isOperator(s) || isLeftBracket(s) || isRightBracket(s));
}

// 数字判断函数
bool QCalculatorDec::isNumber(QString s)
{
    bool ret = false;

    s.toDouble(&ret);

    return ret;
}

// 符号位判断函数
bool QCalculatorDec::isSign(QString s)
{
    return ((s == "+") || (s == "-"));
}

// 操作符判断函数
bool QCalculatorDec::isOperator(QString s)
{
    return (isSign(s) || s == "*" || s == "/");
}

// 左括号判断函数
bool QCalculatorDec::isLeftBracket(QString s)
{
    return (s == "(");
}

// 右括号判断函数
bool QCalculatorDec::isRightBracket(QString s)
{
    return (s == ")");
}

// 运算优先级判断函数
int QCalculatorDec::priority(QString s)
{
    int ret = 0;

    if(isSign(s))
    {
        // +或-时, 优先级为1
        ret = 1;
    }
    else if(s == "*" || s == "/")
    {
        // *或/时, 优先级为2(1 < 2)
        ret = 2;
    }
    else
    {
        // TODO...
    }

    return ret;
}

// 左右括号匹配函数
bool QCalculatorDec::mathBracket(QQueue< QString >& exp)
{
    bool ret = true;

    int len = exp.length();

    if(len > 0)
    {
        QStack< QString > stack;

        for(int i = 0; i < len; i++)
        {
            QString s = exp[i];

            // 符号为左括号时, 入栈
            if(isLeftBracket(s))
            {
                stack.push(s);
                ret = false;
            }
            // 符号为右括号时, 出栈
            else if(isRightBracket(s))
            {
                if(!stack.isEmpty() && isLeftBracket(stack.top()))
                {
                    stack.pop();
                    ret = true;
                }
                else
                {
                    // 符号为右括号, 但栈内为空时, 则括号匹配失败, 且循环直接结束
                    ret = false;
                    break;
                }
            }
            else
            {
                // TODO...
            }
        }

        // 最后左右符号正好匹配, 此时栈理应为空, 且不是右括号匹配失败而导致的循环匹配结束
        ret = ret && stack.isEmpty();
    }
    else
    {
        // TODO...
    }

    return ret;
}

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
            if(isSign(s) && (pre == "" || isLeftBracket(pre) || isOperator(pre)))
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

    // 将最后的数字, 加入返回队列
    if(!number.isEmpty())
    {
        ret.enqueue(number);
    }

    return ret;
}

bool QCalculatorDec::transform(QQueue< QString >& exp, QQueue< QString >& out)
{
    bool ret = mathBracket(exp);

    QStack< QString > stack;
    out.clear();

    while(ret && !exp.isEmpty())
    {
        // dequeue: 删除头部并返回
        QString s = exp.dequeue();

        if(isNumber(s))
        {
            out.enqueue(s);
        }
        else if(isOperator(s))
        {
            while(!stack.isEmpty() && priority(s) < priority(stack.top()))
            {
                out.enqueue(stack.pop());
            }

            stack.push(s);
        }
        else if(isLeftBracket(s))
        {
            stack.push(s);
        }
        else if(isRightBracket(s))
        {
            while(!stack.isEmpty() && !isLeftBracket(stack.top()))
            {
                out.enqueue(stack.pop());
            }

            stack.pop();
        }
        else
        {
            // TODO...
        }
    }

    while(!stack.isEmpty())
    {
        out.enqueue(stack.pop());
    }

    if(!ret)
    {
        out.clear();
    }

    return ret;
}
QString QCalculatorDec::calculate(QQueue< QString >& exp) {}
QString QCalculatorDec::calculate(QString ls, QString op, QString rs) {}

// 无参构造函数
QCalculatorDec::QCalculatorDec()
{
    m_exp = "";
    m_result = "";

    // QString s = "+9+(-3--1)*-5-(+5)*-5";
    QString s = "-1+2-3*4";
    QQueue< QString > ret = split(s);

    for(int i = 0; i < ret.length(); i++)
    {
        qDebug() << ret[i];
    }

    qDebug() << "";

    QQueue< QString > out;
    transform(ret, out);

    for(int i = 0; i < out.length(); i++)
    {
        qDebug() << out[i];
    }
}

bool QCalculatorDec::expression(const QString& exp) {}
QString QCalculatorDec::expression() {}
QString QCalculatorDec::result() {}

QCalculatorDec::~QCalculatorDec() {}
