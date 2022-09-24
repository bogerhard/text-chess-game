#include <string>
#include "gtest/gtest.h"
#include "Chess.h"
#include "TestEnvironment.h"

class Movement : public TestEnvironment {
};

TEST_F(Movement, emptySpace) {
    Board board;

    EXPECT_THROW(board.movePiece(Colour::WHITE, e5,
                                 e6), no_piece_error);
}

TEST_F(Movement, initialSetupWhite) {
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour colour = Colour::WHITE;

    Piece* rook = dynamic_cast<Rook*>(board->getPiece(a1));
    EXPECT_TRUE(nullptr != rook);
    if (rook != nullptr) {
        EXPECT_EQ(colour, rook->getSide());
    }
    Piece* knight = dynamic_cast<Knight*>(board->getPiece(b1));
    EXPECT_TRUE(nullptr != knight);
    if (knight != nullptr) {
        EXPECT_EQ(colour, knight->getSide());
    }
    Piece* bishop = dynamic_cast<Bishop*>(board->getPiece(c1));
    EXPECT_TRUE(nullptr != bishop);
    if (bishop != nullptr) {
        EXPECT_EQ(colour, bishop->getSide());
    }
    Piece* queen = dynamic_cast<Queen*>(board->getPiece(d1));
    EXPECT_TRUE(nullptr != queen);
    if (queen != nullptr) {
        EXPECT_EQ(colour, queen->getSide());
    }
    Piece* king = dynamic_cast<King*>(board->getPiece(e1));
    EXPECT_TRUE(nullptr != king);
    if (king != nullptr) {
        EXPECT_EQ(colour, king->getSide());
    }
    rook = dynamic_cast<Rook*>(board->getPiece(h1));
    EXPECT_TRUE(nullptr != rook);
    if (rook != nullptr) {
        EXPECT_EQ(colour, rook->getSide());
    }
    knight = dynamic_cast<Knight*>(board->getPiece(g1));
    EXPECT_TRUE(nullptr != knight);
    if (knight != nullptr) {
        EXPECT_EQ(colour, knight->getSide());
    }
    bishop = dynamic_cast<Bishop*>(board->getPiece(f1));
    EXPECT_TRUE(nullptr != bishop);
    if (bishop != nullptr) {
        EXPECT_EQ(colour, bishop->getSide());
    }

    for (int i = 0; i < 8; ++i) {
        char column = 'A' + i;
        std::string s(1, column);
        s.append("2");
        Coordinate* c = new Coordinate(s);
        Piece* pawn = dynamic_cast<Pawn*>(board->getPiece(c));
        EXPECT_TRUE(nullptr != pawn);
        if (pawn != nullptr) {
            EXPECT_EQ(colour, pawn->getSide());
        }
        delete c;
    }
}

TEST_F(Movement, initialSetupBlack) {
    Chess game;
    game.setup();
    Board* board = game.getBoard();

    Colour colour = Colour::BLACK;

    Piece* rook = dynamic_cast<Rook*>(board->getPiece(a8));
    EXPECT_TRUE(nullptr != rook);
    if (rook != nullptr) {
        EXPECT_EQ(colour, rook->getSide());
    }
    Piece* knight = dynamic_cast<Knight*>(board->getPiece(b8));
    EXPECT_TRUE(nullptr != knight);
    if (knight != nullptr) {
        EXPECT_EQ(colour, knight->getSide());
    }
    Piece* bishop = dynamic_cast<Bishop*>(board->getPiece(c8));
    EXPECT_TRUE(nullptr != bishop);
    if (bishop != nullptr) {
        EXPECT_EQ(colour, bishop->getSide());
    }
    Piece* queen = dynamic_cast<Queen*>(board->getPiece(d8));
    EXPECT_TRUE(nullptr != queen);
    if (queen != nullptr) {
        EXPECT_EQ(colour, queen->getSide());
    }
    Piece* king = dynamic_cast<King*>(board->getPiece(e8));
    EXPECT_TRUE(nullptr != king);
    if (king != nullptr) {
        EXPECT_EQ(colour, king->getSide());
    }
    rook = dynamic_cast<Rook*>(board->getPiece(h8));
    EXPECT_TRUE(nullptr != rook);
    if (rook != nullptr) {
        EXPECT_EQ(colour, rook->getSide());
    }
    knight = dynamic_cast<Knight*>(board->getPiece(g8));
    EXPECT_TRUE(nullptr != knight);
    if (knight != nullptr) {
        EXPECT_EQ(colour, knight->getSide());
    }
    bishop = dynamic_cast<Bishop*>(board->getPiece(f8));
    EXPECT_TRUE(nullptr != bishop);
    if (bishop != nullptr) {
        EXPECT_EQ(colour, bishop->getSide());
    }

    for (int i = 0; i < 8; ++i) {
        char column = 'A' + i;
        std::string s(1, column);
        s.append("7");
        Coordinate* c = new Coordinate(s);
        Piece* pawn = dynamic_cast<Pawn*>(board->getPiece(c));
        EXPECT_TRUE(nullptr != pawn);
        if (pawn != nullptr) {
            EXPECT_EQ(colour, pawn->getSide());
        }
        delete c;
    }
}

TEST_F(Movement, notPlayers) {
    Board board;
    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, e5);

    EXPECT_THROW(board.movePiece(Colour::BLACK, e5, e6), invalid_piece_error);
}

TEST_F(Movement, offBoard) {
    Board board;
    Coordinate* rank = new Coordinate("I2");
    Coordinate* file = new Coordinate("A9");
    Piece* p = new Pawn(Colour::BLACK);
    EXPECT_THROW(board.placePiece(p, rank),
      invalid_location_error);
    EXPECT_THROW(board.placePiece(p, file),
      invalid_location_error);
    EXPECT_THROW(board.movePiece(Colour::BLACK, rank, a1),
      invalid_location_error);
    EXPECT_THROW(board.movePiece(Colour::BLACK, file, a1),
      invalid_location_error);
    delete rank;
    delete file;
    delete p;
}

TEST_F(Movement, illegalCoordiante) {
    EXPECT_THROW(new Coordinate("A12"), invalid_location_error);
}
