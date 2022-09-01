#include <QApplication>
#include "card.h"
#include "myTimer.h"
#include "mygrid.h"
#include "myScorer.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget *cw = new QWidget;
    MyTimer *mt= new MyTimer();
    MyGrid *gl = new MyGrid(mt->timer);
    myscorer *ms = new myscorer();
    QObject::connect(gl, SIGNAL(paired()),  ms, SLOT(increaseScore())); // if a pair is matched, increase the score
    QObject::connect(mt, SIGNAL(timerunout()), gl, SLOT(endgame()));    // if time limit is exceeded, end the game
    gl->createNew();

    // Initialize and adjust New Game and Quit Buttons
    QPalette pal;
    pal.setColor(QPalette::Button, QColor(Qt::darkGray));
    pal.setColor(QPalette::ButtonText, QColor(Qt::white));
    QPushButton *newGame = new QPushButton("New Game");
    QPushButton *quit = new QPushButton("Quit");
    newGame->setPalette(pal);
    newGame->setAutoFillBackground(true);
    newGame->setFlat(true);
    quit->setPalette(pal);
    quit->setFlat(true);
    quit->setAutoFillBackground(true);
    QObject:: connect(newGame, SIGNAL(clicked()), gl, SLOT(createNew()));   // create new game layout
    QObject:: connect(newGame, SIGNAL(clicked()), mt, SLOT(reset()));       // reset the game timer
    QObject:: connect(newGame, SIGNAL(clicked()), ms, SLOT(reset()));       // reset the game score
    QObject:: connect(quit, SIGNAL(clicked()), &app, SLOT(quit()));         // quit the application

    // Initialize and adjust widgets that show time and score
    QPalette pal2;
    pal2.setColor(QPalette::Window, QColor(Qt::darkGray));
    pal2.setColor(QPalette::WindowText, QColor(Qt::white));
    QWidget *timerwidget = mt->label;
    timerwidget->setPalette(pal2);
    timerwidget->setAutoFillBackground(true);
    QWidget *scorerwidget = ms->label;
    scorerwidget->setPalette(pal2);
    scorerwidget->setAutoFillBackground(true);

    // form grid layout
    QGridLayout *maingrid = new QGridLayout();
    maingrid->addWidget(timerwidget,0,0,1,1);
    maingrid->addWidget(scorerwidget,0,1,1,1);
    maingrid->addWidget(newGame,0,4,1,1);
    maingrid->addWidget(quit,0,5,1,1);
    maingrid->addLayout(gl,5,0,1,6);
    cw->setMinimumWidth(800);
    cw->setMaximumHeight(500);
    cw->setMaximumWidth(1000);
    cw->setLayout(maingrid);

    // adjust the central widget
    QPalette pal3;
    pal3.setColor(QPalette::Background, Qt::white);
    cw->setAutoFillBackground(true);
    cw->setPalette(pal3);
    cw->setWindowTitle("Card Match Game");
    cw->resize(800, 400);
    cw->show();

    return app.exec();
}
