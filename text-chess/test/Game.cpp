#include <string>
#include "gtest/gtest.h"
#include "Chess.h"
#include "TestEnvironment.h"

class Game : public TestEnvironment {
};


TEST_F(Game, foolsMate) {
    // See https://en.wikipedia.org/wiki/Fool%27s_mate

    std::string moves[] = {"F2", "F3", "E7", "E5", "G2", "G4", "D8", "H4"};
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour player = Colour::WHITE;
    unsigned int move = 0;
    do {
        Coordinate* start = new Coordinate(moves[move]);
        Coordinate* end = new Coordinate(moves[move+1]);

        EXPECT_TRUE(board->movePiece(player, start, end));
        player = (player == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
        move += 2;

        delete start;
        delete end;
    } while (move/2 < 4);

    EXPECT_TRUE(board->checkmate(Colour::WHITE));
}

TEST_F(Game, scholarsMate) {
    // See https://en.wikipedia.org/wiki/Scholar%27s_mate

    std::string moves[] = {"E2", "E4", "E7", "E5", "F1", "C4", "B8", "C6",
                           "D1", "H5", "G8", "F6", "H5", "F7"
                          };
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour player = Colour::WHITE;
    unsigned int move = 0;
    do {
        Coordinate* start = new Coordinate(moves[move]);
        Coordinate* end = new Coordinate(moves[move+1]);
        EXPECT_TRUE(board->movePiece(player, start, end));
        player = (player == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
        move += 2;

        delete start;
        delete end;
    } while (move/2 < 7);

    EXPECT_TRUE(board->checkmate(Colour::BLACK));
}


TEST_F(Game, borgsMate) {
    // See https://en.wikipedia.org/wiki/Checkmates_in_the_opening

    std::string moves[] = {"E2", "E4", "G7", "G5", "B1", "C3", "F7", "F5",
                           "D1", "H5", "G8", "F6", "H5", "F7"
                          };
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour player = Colour::WHITE;
    unsigned int move = 0;
    do {
        Coordinate* start = new Coordinate(moves[move]);
        Coordinate* end = new Coordinate(moves[move+1]);
        EXPECT_TRUE(board->movePiece(player, start, end));
        player = (player == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
        move += 2;

        delete start;
        delete end;
    } while (move/2 < 7);

    EXPECT_TRUE(board->checkmate(Colour::BLACK));
}

TEST_F(Game, indianMate) {
    // See https://en.wikipedia.org/wiki/Checkmates_in_the_opening

    std::string moves[] = {"D2", "D4", "G8", "F6", "B1", "D2", "E7", "E5",
                           "D4", "E5", "F6", "G4", "H2", "H3", "G4", "E3",
                           "F2", "E3", "D8", "H4", "G2", "G3", "H4", "G3"
                          };
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour player = Colour::WHITE;
    unsigned int move = 0;
    do {
        Coordinate* start = new Coordinate(moves[move]);
        Coordinate* end = new Coordinate(moves[move+1]);
        EXPECT_TRUE(board->movePiece(player, start, end));
        player = (player == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
        move += 2;

        delete start;
        delete end;
    } while (move/2 < 12);

    EXPECT_TRUE(board->checkmate(Colour::WHITE));
}


TEST_F(Game, blackburneTrap) {
    // See https://en.wikipedia.org/wiki/Checkmates_in_the_opening

    std::string moves[] = {"E2", "E4", "E7", "E5",
                           "G1", "F3", "B8", "C6",
                           "F1", "C4", "D7", "D6",
                           "B1", "C3", "C8", "G4",
                           "H2", "H3", "G4", "H5",
                           "F3", "E5", "H5", "D1",
                           "C4", "F7", "E8", "E7",
                           "C3", "D5"
                          };
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour player = Colour::WHITE;
    unsigned int move = 0;
    do {
        Coordinate* start = new Coordinate(moves[move]);
        Coordinate* end = new Coordinate(moves[move+1]);
        EXPECT_TRUE(board->movePiece(player, start, end));
        player = (player == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
        move += 2;

        delete start;
        delete end;
    } while (move/2 < 15);

    EXPECT_TRUE(board->checkmate(Colour::BLACK));
}

TEST_F(Game, kingsGambitAcceptedMate) {
    // See https://en.wikipedia.org/wiki/Checkmates_in_the_opening

    std::string moves[] = {"E2", "E4", "E7", "E5",
                           "F2", "F4", "E5", "F4",
                           "B2", "B3", "D8", "H4",
                           "G2", "G3", "F4", "G3",
                           "H2", "H3", "G3", "G2",
                           "E1", "E2", "H4", "E4",
                           "E2", "F2", "G2", "H1"
                          };
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour player = Colour::WHITE;
    unsigned int move = 0;
    do {
        Coordinate* start = new Coordinate(moves[move]);
        Coordinate* end = new Coordinate(moves[move+1]);
        EXPECT_TRUE(board->movePiece(player, start, end));
        player = (player == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
        move += 2;

        delete start;
        delete end;
    } while (move/2 < 14);

    Pawn* pawn = dynamic_cast<Pawn*>(board->getPiece(h1));
    EXPECT_NE(nullptr, pawn);
    EXPECT_TRUE(pawn->promotable());
    board->placePiece(new Knight(Colour::BLACK), h1);

    EXPECT_TRUE(board->checkmate(Colour::WHITE));
}
