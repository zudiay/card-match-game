#ifndef Card_H
#define Card_H
#include <QPushButton>
#include <QPalette>

class Card : public QPushButton{
    Q_OBJECT

public:
    Card(const QString& text, QWidget* parent = 0);
    QString cardText;
    bool paired;
    bool open;

public slots:
    void openCard();
    void closeCard();
    void enableCard();
signals:
    void newCardOpened();
};

#endif // Card_H
