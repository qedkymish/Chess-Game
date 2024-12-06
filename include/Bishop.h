//Qusay Edkymish
//Dec/1/2024
//Header file for the Bishop class in a chess game. Defines the Bishop piece and its movement rules.

#ifndef BISHOP_H
#define BISHOP_H

#include "ChessBoard.h"     //Provides the ChessBoard class for movement validation.
#include "ChessPiece.h"     //Base class for all chess pieces.
#include "Position.h"       //Represents a position on the chessboard.
#include <string>           //For handling string attributes like color.
#include <vector>           //For storing a list of valid moves.

/**
 * @class Bishop
 * @brief Represents the Bishop piece in a chess game.
 *
 * The Bishop moves diagonally any number of squares, provided the path is clear.
 * Inherits from the ChessPiece base class.
 */
class Bishop : public ChessPiece 
{
public:
    /**
     * @brief Constructs a Bishop object.
     * @param color The color of the Bishop ("White" or "Black").
     * @param position The initial position of the Bishop on the board.
     */
    Bishop(const string& color, const Position& position);

    /**
     * @brief Calculates all legal moves for the Bishop.@brief Calculates all legal moves for the Bishop.
     * @param board The chessboard to evaluate the Bishop's movement.
     * @return A vector containing all valid positions the Bishop can move to.
     * @note The Bishop can move diagonally in all directions until blocked-
     * by another piece or the edge of the board.
     */
    vector<Position> getLegalMoves(const ChessBoard& board) const override;
};

#endif // BISHOP_H