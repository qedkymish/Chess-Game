//Qusay Edkymish
//Nov/17/2024
//Class represents a single chess piece, including its type, color, and position.


#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Position.h" //Provides the Position class for piece location.
#include <iostream>   //Used for input and output operations.
#include <string>     //Used for handling the piece color as a string.
#include <vector>     //Used for storing the list of legal moves.

using namespace std;

//Forward decleration
class ChessBoard;

/**
 * @class ChessPiece
 * @brief Represents a generic chess piece with its type, color, and position.
 *
 * This abstract base class defines the common attributes and behaviors for all chess pieces.
 * Derived classes (e.g., Pawn, Rook, King) implement specific movement rules through the
 * `getLegalMoves` method.
 */
class ChessPiece
{
protected:
    //Variables
    char symbol;        //Symbol letter referring to the type of the piece (e.g., 'P' for Pawn) 
    string color;       //Piece color: Either white or blue
    Position position;  //Position instance representing the piece's location on the board

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the chess piece to an empty state with no symbol, no color, and no position.
     */
    ChessPiece();

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the chess piece with a specific symbol, color, and position.
     *
     * @param s The symbol representing the type of the piece (e.g., 'P', 'K').
     * @param c The color of the piece ("White" or "Black").
     * @param p The initial position of the piece on the chessboard.
     */
    ChessPiece(char s, const string& c, const Position& p);

    /**
     * @brief Gets the symbol of the chess piece.
     *
     * @return The character symbol representing the piece type.
     */
    char getSymbol() const;

    /**
     * @brief Gets the color of the chess piece.
     *
     * @return A string representing the piece's color ("White" or "Black").
     */
    string getColor() const;

    /**
     * @brief Gets the current position of the chess piece.
     *
     * @return A Position object representing the piece's location on the chessboard.
     */
    Position getPosition() const;

    /**
     * @brief Sets the position of the chess piece.
     *
     * @param r The row index of the new position (0-7).
     * @param col The column index of the new position (0-7).
     */
    void setPosition(int r, int col);

    /**
     * @brief Pure virtual function to calculate legal moves.
     *
     * This method must be implemented by all derived classes to define
     * the specific movement rules for each piece type.
     *
     * @param board The ChessBoard object representing the current state of the game.
     * @return A vector of Position objects representing valid moves for the piece.
     */
    virtual vector<Position> getLegalMoves(const ChessBoard& board) const = 0;

    /**
     * @brief Virtual destructor.
     *
     * Ensures proper cleanup of derived classes when deleting a ChessPiece pointer.
     */
    virtual ~ChessPiece();
};

#endif // !CHESSPIECE_H