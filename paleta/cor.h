#ifndef COR_H
#define COR_H

struct Cor {
    int r;
    int g;
    int b;

    Cor() : r(0), g(0), b(0) {}

    Cor(int rr, int gg, int bb) : r(rr), g(gg), b(bb) {}
};

#endif
