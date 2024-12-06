//Qusay Edkymish
//Nov/17/2024
//ChessPiece Class Implementation

#include "ChessPiece.h"

/**
 * @brief Default constructor.
 *
 * Initializes the chess piece to an empty state with:
 * - Symbol: ' ' (no piece type).
 * - Color: "None".
 * - Position: (0, 0).
 */
ChessPiece::ChessPiece() : symbol(' '), color("None"), position(Position(0, 0)) {}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the chess piece with a specific symbol, color, and position.
 *
 * @param s The symbol representing the type of the piece (e.g., 'P' for Pawn, 'K' for King).
 * @param c The color of the piece ("White" or "Black").
 * @param p The initial position of the piece on the chessboard.
 */
ChessPiece::ChessPiece(char s, const string& c, const Position& p) : symbol(s), color(c), position(p) {}

/**
 * @brief Gets the symbol of the chess piece.
 *
 * @return The character symbol representing the piece type.
 */
char ChessPiece::getSymbol() const { return symbol; }

/**
 * @brief Gets the color of the chess piece.
 *
 * @return A string representing the piece's color ("White" or "Black").
 */
string ChessPiece::getColor() const { return color; }

/**
 * @brief Gets the current position of the chess piece.
 *
 * @return A Position object representing the piece's location on the chessboard.
 */
Position ChessPiece::getPosition() const { return position; }

/**
 * @brief Sets the position of the chess piece.
 *
 * Updates the position of the piece with new row and column values.
 *
 * @param r The row index of the new position (0-7).
 * @param col The column index of the new position (0-7).
 */
void ChessPiece::setPosition(int r, int col)
{
    position.setRow(r);
    position.setCol(col);
}

/**
 * @brief Virtual destructor.
 *
 * Ensures proper cleanup of derived classes when deleting a ChessPiece pointer.
 */
ChessPiece::~ChessPiece() {}