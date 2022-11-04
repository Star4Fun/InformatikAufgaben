#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

#include <iostream>
#include <mandelvec.h>

/*
class Draw
{
public:
    Draw();
};
*/

const std::vector<QColor> colors = {
    Qt::green,
    Qt::yellow,
    Qt::red,
    Qt::magenta,
    Qt::lightGray,
    Qt::gray,
    Qt::darkYellow,
    Qt::darkBlue,
    Qt::blue,
    Qt::darkCyan,
    Qt::cyan,
    Qt::darkGreen,
    Qt::darkRed
};

class Draw: public QWidget {
    Q_OBJECT

    public:
        Draw(QWidget *parent = 0): QWidget(parent) {};
        void setMandelVec(std::vector<MandelVec> vec);
        std::vector<MandelVec>& getMandelVec();
        const float fw = 1280, fh = 720;

        Vec zoom = Vec(1, 1);
        Vec offset = Vec(0, 0);

        Vec begin = Vec(-2.02, -1.2);
        Vec end = Vec(0.7, 1.2);

        const Vec orgBegin = Vec(-2.02, -1.2);
        const Vec orgEnd = Vec(0.7, 1.2);
        const int maxI = 500;

        int iter(Vec c);
        std::vector<MandelVec> getMandel(Vec min, Vec max);
        void refreshMandel();
    protected:
        std::vector<MandelVec> vec;
        void paintEvent(QPaintEvent *) {
            QPainter p(this);


            QPen pen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap);
            p.setPen(pen);

            for(unsigned long i = 0; i < vec.size(); i++) {
                MandelVec mv = vec.at(i);
                Vec tmp = mv.getVec();

                if(mv.getN() == maxI) {
                    p.setPen(Qt::black);
                } else {
                    p.setPen(colors.at(mv.getN() % colors.size()));
                }
                p.drawPoint(tmp.x, tmp.y);
            }

        }
        void keyPressEvent(QKeyEvent *event) {
            if(event->key() == Qt::Key_Plus) {
                std::cout << "Plus" << std::endl;
                zoom.add(Vec(0.1, 0.1));
                refreshMandel();
            } else if(event->key() == Qt::Key_Minus) {
                    std::cout << "Minus" << std::endl;
                    zoom.add(Vec(-0.1, -0.1));
                    refreshMandel();
            }

            if(event->key() == Qt::Key_Up) {
                std::cout << "Up" << std::endl;
                offset.add(Vec(0.0, -0.3));
                refreshMandel();
            } else if(event->key() == Qt::Key_Down) {
                    std::cout << "Down" << std::endl;
                    offset.add(Vec(0.0, 0.3));
                    refreshMandel();
            } else if(event->key() == Qt::Key_Left) {
                std::cout << "Left" << std::endl;
                offset.add(Vec(0.3, 0.0));
                refreshMandel();
            } else if(event->key() == Qt::Key_Right) {
                    std::cout << "Right" << std::endl;
                    offset.add(Vec(-0.3, 0.0));
                    refreshMandel();
            }
            this->repaint();

            if(event->key() == Qt::Key_Escape) {
                std::exit(0);
            }
        }
};



#endif // DRAW_H
