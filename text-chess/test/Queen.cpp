#include <string>
#include "gtest/gtest.h"
#include "Chess.h"
#include "TestEnvironment.h"

class QueenTest : public TestEnvironment {
};

TEST_F(QueenTest, horizontal) {
    Board board;
    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               a5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a5,
                               h5));
}

TEST_F(QueenTest, vertical) {
    Board board;
    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               e1));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e1,
                               e8));
}

TEST_F(QueenTest, diagonal) {
    Board board;
    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               a1));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a1,
                               e5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               h8));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, h8,
                               e5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               b8));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, b8,
                               e5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               h2));
}

TEST_F(QueenTest, pathNotClearHorizontal) {
    Board board;
    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, e5);

    Piece*bishop = new Bishop(Colour::BLACK);
    board.placePiece(bishop, b5);
    bishop = new Bishop(Colour::BLACK);
    board.placePiece(bishop, g5);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                a5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h5));
}

TEST_F(QueenTest, pathNotClearVertical) {
    Board board;
    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, e5);

    Piece*bishop = new Bishop(Colour::BLACK);
    board.placePiece(bishop, e2);
    bishop = new Bishop(Colour::BLACK);
    board.placePiece(bishop, e7);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, e1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, e8));
}

TEST_F(QueenTest, pathNotClearDiagonal) {
    Board board;
    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, e5);

    Piece* rook = new Rook(Colour::BLACK);
    board.placePiece(rook, b2);
    rook = new Rook(Colour::BLACK);
    board.placePiece(rook, c7);
    rook = new Rook(Colour::BLACK);
    board.placePiece(rook, g7);
    rook = new Rook(Colour::BLACK);
    board.placePiece(rook, g3);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                b8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h2));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                a1));
}
