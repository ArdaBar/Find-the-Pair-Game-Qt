#ifndef WINDOW_H
#define WINDOW_H
#include <QPushButton>
#include <QButtonGroup>
#include <QTextEdit>
#include <QTest>
#include <QWidget>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    QPushButton *m_button[4][6]; // matching pairs
    QPushButton *r_button; // reset button
    QTextEdit *line; // text area
    QButtonGroup *group; // button group
    int tries; // no of tries
    int pairs; // no of found pairs
    int open_letter,open_id; // last opened letter and its id in buttongroup
    bool is_open=false; // is a letter open?
    char table[4][6]; // table of real values of elements

signals:

public slots:
    void slotButtonClicked(int id)
    {
        tries++;
        int i,j;
        i = (id-1)/6;
        j = (id-1)%6;
        m_button[i][j]->setText(QString(table[i][j]));

        if(!is_open)
        {
            open_letter = table[i][j];
            open_id = id;
            line->setText("Tries:"+QString::number(tries)+"  Pairs:"+QString::number(pairs));
        }

        else if(is_open)
        {
            if(open_letter==table[i][j])
            {
                pairs++;
                line->setText("Tries:"+QString::number(tries)+"  Pairs:"+QString::number(pairs));
                QTest::qWait(500);
                group->button(id)->setDisabled(true);
                group->button(id)->setVisible(false);
                group->button(open_id)->setDisabled(true);
                group->button(open_id)->setVisible(false);

            }
            else
            {
                line->setText("Tries:"+QString::number(tries)+"  Pairs:"+QString::number(pairs));
                QTest::qWait(500);
                m_button[i][j]->setText("X");
                m_button[(open_id-1)/6][(open_id-1)%6]->setText("X");
            }

        }


        if(is_open)
            is_open=false;
        else
            is_open=true;


        line->setText("Tries:"+QString::number(tries)+"  Pairs:"+QString::number(pairs));
    }

    void reset()
    {
        open_letter = tries = pairs = 0;
        is_open = false;
        srand(time(NULL));
        int ra;
        bool is[24];

        for(int i=0; i<24; i++)
            is[i]=false;
        for(char ka='A'; ka<'A'+12; ka++)
        for(int sifirbir=0; sifirbir<2; sifirbir++)
        {
            ra=rand()%24;
            int curs=0;
            for(int i=ra; i>0; i--)
            {
                curs++;
                curs%=24;
                while(is[curs])
                {
                    curs++;
                    curs%=24;
                }
            }
            is[curs]=true;
            table[curs/6][curs%6]=ka;
            m_button[curs/6][curs%6]->setDisabled(false);
            m_button[curs/6][curs%6]->setVisible(true);
            m_button[curs/6][curs%6]->setText(QString(table[curs/6][curs%6]));
        }

        QTest::qWait(2000);
        for(int i=0; i<4; i++)
            for(int j=0; j<6; j++)
            {
                m_button[i][j]->setText("X");
            }
    }
};

#endif // WINDOW_H
