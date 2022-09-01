#ifndef MYSCORER_H
#define MYSCORER_H
#include <QTimer>
#include <QLabel>
#include <QMessageBox>

class myscorer: public QObject{
    Q_OBJECT
public:
    myscorer();
    QLabel *label;
    int counter;

public slots:
    void increaseScore();
    void reset();
};


#endif // MYSCORER_H
