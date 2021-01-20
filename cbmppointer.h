#ifndef CBMPPOINTER_H
#define CBMPPOINTER_H

#include "qpushbutton.h"
#include "QPainter"

class CBmpPointer : public QPushButton
{
public:
    CBmpPointer(QPixmap *pImage, const QPoint &ptOrigin, const QRect &rtArea, QWidget *parent = Q_NULLPTR);
    ~CBmpPointer();
    void SetAngle(int nAngleSpace,int nPointOffset);
    void SetMinMaxData(int nMinData,int nMaxData);
    void SetNum(int nCurNum);
private:
    QPixmap *m_pImg;
    QPoint m_ptstart;
    int m_nAngleSpace;
    int m_nPointOffset;
    int m_nMinData;
    int m_nMaxData;
    int m_nCurData;

protected:
    virtual void paintEvent(QPaintEvent *);
};

#endif // CBMPPOINTER_H

