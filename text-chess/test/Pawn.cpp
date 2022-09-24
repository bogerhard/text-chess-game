#include <string>
#include "gtest/gtest.h"
#include "Chess.h"
#include "TestEnvironment.h"

class PawnTest : public TestEnvironment {
};

TEST_F(PawnTest, oneSpaceValid) {
    Board board;
    Piece* pawnWhite = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2, a3));

    Piece* pawnBlack = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, a7);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, a7, a6));
}

TEST_F(PawnTest, backwards) {
    Board board;
    Piece* pawnWhite = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, a2, a1));


    Piece* pawnBlack = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, a7);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, a7, a8));
}

TEST_F(PawnTest, twoSpacesValid) {
    Board board;
    Piece* pawnWhite = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2, a4));

    Piece* pawnBlack = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, a7);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, a7, a5));
}

TEST_F(PawnTest, twoSpacesInvalid) {
    Board board;
    Piece* pawnWhite = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a3);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, a3, a5));

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, a6);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, a6, a4));
}

TEST_F(PawnTest, sideways) {
    Board board;
    Piece* pawnWhite = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, e5);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, f5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5, d5));
}

TEST_F(PawnTest, enPassantBlack) {
    Board board;

    // A-file
    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, b4);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2, a4));
    EXPECT_TRUE(board.movePiece(Colour::BLACK, b4, a3));
    EXPECT_EQ(Colour::NONE, board.getPiece(a4)->getSide());

    // C-file
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, c2);
    pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, b4);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, c2, c4));
    EXPECT_TRUE(board.movePiece(Colour::BLACK, b4, c3));
    EXPECT_EQ(Colour::NONE, board.getPiece(c4)->getSide());

    // H-file
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, h2);
    pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, g4);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, h2, h4));
    EXPECT_TRUE(board.movePiece(Colour::BLACK, g4, h3));
    EXPECT_EQ(Colour::NONE, board.getPiece(h4)->getSide());
}

TEST_F(PawnTest, enPassantWhite) {
    Board board;

    // A-file
    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, b5);

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, a7);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, a7, a5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, b5, a6));
    EXPECT_EQ(Colour::NONE, board.getPiece(a5)->getSide());

    // C-file
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, b5);
    pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, c7);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, c7, c5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, b5, c6));
    EXPECT_EQ(Colour::NONE, board.getPiece(c5)->getSide());

    // H-file
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, g5);
    pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, h7);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, h7, h5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, g5, h6));
    EXPECT_EQ(Colour::NONE, board.getPiece(h5)->getSide());
}

TEST_F(PawnTest, enPassantFail) {
    Board board;

    // White pawn already moved
    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, e3);

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, d4);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e3, e4));
    EXPECT_FALSE(board.movePiece(Colour::BLACK, d4, e3));
    Piece* pawn = dynamic_cast<Pawn*>(board.getPiece(e4));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(e4)->getSide());

    // Black pawn already moved
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, d5);
    pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, e6);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, e6,
                               e5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, d5,
                                e6));
    pawn = dynamic_cast<Pawn*>(board.getPiece(e5));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::BLACK, board.getPiece(e5)->getSide());
}

TEST_F(PawnTest, enPassantNotPawn) {
    Board board;

    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, g5);

    Piece* blackRook = new Rook(Colour::BLACK);
    board.placePiece(blackRook, f6);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, f6,
                               f5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, g5,
                                f6));
    Piece* rook = dynamic_cast<Rook*>(board.getPiece(f5));
    EXPECT_TRUE(rook != nullptr);
    EXPECT_EQ(Colour::BLACK, board.getPiece(f5)->getSide());

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, g4);

    Piece* whiteRook = new Rook(Colour::WHITE);
    board.placePiece(whiteRook, f3);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, f3, f4));
    EXPECT_FALSE(board.movePiece(Colour::BLACK, g4, f3));
    rook = dynamic_cast<Rook*>(board.getPiece(f4));
    EXPECT_TRUE(rook != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(f4)->getSide());
}

TEST_F(PawnTest, noForward) {
    Board board;

    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, e5);

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, e6);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                e6));
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e6,
                                e5));
}

TEST_F(PawnTest, promote) {
    Board board;

    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a7);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, a7,
                               a8));

    Pawn* pawn = dynamic_cast<Pawn*>(board.getPiece(a8));
    EXPECT_NE(nullptr, pawn);
    EXPECT_TRUE(pawn->promotable());

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, a2);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, a2,
                               a1));
    pawn = dynamic_cast<Pawn*>(board.getPiece(a1));
    EXPECT_NE(nullptr, pawn);
    EXPECT_TRUE(pawn->promotable());

    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, e5);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5,
                               e6));
    pawn = dynamic_cast<Pawn*>(board.getPiece(e6));
    EXPECT_NE(nullptr, pawn);
    EXPECT_FALSE(pawn->promotable());
}


TEST_F(PawnTest, takePieceWhite) {
    Board board;

    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);

    // King
    Piece* kingBlack  = new King(Colour::BLACK);
    board.placePiece(kingBlack, b3);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2,
                               b3));
    Piece* pawn = dynamic_cast<Pawn*>(board.getPiece(b3));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(b3)->getSide());

    // Queen
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);
    Piece* queenBlack  = new Queen(Colour::BLACK);
    board.placePiece(queenBlack, b3);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2,
                               b3));
    pawn = dynamic_cast<Pawn*>(board.getPiece(b3));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(b3)->getSide());

    // Bishop
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);
    Piece*bishopBlack  = new Bishop(Colour::BLACK);
    board.placePiece(bishopBlack, b3);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2,
                               b3));
    pawn = dynamic_cast<Pawn*>(board.getPiece(b3));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(b3)->getSide());

    // Knight
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);
    Piece* knightBlack = new Knight(Colour::BLACK);
    board.placePiece(knightBlack, b3);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2,
                               b3));
    pawn = dynamic_cast<Pawn*>(board.getPiece(b3));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(b3)->getSide());

    // Rook
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);
    Piece* rookBlack  = new Rook(Colour::BLACK);
    board.placePiece(rookBlack, b3);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2,
                               b3));
    pawn = dynamic_cast<Pawn*>(board.getPiece(b3));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(b3)->getSide());

    // Pawn
    pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, a2);
    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, b3);
    EXPECT_TRUE(board.movePiece(Colour::WHITE, a2,
                               b3));
    pawn = dynamic_cast<Pawn*>(board.getPiece(b3));
    EXPECT_TRUE(pawn != nullptr);
    EXPECT_EQ(Colour::WHITE, board.getPiece(b3)->getSide());
}


TEST_F(PawnTest, takePieceBlack) {
    Board board;

    Piece* pawnBlack  = new Pawn(Colour::BLACK);
    board.placePiece(pawnBlack, a7);

    Piece* pawnWhite  = new Pawn(Colour::WHITE);
    board.placePiece(pawnWhite, b6);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, a7,
                               b6));
    Piece* pawn = dynamic_cast<Pawn*>(board.getPiece(b6));
    EXPECT_TRUE(pawn != nullptr);

    EXPECT_EQ(Colour::BLACK, board.getPiece(b6)->getSide());
}
