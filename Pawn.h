//Qusay Edkymish
//Dec/1/2024
//Header file for the Pawn class in the Chess game project.

#ifndef PAWN_H
#define PAWN_H

#include "ChessBoard.h"     //Provides the ChessBoard class for movement validation.
#include "ChessPiece.h"     //Base class for all chess pieces.
#include "Position.h"       //Represents a position on the chessboard.
#include <string>           //For handling string attributes like color.
#include <vector>           //For storing a list of valid moves.

/**
 * @class Pawn
 * @brief Represents a Pawn piece in the Chess game.
 *
 * The Pawn moves forward one square but captures diagonally. It has special
 * rules such as moving two squares forward from its starting position
 * and the potential for promotion upon reaching the opposite end of the board.
 */
class Pawn : public ChessPiece 
{
public:
    /**
     * @brief Constructor for the Pawn class.
     *
     * @param color The color of the Pawn ("White" or "Black").
     * @param position The initial position of the Pawn on the chessboard.
     */
    Pawn(const string& color, const Position& position);

    /**
     * @brief Calculates all legal moves for the Pawn.
     *
     * This method determines the Pawn's possible movements based on the current
     * state of the chessboard. It considers the Pawn's unique movement rules,
     * including:
     * - Forward movement by one square.
     * - Double forward movement from the starting position.
     * - Diagonal captures of opponent pieces.
     *
     * @param board The ChessBoard object representing the game state.
     * @return A vector of Position objects representing valid moves for the Pawn.
     */
    vector<Position> getLegalMoves(const ChessBoard& board) const override;
};

#endif // PAWN_H