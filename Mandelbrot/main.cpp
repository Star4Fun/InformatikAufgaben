#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QGraphicsView>
#include <QtWidgets>

#include <vec.h>
#include <mandelvec.h>
#include <cmath>

#include <Draw.h>

Draw *d;

int main(int argc, char *argv[])
{
    Vec test(0, 0);
    Vec b(8, 8);
    test.add(b);

    std::cout << "z" << test.z() << std::endl;

    std::cout << test.x << " " << test.y << std::endl;

    auto since_epoch = std::chrono::high_resolution_clock::now().time_since_epoch();

    long be = std::chrono::duration_cast<std::chrono::nanoseconds>(since_epoch).count();

    QApplication a(argc, argv);
    MainWindow w;
    d = new Draw(&w);
    d->grabKeyboard();

    std::cout << "begin" << be << std::endl;

    d->refreshMandel();

    since_epoch = std::chrono::high_resolution_clock::now().time_since_epoch();
    long en = std::chrono::duration_cast<std::chrono::nanoseconds>(since_epoch).count();

    std::cout << "end" << en << std::endl;

    double dur = ((en - be) / 1000000000.0);

    std::cout << "duration" << dur << std::endl;

    std::cout << d->getMandelVec().size() << std::endl;

    w.setWindowFlag(Qt::FramelessWindowHint, true);

    QImage image("/home/david/Desktop/test.jpg");

//    QGraphicsPixmapItem item(QPixmap::fromImage(image));

    d->setMinimumSize(QSize(d->fw, d->fh));
    w.layout()->addWidget(d);
    w.layout()->removeWidget(w.getUI()->graphicsView);

    QGraphicsScene scene;
//    scene.addText("Hello");
//    scene.addItem(&item);


    /*
    for(int i = 0; i < mandel.size(); i++) {
        MandelVec mv = mandel.at(i);
        Vec tmpVec = mv.getVec();
        int n = mv.getN();
        if(n != maxI) {
            int num = n % sizeof(colors[0]);
//            scene.setForegroundBrush(colors[num]);
        } else {
            scene.foregroundBrush().setColor(qRgb(0, 0, 255));
            scene.update();
//            scene.setForegroundBrush(QBrush(qRgb(0, 255, 255)));
            scene.addLine(tmpVec.x, tmpVec.y, tmpVec.x, tmpVec.y);
        }
    }
*/

//    item.setPos(0, 0);

    w.getUI()->graphicsView->setScene(&scene);

    w.show();

    return a.exec();
}
