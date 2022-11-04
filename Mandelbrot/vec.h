#ifndef VEC_H
#define VEC_H


class Vec
{
public:
    Vec();
    Vec(float x, float y);
    Vec(int x, int y);
    Vec(Vec* vec);
    Vec(double x, double y);
    float x;
    float y;
    Vec& add(Vec vec);
    Vec& sub(Vec vec);
    Vec& mul(Vec vec);
    Vec& normalize(Vec min, Vec max);
    Vec& set(float x, float y);
    Vec copy();
    static Vec normalize(Vec min, Vec max, Vec cur);
    float z();
};

#endif // VEC_H
