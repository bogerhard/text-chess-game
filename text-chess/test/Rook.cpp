#include <string>
#include "gtest/gtest.h"
#include "Chess.h"
#include "TestEnvironment.h"

class RookTest : public TestEnvironment {
};

TEST_F(RookTest, horizontal) {
    Board* board = new Board(2);
    Piece* rook  = new Rook(Colour::WHITE);
    board->placePiece(rook, a1);

    EXPECT_TRUE(board->movePiece(Colour::WHITE, a1,
                               b1));
    EXPECT_TRUE(board->movePiece(Colour::WHITE, b1,
                               a1));
    delete board;
}

TEST_F(RookTest, vertical) {
    Board board;
    Piece* rook  = new Rook(Colour::WHITE);
    board.placePiece(rook, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               e1));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e1,
                               e8));
}

TEST_F(RookTest, diagonal) {
    Board board;
    Piece* rook = new Rook(Colour::WHITE);
    board.placePiece(rook, e5);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                a1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                b8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h2));
}

TEST_F(RookTest, pathNotClearHorizontal) {
    Board board;
    Piece* rook = new Rook(Colour::WHITE);
    board.placePiece(rook, e5);

    Piece* bishop1 = new Bishop(Colour::BLACK);
    board.placePiece(bishop1, b5);
    Piece* bishop2 = new Bishop(Colour::BLACK);
    board.placePiece(bishop2, g5);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                a5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h5));
}

TEST_F(RookTest, pathNotClearVertical) {
    Board board;
    Piece* rook = new Rook(Colour::WHITE);
    board.placePiece(rook, e5);

    Piece* bishop1 = new Bishop(Colour::BLACK);
    board.placePiece(bishop1, e2);
    Piece* bishop2 = new Bishop(Colour::BLACK);
    board.placePiece(bishop2, e7);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                e1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                e8));
}
