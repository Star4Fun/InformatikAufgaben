#include "Draw.h"
#include <cmath>

void Draw::setMandelVec(std::vector<MandelVec> vec) {
    this->vec = vec;
}

std::vector<MandelVec>& Draw::getMandelVec() {
    return this->vec;
}

int Draw::iter(Vec c) {
    float zx = 0, zy = 0;
    int i = 0;
    do {
        float tmp = (float)(pow(zx, 2) - pow(zy, 2) + c.x);
        zy = 2.0f * zx * zy + c.y;
        zx = tmp;
        i++;
    } while(((pow(zx, 2) + pow(zy, 2)) <= 4) && (i < maxI));
    return i;
}

std::vector<MandelVec> Draw::getMandel(Vec min, Vec max) {
    std::cout << min.x << " " << min.y << std::endl;
    min = min.sub(offset);
    max = max.sub(offset);
    min = min.mul(zoom);
    max = max.mul(zoom);
    std::cout << min.x << " " << min.y << std::endl;

    float deltaX = (max.x-min.x)/(fw-1);
    float deltaY = (max.y-min.y)/(fh-1);

    std::vector<MandelVec> almv;
    almv.reserve(fw*fh);

    Vec c(min.x, min.y);

    Vec tmpVec;

    for(int spalte = 0; spalte < fw; spalte++) {
        c.set(c.x, max.y);
        for(int zeile = 0; zeile < fh; zeile++) {
            int i = iter(c);

            if(i == maxI) {
                tmpVec.set(spalte, zeile);
                almv.push_back(MandelVec(i, &tmpVec));
            }  else {
                tmpVec.set(spalte, zeile);
                almv.push_back(MandelVec(i, &tmpVec));
            }
            c.set(c.x, c.y - deltaY);
        }
        c.set(c.x, 0.0f);
        int i = iter(c);
        if(i == maxI) {
            tmpVec.set(spalte, 0);
            almv.push_back(MandelVec(i, &tmpVec));
        } else {
            tmpVec.set(spalte, 0);
            almv.push_back(MandelVec(i, &tmpVec));
        }

        c.set(c.x + deltaX, c.y);
    }

    return almv;
}

void Draw::refreshMandel() {
    this->setMandelVec(getMandel(begin, end));
    begin = orgBegin;
    end = orgEnd;
}
