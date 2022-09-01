#include "myScorer.h"

myscorer::myscorer(){
    label = new QLabel("Score: 0");
    counter = 0;
}

void myscorer::increaseScore(){
    counter += 1;
    label->setText("Score: "+ QString::number(this->counter));
}

void myscorer::reset(){
    this->counter = 0;
    this->label->setText("Score: "+ QString::number(this->counter));

}
