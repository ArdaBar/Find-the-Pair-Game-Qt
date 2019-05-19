#include "window.h"
#define SPACE 2 // macro for spacing between buttons
#define BSIZE 30 // macro for button size

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(8*(BSIZE+SPACE),9*(BSIZE+SPACE)); // set window size
    line = new QTextEdit("Tries:",this); 
    group = new QButtonGroup(this);
    r_button = new QPushButton("Reset",this);
    line->setGeometry(5,5,4*(BSIZE+SPACE),BSIZE);
    r_button->setGeometry(5+4*(BSIZE+SPACE),5,4*(BSIZE+SPACE),BSIZE);
    //thread = new QThread;
    for(int i=0; i<4; i++)
        for(int j=0; j<6; j++)
        {
            m_button[i][j] = new QPushButton("X", this);
            m_button[i][j]->setGeometry(5+j*(SPACE+BSIZE),3*BSIZE+i*(SPACE+BSIZE), BSIZE, BSIZE);
            group->addButton(m_button[i][j],6*i+j+1) ;
        }

    QObject::connect(group, SIGNAL(buttonClicked(int)), this, SLOT(slotButtonClicked(int)));
    QObject::connect(r_button, SIGNAL(clicked()), this, SLOT(reset()));

    reset();
}
