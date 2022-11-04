#include "mandelvec.h"

MandelVec::MandelVec() {
    this->n = 0;
    this->vec = Vec(0, 0);
}

MandelVec::MandelVec(int ni, Vec* vect) {
    this->n = ni;
    this->vec.set(vect->x, vect->y);
}

int MandelVec::getN() {
    return this->n;
}

Vec MandelVec::getVec() {
    return this->vec;
}
