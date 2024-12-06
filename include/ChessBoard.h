//Qusay Edkymish
//Nov/17/2024
//ChessBoard Class: Manages the chessboard and its pieces.

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Bishop.h"       //Includes Bishop class for board setup and interactions.
#include "King.h"         //Includes King class for board setup and interactions.
#include "Knight.h"       //Includes Kinght class for board setup and interactions.
#include "Pawn.h"         //Includes Pawn class for board setup and interactions.
#include "Position.h"     //Includes Position class for piece locations.
#include "Queen.h"        //Includes Queen class for board setup and interactions.
#include "Rook.h"         //Includes Rook class for board setup and interactions.
#include <iomanip>        //Used for formatting board display.  
#include <iostream>       //Used for input and output operations.
#include <memory>         //Used for unique pointers to ChessPiece objects.
#include <vector>         //Used for managing lists of pieces and positions.

using namespace std;

//Forward declaration of ChessPiece
class ChessPiece;

/**
 * @class ChessBoard
 * @brief Manages the chessboard and its pieces.
 *
 * The ChessBoard class handles the initialization, display, and manipulation
 * of a chessboard. It manages the positions of pieces, validates movements,
 * and provides utilities to check the state of the board.
 */
class ChessBoard
{   
private:
    static const int SIZE = 8;                      //Board dimensions (8x8)
    unique_ptr<ChessPiece> board[SIZE][SIZE];       //2D array of unique pointers to ChessPiece objects

public:
    /**
     * @brief Constructor for the ChessBoard class.
     *
     * Initializes an empty chessboard.
     */
    ChessBoard();

    /**
     * @brief Sets up the initial board configuration.
     *
     * Places all pieces (Pawns, Rooks, Knights, Bishops, Queens, and Kings)
     * in their starting positions.
     */
    void initializeBoard();

    /**
     * @brief Displays the chessboard, optionally highlighting specific positions.
     *
     * - Pieces are displayed using their symbols.
     * - Empty spaces are displayed as '.'.
     * - Highlighted positions (if provided) are marked with 'x'.
     *
     * @param highlightedPositions A vector of positions to highlight (e.g., legal moves). Defaults to an empty vector.
     */
    void displayBoard(const std::vector<Position>& highlightedPositions = {}) const;

    /**
     * @brief Gets the chess piece at a specific position.
     *
     * @param row The row index of the position (0-7).
     * @param col The column index of the position (0-7).
     * @return A constant pointer to the ChessPiece at the specified position,
     *         or nullptr if the square is empty.
     */
    const ChessPiece* getPieceAt(int row, int col) const;

    /**
     * @brief Moves a piece from one position to another.
     *
     * Updates the board to reflect the move and modifies the piece's position.
     *
     * @param from The starting position of the piece.
     * @param to The target position of the piece.
     */
    void movePiece(const Position& from, const Position& to);

    /**
     * @brief Checks if the path between two positions is clear.
     *
     * Validates that no pieces block the path between the starting
     * and ending positions.
     *
     * @param start The starting position of the path.
     * @param end The ending position of the path.
     * @return True if the path is clear; otherwise, false.
     */
    bool isPathClear(const Position& start, const Position& end) const;

    /**
     * @brief Displays all legal moves for the piece at a given position.
     *
     * Prints the valid moves to the console based on the piece's movement rules.
     *
     * @param piecePos The position of the piece to evaluate.
     */
    void displayLegalMoves(const Position& piecePos) const;

    /**
     * @brief Destructor for the Chess class.
     *
     * Cleans up resources and finalizes the game.
     */
    ~ChessBoard();
};

#endif // !CHESSBOARD_H