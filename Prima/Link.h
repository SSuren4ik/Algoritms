#pragma once

struct Link {
    int src;
    int weight;
    Link* next;
    Link(int _src = 0, int _w = 0, Link* _n = nullptr) {
        src = _src;
        weight = _w;
        next = _n;
    }
    ~Link()
    {
        ;
    }
};