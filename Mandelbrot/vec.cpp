#include "vec.h"
#include "cmath"

Vec::Vec() {
    this->x = 0;
    this->y = 0;
}

Vec::Vec(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vec::Vec(int x, int y)
{
    this->x = x;
    this->y = y;
}

Vec::Vec(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vec::Vec(Vec* vec)
{
    this->x = vec->x;
    this->y = vec->y;
}

Vec& Vec::add(Vec vec) {
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

Vec& Vec::sub(Vec vec) {
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

Vec& Vec::mul(Vec a) {
    this->x *= a.x;
    this->y *= a.y;

    return *this;
}

Vec& Vec::set(float x, float y) {
    this->x = x;
    this->y = y;
    return *this;
}

Vec Vec::copy() {
    return (*this);
}

float Vec::z() {
    return (float)sqrt(pow(this->x,2)+pow(this->y,2));
}

Vec& Vec::normalize(Vec min, Vec max) {
    this->x = (this->x-min.x)/(max.x-min.x);
    this->y = (this->y-min.y)/(max.y-max.y);
    return *this;
}

Vec Vec::normalize(Vec min, Vec max, Vec cur) {
    Vec tmp(cur);
    tmp.normalize(min, max);
    return tmp;
}
