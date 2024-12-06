//Qusay Edkymish
//Dec/1/2024
//Header file for the King class in the Chess game project.

#ifndef KING_H
#define KING_H

#include "ChessBoard.h"     //Provides the ChessBoard class for movement validation.
#include "ChessPiece.h"     //Base class for all chess pieces.
#include "Position.h"       //Represents a position on the chessboard.
#include <string>           //For handling string attributes like color.
#include <vector>           //For storing a list of valid moves.

/**
 * @class King
 * @brief Represents a King piece in the Chess game.
 *
 * The King moves one square in any direction (horizontally, vertically, or diagonally).
 * It also has special rules for castling under specific conditions.
 */
class King : public ChessPiece 
{
public:
    /**
     * @brief Constructor for the King class.
     *
     * @param color The color of the King ("White" or "Black").
     * @param position The initial position of the King on the chessboard.
     */
    King(const string& color, const Position& position);

    /**
     * @brief Calculates all legal moves for the King.
     *
     * This method determines the King's possible movements based on the current
     * state of the chessboard. It considers the King's unique movement rules:
     * - Moves one square in any direction (horizontally, vertically, or diagonally).
     * - Castling (if implemented) under specific conditions: no check, clear path, and unmoved pieces.
     *
     * @param board The ChessBoard object representing the game state.
     * @return A vector of Position objects representing valid moves for the King.
     * @note The King cannot move into a square that would place it in check.
     */
    vector<Position> getLegalMoves(const ChessBoard& board) const override;
};

#endif // KING_H