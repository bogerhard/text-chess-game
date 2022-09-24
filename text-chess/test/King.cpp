#include <string>
#include "gtest/gtest.h"
#include "Chess.h"
#include "TestEnvironment.h"

class KingTest : public TestEnvironment {
};

TEST_F(KingTest, horizontal) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, f5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, f5, e5));
} // Horizontal


TEST_F(KingTest, vertical) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, e4));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e4, e5));
} // Vertical

TEST_F(KingTest, diagonal) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e5);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, d4));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, d4, e5));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, e5, d6));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, d6, e5));
} // Diagonal

TEST_F(KingTest, tooFar) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e5);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                a1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                b8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h2));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                e1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                e8));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                a5));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e5,
                                h5));
} // Too Far

TEST_F(KingTest, castleQueensideWhite) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e1);

    Piece* rookWhite  = new Rook(Colour::WHITE);
    board.placePiece(rookWhite, a1);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e1, c1));

    Piece* king = dynamic_cast<King*>(board.getPiece(c1));
    EXPECT_TRUE(king != nullptr);

    Piece* rook = dynamic_cast<Rook*>(board.getPiece(d1));
    EXPECT_TRUE(rook != nullptr);

    EXPECT_EQ(Colour::NONE, board.getPiece(a1)->getSide());
}

TEST_F(KingTest, castleQueensideWhiteFail) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e1);

    Piece* rookWhite  = new Rook(Colour::WHITE);
    board.placePiece(rookWhite, a1);

    // Black Rook
    Piece* rookBlack  = new Rook(Colour::BLACK);
    board.placePiece(rookBlack, c8);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                c1));
    Piece* king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    Piece* rook = dynamic_cast<Rook*>(board.getPiece(a1));
    EXPECT_TRUE(rook != nullptr);
     board.emptySpace(b8);

    // Black Bishop
    Piece* blackBishop  = new Bishop(Colour::BLACK);
    board.placePiece(blackBishop, h6);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                c1));
    king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(a1));
    EXPECT_TRUE(rook != nullptr);

    board.emptySpace(h6);

    // Black Knight
    Piece* blackKnight  = new Knight(Colour::BLACK);
    board.placePiece(blackKnight, f3);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                c1));
    king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(a1));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(f3);

    // Black Pawn
    Piece* blackPawn  = new Pawn(Colour::BLACK);
    board.placePiece(blackPawn, c2);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                c1));
    king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(a1));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(c2);
}

TEST_F(KingTest, castleKingsideWhite) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e1);

    Piece* rookWhite  = new Rook(Colour::WHITE);
    board.placePiece(rookWhite, h1);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e1, g1));

    Piece* king = dynamic_cast<King*>(board.getPiece(g1));
    EXPECT_TRUE(king != nullptr);

    Piece* rook = dynamic_cast<Rook*>(board.getPiece(f1));
    EXPECT_TRUE(rook != nullptr);

    EXPECT_EQ(Colour::NONE, board.getPiece(h1)->getSide());
}

TEST_F(KingTest, castleKingsideWhiteFail) {
    Board board;

    Piece* kingWhite  = new King(Colour::WHITE);
    board.placePiece(kingWhite, e1);

    Piece* rookWhite  = new Rook(Colour::WHITE);
    board.placePiece(rookWhite, h1);

    // Black Rook
    Piece* rookBlack  = new Rook(Colour::BLACK);
    board.placePiece(rookBlack, f8);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                g1));
    Piece* king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    Piece* rook = dynamic_cast<Rook*>(board.getPiece(h1));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(f8);

    // Black Bishop
    Piece* blackBishop  = new Bishop(Colour::BLACK);
    board.placePiece(blackBishop, d4);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                g1));
    king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(h1));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(d4);

    // Black Knight
    Piece* blackKnight  = new Knight(Colour::BLACK);
    board.placePiece(blackKnight, f3);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                g1));
    king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(h1));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(f3);

    // Black Pawn
    Piece* blackPawn  = new Pawn(Colour::BLACK);
    board.placePiece(blackPawn, g2);

    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                g1));
    king = dynamic_cast<King*>(board.getPiece(e1));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(h1));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(g2);
}

TEST_F(KingTest, castleQueenSideBlack) {
    Board board;

    Piece* king  = new King(Colour::BLACK);
    board.placePiece(king, e8);

    Piece* rook  = new Rook(Colour::BLACK);
    board.placePiece(rook, a8);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, e8, c8));

    king = dynamic_cast<King*>(board.getPiece(c8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(d8));
    EXPECT_TRUE(rook != nullptr);
    EXPECT_EQ(Colour::NONE, board.getPiece(a8)->getSide());
}

TEST_F(KingTest, castleQueensideBlackFail) {
    Board board;


    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, e8);

    Piece* rook = new Rook(Colour::BLACK);
    board.placePiece(rook, a8);

    // White Rook
    Piece* rookWhite = new Rook(Colour::WHITE);
    board.placePiece(rookWhite, c1);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                c8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(a8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(c1);

    // White Bishop
    Piece* whiteBishop = new Bishop(Colour::WHITE);
    board.placePiece(whiteBishop, h3);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                c8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(a8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(f1);

    // White Knight
    Piece* whiteKnight = new Knight(Colour::WHITE);
    board.placePiece(whiteKnight, f6);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                c8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(a8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(f6);

    // White Pawn
    Piece* whitePawn = new Pawn(Colour::WHITE);
    board.placePiece(whitePawn, c7);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                c8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(a8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(c7);
}

TEST_F(KingTest, castleKingSideBlack) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, e8);

    Piece* rook  = new Rook(Colour::BLACK);
    board.placePiece(rook, h8);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, e8, g8));

    king = dynamic_cast<King*>(board.getPiece(g8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(f8));
    EXPECT_TRUE(rook != nullptr);
    EXPECT_EQ(Colour::NONE, board.getPiece(h8)->getSide());
}

TEST_F(KingTest, castleKingsideBlackFail) {
    Board board;


    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, e8);

    Piece* rook = new Rook(Colour::BLACK);
    board.placePiece(rook, h8);

    // White Rook
    Piece* rookWhite = new Rook(Colour::WHITE);
    board.placePiece(rookWhite, c8);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                g8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(h8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(c8);

    // White Bishop
    Piece* whiteBishop = new Bishop(Colour::WHITE);
    board.placePiece(whiteBishop, d6);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                g8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(h8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(d6);

    // White Knight
    Piece* whiteKnight = new Knight(Colour::WHITE);
    board.placePiece(whiteKnight, f6);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                g8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(h8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(f6);

    // White Pawn
    Piece* whitePawn = new Pawn(Colour::WHITE);
    board.placePiece(whitePawn, h7);

    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8,
                                g8));
    king = dynamic_cast<King*>(board.getPiece(e8));
    EXPECT_TRUE(king != nullptr);

    rook = dynamic_cast<Rook*>(board.getPiece(h8));
    EXPECT_TRUE(rook != nullptr);
    board.emptySpace(h7);
}

TEST_F(KingTest, castleKingMovedBlack) {
    Board board;
    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, e8);

    EXPECT_TRUE(board.movePiece(Colour::BLACK, e8, d8));
    EXPECT_TRUE(board.movePiece(Colour::BLACK, d8, e8));

    // Castle
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8, c8));
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e8, g8));
}

TEST_F(KingTest, castleKingMovedWhite) {
    Board board;
    Piece* king = new King(Colour::WHITE);
    board.placePiece(king, e1);

    EXPECT_TRUE(board.movePiece(Colour::WHITE, e1,
                               d1));
    EXPECT_TRUE(board.movePiece(Colour::WHITE, d1,
                               e1));

    // Castle
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                c1));
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e1,
                                g1));
}

TEST_F(KingTest, checkBlack) {
    Board board;



    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, e6);

    Piece* whiteQueen = new Queen(Colour::WHITE);
    board.placePiece(whiteQueen, g3);
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e6, e5));
    board.emptySpace(g3);

    Piece* whiteBishop = new Bishop(Colour::WHITE);
    board.placePiece(whiteBishop, g7);
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e6, e5));
    board.emptySpace(g7);

    Piece* whiteKnight = new Knight(Colour::WHITE);
    board.placePiece(whiteKnight, g6);
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e6, e5));
    board.emptySpace(g6);

    Piece* whiteRook = new Rook(Colour::WHITE);
    board.placePiece(whiteRook, b5);
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e6, e5));
    board.emptySpace(b5);

    Piece* whitePawn = new Pawn(Colour::WHITE);
    board.placePiece(whitePawn, d4);
    EXPECT_FALSE(board.movePiece(Colour::BLACK, e6, e5));
    board.emptySpace(d4);
} // Check-Black


TEST_F(KingTest, checkWhite) {
    Board board;

    Piece* king = new King(Colour::WHITE);
    board.placePiece(king, e6);

    Piece* blackQueen = new Queen(Colour::BLACK);
    board.placePiece(blackQueen, g3);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e6, e5));
    board.emptySpace(g3);

    Piece* blackBishop = new Bishop(Colour::BLACK);
    board.placePiece(blackBishop, g7);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e6,
                                e5));
    board.emptySpace(g7);

    Piece* blackKnight = new Knight(Colour::BLACK);
    board.placePiece(blackKnight, g6);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e6,
                                e5));
    board.emptySpace(g6);

    Piece* blackRook = new Rook(Colour::BLACK);
    board.placePiece(blackRook, b5);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e6,
                                e5));
    board.emptySpace(b5);

    Piece* blackPawn = new Pawn(Colour::BLACK);
    board.placePiece(blackPawn, d6);
    EXPECT_FALSE(board.movePiece(Colour::WHITE, e6,
                                e5));
    board.emptySpace(d6);
} // Check-White

TEST_F(KingTest, checkmateTwoRooks) {
    Board board;

    Piece* king = new King(Colour::WHITE);
    board.placePiece(king, h8);

    Piece* rook = new Rook(Colour::BLACK);
    board.placePiece(rook, a8);
    rook = new Rook(Colour::BLACK);
    board.placePiece(rook, b7);

    EXPECT_TRUE(board.checkmate(Colour::WHITE));
}

TEST_F(KingTest, checkmateQueenKnight) {
    Board board;
    Piece* king = new King(Colour::WHITE);
    board.placePiece(king, h8);

    Piece* queen = new Queen(Colour::BLACK);
    board.placePiece(queen, g7);

    Piece* knight = new Knight(Colour::BLACK);
    board.placePiece(knight, e8);

    EXPECT_TRUE(board.checkmate(Colour::WHITE));
}

TEST_F(KingTest, checkmateTwoPawnKing) {
    Board board;
    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, e8);

    Piece* pawn = new Pawn(Colour::WHITE);
    board.placePiece(pawn, e7);
    pawn = new Pawn(Colour::WHITE);
    board.placePiece(pawn, d7);

    Piece* kingWhite = new King(Colour::WHITE);
    board.placePiece(kingWhite, e6);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateBackRank) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, g8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, f7);
    pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, g7);
    pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, h7);

    Piece* rook = new Rook(Colour::WHITE);
    board.placePiece(rook, a8);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateDiagonal) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, g8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, e7);
    pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, h7);

    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, g7);

    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, a1);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateSmothered) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, h8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, h7);
    pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, g7);

    Piece* rook  = new Rook(Colour::BLACK);
    board.placePiece(rook, g8);

    Piece* knight  = new Knight(Colour::WHITE);
    board.placePiece(knight, f7);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateBishopKnight) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, g8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, f7);
    pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, h7);

    Piece* rook = new Rook(Colour::BLACK);
    board.placePiece(rook, f8);

    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, h6);

    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, f6);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateKnightRook) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, h7);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, g7);

    Piece* knight = new Knight(Colour::WHITE);
    board.placePiece(knight, e7);

    Piece* rook = new Rook(Colour::WHITE);
    board.placePiece(rook, h5);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateQueenBishop) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, g8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, f7);
    pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, h7);

    Piece* rook = new Rook(Colour::BLACK);
    board.placePiece(rook, f8);

    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, g7);

    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, h6);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateTwoBishop) {
    Board board;


    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, h8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, h7);

    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, a2);
    bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, b2);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateQueenRook) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, g8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, g7);
    pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, f7);

    Piece* rook = new Rook(Colour::WHITE);
    board.placePiece(rook, h1);

    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, h8);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateQueenKing) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, h8);

    Piece* queen = new Queen(Colour::WHITE);
    board.placePiece(queen, g7);

    Piece* kingWhite = new King(Colour::WHITE);
    board.placePiece(kingWhite, g6);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}

TEST_F(KingTest, checkmateRookBishop) {
    Board board;

    Piece* king = new King(Colour::BLACK);
    board.placePiece(king, h8);

    Piece* pawn = new Pawn(Colour::BLACK);
    board.placePiece(pawn, h7);

    Piece* rook = new Rook(Colour::WHITE);
    board.placePiece(rook, g1);

    Piece* bishop = new Bishop(Colour::WHITE);
    board.placePiece(bishop, b2);

    EXPECT_TRUE(board.checkmate(Colour::BLACK));
}
