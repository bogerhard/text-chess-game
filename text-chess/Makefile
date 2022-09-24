CXX = g++
CXXFLAGS = -std=c++11 -g -fprofile-arcs -ftest-coverage

LINKFLAGS = -lgtest -lpthread

TEST_DIR = test

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

SRC_DIR = src

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM = chess
PROGRAM_TEST = testChess

DOCS_DIR = docs

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

.PHONY: all
all: $(PROGRAM_TEST) coverage memcheck static style docs

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *~ *.o $(SRC)/*.o $(TEST_SRC)/*.o \
	$(PROGRAM_TEST) $(PROGRAM) \
	$(DOCS_DIR) obj bin *.gc* .objs \
	$(COVERAGE_RESULTS) $(COVERAGE_DIR)

$(PROGRAM): $(SRC_DIR) $(SRC_DIR)/game/main.cpp
		$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(INCLUDE) \
		$(SRC_DIR)/*.cpp $(SRC_DIR)/game/main.cpp


$(PROGRAM_TEST): King.o Queen.o Bishop.o Knight.o Rook.o Pawn.o Chess.o Board.o \
		Piece.o Coordinate.o HorizontalPath.o VerticalPath.o DiagonalPath.o CompositePathChecker.o \
		testMain.o testGame.o testKing.o testQueen.o testBishop.o testKnight.o \
		testRook.o testPawn.o testMovement.o
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
		testMain.o testGame.o testKing.o testQueen.o testBishop.o testKnight.o \
		testRook.o testPawn.o testMovement.o \
		Chess.o Board.o Pawn.o Piece.o King.o Queen.o Knight.o Rook.o Bishop.o \
		Coordinate.o HorizontalPath.o VerticalPath.o DiagonalPath.o CompositePathChecker.o \
		$(LINKFLAGS)

King.o: $(SRC_DIR)/King.cpp $(SRC_INCLUDE)/King.h $(SRC_INCLUDE)/Pawn.h
		$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/King.cpp -o King.o -I $(SRC_INCLUDE)

Queen.o: $(SRC_DIR)/Queen.cpp $(SRC_INCLUDE)/Queen.h
		$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Queen.cpp -o Queen.o -I $(SRC_INCLUDE)

Bishop.o: $(SRC_DIR)/Bishop.cpp $(SRC_INCLUDE)/Bishop.h
		$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Bishop.cpp -o Bishop.o -I $(SRC_INCLUDE)

Knight.o: $(SRC_DIR)/Knight.cpp $(SRC_INCLUDE)/Knight.h
		$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Knight.cpp -o Knight.o -I $(SRC_INCLUDE)

Rook.o: $(SRC_DIR)/Rook.cpp $(SRC_INCLUDE)/Rook.h
		$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Rook.cpp -o Rook.o -I $(SRC_INCLUDE)

Pawn.o: $(SRC_DIR)/Pawn.cpp $(SRC_INCLUDE)/Pawn.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Pawn.cpp -o Pawn.o -I $(SRC_INCLUDE)

Chess.o: $(SRC_DIR)/Chess.cpp $(SRC_INCLUDE)/Chess.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Chess.cpp -o Chess.o -I $(SRC_INCLUDE)

Board.o: $(SRC_DIR)/Board.cpp $(SRC_INCLUDE)/Board.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Board.cpp -o Board.o -I $(SRC_INCLUDE)

Piece.o: $(SRC_DIR)/Piece.cpp $(SRC_INCLUDE)/Piece.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Piece.cpp -o Piece.o -I $(SRC_INCLUDE)

Coordinate.o: $(SRC_DIR)/Coordinate.cpp $(SRC_INCLUDE)/Coordinate.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Coordinate.cpp -o Coordinate.o -I $(SRC_INCLUDE)

HorizontalPath.o: $(SRC_DIR)/HorizontalPath.cpp $(SRC_INCLUDE)/HorizontalPath.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/HorizontalPath.cpp -o HorizontalPath.o -I $(SRC_INCLUDE)

VerticalPath.o: $(SRC_DIR)/VerticalPath.cpp $(SRC_INCLUDE)/VerticalPath.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/VerticalPath.cpp -o VerticalPath.o -I $(SRC_INCLUDE)

DiagonalPath.o: $(SRC_DIR)/DiagonalPath.cpp $(SRC_INCLUDE)/DiagonalPath.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/DiagonalPath.cpp -o DiagonalPath.o -I $(SRC_INCLUDE)

CompositePathChecker.o: $(SRC_DIR)/CompositePathChecker.cpp $(SRC_INCLUDE)/CompositePathChecker.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/CompositePathChecker.cpp -o CompositePathChecker.o -I $(SRC_INCLUDE)

testMain.o: $(TEST_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/main.cpp -o testMain.o -I $(SRC_INCLUDE)

testGame.o: $(TEST_DIR)/Game.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Game.cpp -o testGame.o -I $(SRC_INCLUDE)

testKing.o: $(TEST_DIR)/King.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/King.cpp -o testKing.o -I $(SRC_INCLUDE)

testQueen.o: $(TEST_DIR)/Queen.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Queen.cpp -o testQueen.o -I $(SRC_INCLUDE)

testBishop.o: $(TEST_DIR)/Bishop.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Bishop.cpp -o testBishop.o -I $(SRC_INCLUDE)

testKnight.o: $(TEST_DIR)/Knight.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Knight.cpp -o testKnight.o -I $(SRC_INCLUDE)

testRook.o: $(TEST_DIR)/Rook.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Rook.cpp -o testRook.o -I $(SRC_INCLUDE)

testPawn.o: $(TEST_DIR)/Pawn.cpp
		$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Pawn.cpp -o testPawn.o -I $(SRC_INCLUDE)

testMovement.o: $(TEST_DIR)/Movement.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Movement.cpp -o testMovement.o -I $(SRC_INCLUDE)

testCoordinate3D.o: $(TEST_DIR)/Coordinate3D.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Coordinate3D.cpp -o testCoordinate3D.o -I $(SRC_INCLUDE)

testBoard3D.o: $(TEST_DIR)/Board3DTest.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/Board3DTest.cpp -o testBoard3D.o -I $(SRC_INCLUDE)

tests: $(PROGRAM_TEST)
	$(PROGRAM_TEST)

memcheck: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM_TEST)

static: ${SRC_DIR} ${TEST_DIR} ${SRC_INCLUDE}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${TEST_DIR} ${SRC_INCLUDE} --suppress=missingInclude

style: ${TEST_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${TEST_DIR}/*

docs: ${SRC_INCLUDE}/*.h
	doxygen doxyfile

coverage: testChess
		$(PROGRAM_TEST)
		# Determine code coverage
		$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS) --rc lcov_branch_coverage=1
		# Only show code coverage for the source code files (not library files)
		$(LCOV) --extract $(COVERAGE_RESULTS) "*/src/*" -o $(COVERAGE_RESULTS) --rc lcov_branch_coverage=1
		$(LCOV) --remove $(COVERAGE_RESULTS) "*/test/*" -o $(COVERAGE_RESULTS) --rc lcov_branch_coverage=1
		#Generate the HTML reports
		genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR) --rc lcov_branch_coverage=1
		#Remove all of the generated files from gcov
		rm -f *.gc*
