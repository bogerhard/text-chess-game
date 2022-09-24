#include "gtest/gtest.h"
#include "Coordinate.h"

class TestEnvironment : public ::testing::Test {
 protected:
    TestEnvironment() {
        a1 = new Coordinate("A1");
        a2 = new Coordinate("A2");
        a3 = new Coordinate("A3");
        a4 = new Coordinate("A4");
        a5 = new Coordinate("A5");
        a6 = new Coordinate("A6");
        a7 = new Coordinate("A7");
        a8 = new Coordinate("A8");

        b1 = new Coordinate("B1");
        b2 = new Coordinate("B2");
        b3 = new Coordinate("B3");
        b4 = new Coordinate("B4");
        b5 = new Coordinate("B5");
        b6 = new Coordinate("B6");
        b7 = new Coordinate("B7");
        b8 = new Coordinate("B8");

        c1 = new Coordinate("C1");
        c2 = new Coordinate("C2");
        c3 = new Coordinate("C3");
        c4 = new Coordinate("C4");
        c5 = new Coordinate("C5");
        c6 = new Coordinate("C6");
        c7 = new Coordinate("C7");
        c8 = new Coordinate("C8");

        d1 = new Coordinate("D1");
        d3 = new Coordinate("D3");
        d4 = new Coordinate("D4");
        d5 = new Coordinate("D5");
        d6 = new Coordinate("D6");
        d7 = new Coordinate("D7");
        d8 = new Coordinate("D8");

        e1 = new Coordinate("E1");
        e2 = new Coordinate("E2");
        e3 = new Coordinate("E3");
        e4 = new Coordinate("E4");
        e5 = new Coordinate("E5");
        e6 = new Coordinate("E6");
        e7 = new Coordinate("E7");
        e8 = new Coordinate("E8");

        f1 = new Coordinate("F1");
        f3 = new Coordinate("F3");
        f4 = new Coordinate("F4");
        f5 = new Coordinate("F5");
        f6 = new Coordinate("F6");
        f7 = new Coordinate("F7");
        f8 = new Coordinate("F8");

        g1 = new Coordinate("G1");
        g2 = new Coordinate("G2");
        g3 = new Coordinate("G3");
        g4 = new Coordinate("G4");
        g5 = new Coordinate("G5");
        g6 = new Coordinate("G6");
        g7 = new Coordinate("G7");
        g8 = new Coordinate("G8");

        h1 = new Coordinate("H1");
        h2 = new Coordinate("H2");
        h3 = new Coordinate("H3");
        h4 = new Coordinate("H4");
        h5 = new Coordinate("H5");
        h6 = new Coordinate("H6");
        h7 = new Coordinate("H7");
        h8 = new Coordinate("H8");
    }

    ~TestEnvironment() {
        delete a1;
        delete a2;
        delete a3;
        delete a4;
        delete a5;
        delete a6;
        delete a7;
        delete a8;

        delete b1;
        delete b2;
        delete b3;
        delete b4;
        delete b5;
        delete b6;
        delete b7;
        delete b8;

        delete c1;
        delete c2;
        delete c3;
        delete c4;
        delete c5;
        delete c6;
        delete c7;
        delete c8;

        delete d1;
        delete d3;
        delete d4;
        delete d5;
        delete d6;
        delete d7;
        delete d8;

        delete e1;
        delete e2;
        delete e3;
        delete e4;
        delete e5;
        delete e6;
        delete e7;
        delete e8;

        delete f1;
        delete f3;
        delete f4;
        delete f5;
        delete f6;
        delete f7;
        delete f8;

        delete g1;
        delete g2;
        delete g3;
        delete g4;
        delete g5;
        delete g6;
        delete g7;
        delete g8;

        delete h1;
        delete h2;
        delete h3;
        delete h4;
        delete h5;
        delete h6;
        delete h7;
        delete h8;
    }

    Coordinate *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
    Coordinate *b1, *b2, *b3, *b4, *b5, *b6, *b7, *b8;
    Coordinate *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
    Coordinate *d1, *d3, *d4, *d5, *d6, *d7, *d8;
    Coordinate *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e8;
    Coordinate *f1, *f3, *f4, *f5, *f6, *f7, *f8;
    Coordinate *g1, *g2, *g3, *g4, *g5, *g6, *g7, *g8;
    Coordinate *h1, *h2, *h3, *h4, *h5, *h6, *h7, *h8;
};
