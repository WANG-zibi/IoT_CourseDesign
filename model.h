#ifndef MODEL_H
#define MODEL_H

#include <QWidget>

namespace Ui {
class Model;
}

class Model : public QWidget
{
    Q_OBJECT

public:
    explicit Model(QWidget *parent = nullptr);
    ~Model();

private:
    Ui::Model *ui;
};

#endif // MODEL_H
