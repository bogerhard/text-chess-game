#include <string>
#include "TestEnvironment.h"
#include "Chess.h"

class BishopTest : public TestEnvironment {
};

TEST_F(BishopTest, horizontal) {
    Board board;
    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, e5);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, a5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, h5));
}

TEST_F(BishopTest, vertical) {
    Board board;
    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, e5);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, e1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, e8));
}

TEST_F(BishopTest, diagonal) {
    Board board;
    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, a1));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a1, e5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, h8));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, h8, e5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, b8));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, b8, e5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, h2));
}

TEST_F(BishopTest, pathNotClear) {
    Board board;
    Piece* bishop = new Bishop(Colour::WHITE);

    board.placePiece(bishop, e5);

    Piece* rook1 = new Rook(Colour::BLACK);
    board.placePiece(rook1, c7);
    Piece* rook2 = new Rook(Colour::BLACK);
    board.placePiece(rook2, g7);
    Piece* rook3 = new Rook(Colour::BLACK);
    board.placePiece(rook3, b2);
    Piece* rook4 = new Rook(Colour::BLACK);
    board.placePiece(rook4, g3);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, b8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, h8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, a1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, h2));
}
