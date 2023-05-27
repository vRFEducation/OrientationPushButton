#ifndef ORINETATIONPUSHBUTTON_H
#define ORINETATIONPUSHBUTTON_H

#include <QPushButton>

class OrinetationPushButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(Orientation orientation READ orientation WRITE setOrientation )
public:
    enum Orientation{
        Horizontal,
        VerticalTopToBottom,
        VerticalBottomToTop
    };
    Q_ENUM(Orientation)
    OrinetationPushButton(QWidget *parent = 0);
    OrinetationPushButton(QString &text, QWidget *parent = 0);
    OrinetationPushButton(QIcon icon, QString &text,QWidget *parent = 0);

    Orientation orientation() const;
    void setOrientation(Orientation newOrientation);

    QSize sizeHint()const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    Orientation mOrientation = Horizontal;

};

#endif // ORINETATIONPUSHBUTTON_H
