#include "cbmppointer.h"

CBmpPointer::CBmpPointer(QPixmap *pImage, const QPoint &ptOrigin, const QRect &rtArea, QWidget *parent)
      :QPushButton(parent)
{
    m_pImg = pImage;
    m_ptstart.setX(0 - ptOrigin.x());
    m_ptstart.setY(0 - ptOrigin.y());

    move(QPoint(rtArea.left(), rtArea.top()));
    resize(rtArea.size());
}

CBmpPointer::~CBmpPointer()
{
    m_pImg = NULL;
}

void CBmpPointer::SetAngle(int nAngleSpace,int nPointOffset)
{
    m_nAngleSpace = nAngleSpace;
    m_nPointOffset = nPointOffset;
}

void CBmpPointer::SetMinMaxData(int nMinData,int nMaxData)
{
    m_nMinData = nMinData;
    m_nMaxData = nMaxData;
}

void CBmpPointer::SetNum(int nCurNum)
{
    if((nCurNum > m_nMaxData) || (nCurNum < m_nMinData))
    {
        return;
    }
    m_nCurData = nCurNum;
    update();
}

void CBmpPointer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.translate(width()/2, height()/2);
    int rorAngle = m_nPointOffset + ((float)m_nAngleSpace /(float)(m_nMaxData -m_nMinData)) *  (float)(m_nCurData - m_nMinData);
    painter.rotate(rorAngle);
    painter.drawPixmap(m_ptstart, *m_pImg);
}

