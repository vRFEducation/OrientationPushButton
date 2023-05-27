#include "OrinetationPushButton.h"

#include <QStyleOptionButton>
#include <QStylePainter>

OrinetationPushButton::OrinetationPushButton(QWidget *parent) :
    QPushButton("Button", parent)
{
}

OrinetationPushButton::OrinetationPushButton(QString &text, QWidget *parent):
    QPushButton(text, parent)
{

}

OrinetationPushButton::OrinetationPushButton(QIcon icon, QString &text, QWidget *parent):
        QPushButton(icon, text, parent)
{

}

OrinetationPushButton::Orientation OrinetationPushButton::orientation() const
{
    return mOrientation;
}

void OrinetationPushButton::setOrientation(Orientation newOrientation)
{

    if (mOrientation == newOrientation)
        return;
    auto prevOrientation = mOrientation;
    mOrientation = newOrientation;
    if (newOrientation == Horizontal ||
            ((newOrientation == VerticalBottomToTop || newOrientation == VerticalTopToBottom) && prevOrientation == Horizontal)){
        resize(height(), width());
    }
    repaint();
}

QSize OrinetationPushButton::sizeHint() const
{
    auto sh = QPushButton::sizeHint();
    if (mOrientation != Horizontal) {
        sh.transpose();
    }
    return sh;
}

void OrinetationPushButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStylePainter painter(this);
    QStyleOptionButton option;
    initStyleOption(&option);

    if (mOrientation == VerticalTopToBottom) {
        painter.rotate(90);
        painter.translate(0, width() * -1);
        option.rect = option.rect.transposed();
    } else     if (mOrientation == VerticalBottomToTop) {
        painter.rotate(-90);
        painter.translate(-1 * height() , 0);
        option.rect = option.rect.transposed();
    }
    painter.drawControl(QStyle::CE_PushButton, option);
}

