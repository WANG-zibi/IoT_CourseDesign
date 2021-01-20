#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QWidget>

namespace Ui {
class SwitchButton;
}

class SwitchButton : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchButton(QWidget *parent = nullptr);
    ~SwitchButton();

private:
    Ui::SwitchButton *ui;
};

#endif // SWITCHBUTTON_H
