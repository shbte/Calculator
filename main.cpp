#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // 容器类(父组件), 只显示关闭按钮: WindowCloseButtonHint
    QWidget* w = new QWidget(NULL, Qt::WindowCloseButtonHint);
    // 功能类组件, 用于接收用户输入的字符串
    QLineEdit* le = new QLineEdit(w);
    // 按钮类组件
    QPushButton* button[20] = {0};
    // 按钮文本
    const char* btnText[20] =
    {
        "7", "8", "9", "+", "(",
        "4", "5", "6", "-", ")",
        "1", "2", "3", "*", "<-",
        "0", ".", "=", "/", "C"
    };

    int ret = 0;

    // 设置大小和基于窗口的偏移量
    le->resize(240, 30);
    le->move(10, 10);
    // 设置属性为只读, 使其不能从键盘获取输入信息
    le->setReadOnly(true);
    // 设置为向右对齐
    le->setAlignment(Qt::AlignRight);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            button[i * 5 + j] = new QPushButton(w);

            // 设置按钮的大小和基于窗口的偏移量
            button[i * 5 + j]->resize(40, 40);
            button[i * 5 + j]->move(10 + (10 + 40) * j, 50 + (10 + 40) * i);

            // 设置按钮文本
            button[i * 5 + j]->setText(btnText[i * 5 + j]);
        }
    }

    w->show();
    // 固定窗口
    w->setFixedSize(w->width(), w->height());

    ret = a.exec();

    delete le;
    delete w;

    return ret;
}
