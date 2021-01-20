#ifndef ROOMCONTROL_H
#define ROOMCONTROL_H

#include <QWidget>

namespace Ui {
class RoomControl;
}

class RoomControl : public QWidget
{
    Q_OBJECT

public:
    explicit RoomControl(QWidget *parent = nullptr);
    ~RoomControl();

private:
    Ui::RoomControl *ui;
};

#endif // ROOMCONTROL_H
