#include <string>
#include "gtest/gtest.h"
#include "Chess.h"
#include "TestEnvironment.h"

class KnightTest : public TestEnvironment {
};

TEST_F(KnightTest, verticalCorrect) {
    Board board;
    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, f7));

    knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, d7));

    knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, f3));

    knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               d3));
}

TEST_F(KnightTest, horizontalCorrect) {
    Board board;
    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, c4));

    knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, c6));

    knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, g4));

    knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               g6));
}

TEST_F(KnightTest, verticalIncorrect) {
    Board board;
    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                e1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                e8));
}


TEST_F(KnightTest, horizontalIncorrect) {
    Board board;
    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                a5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h5));
}

TEST_F(KnightTest, tooBigL) {
    Board board;
    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, g8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, c8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, g2));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, c2));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, b3));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, b7));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, h3));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, h7));
}

TEST_F(KnightTest, diagonal) {
    Board board;
    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e5);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, a1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, h8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, b8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, h2));
}
