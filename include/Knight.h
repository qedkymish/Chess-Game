//Qusay Edkymish
//Dec/1/2024
//Header file for the Knight class in the Chess game project.


#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessBoard.h"     //Provides the ChessBoard class for movement validation.
#include "ChessPiece.h"     //Base class for all chess pieces.
#include "Position.h"       //Represents a position on the chessboard.
#include <string>           //For handling string attributes like color.
#include <vector>           //For storing a list of valid moves.

/**
 * @class Knight
 * @brief Represents a Knight piece in the Chess game.
 *
 * The Knight moves in an "L" shape: two squares in one direction and one square
 * perpendicular to that direction, or vice versa. Unlike other pieces, it can
 * jump over other pieces.
 */
class Knight : public ChessPiece 
{
public:
    /**
     * @brief Constructor for the Knight class.
     *
     * @param color The color of the Knight ("White" or "Black").
     * @param position The initial position of the Knight on the chessboard.
     */
    Knight(const string& color, const Position& position);

    /**
     * @brief Calculates all legal moves for the Knight.
     *
     * This method determines the Knight's possible movements based on the
     * current state of the chessboard. The Knight's unique ability to jump over
     * other pieces is taken into account.
     *
     * @param board The ChessBoard object representing the game state.
     * @return A vector of Position objects representing valid moves for the Knight.
     * @note The Knight's movement is not blocked by other pieces, but it cannot
     * land on a square occupied by a friendly piece.
     */
    vector<Position> getLegalMoves(const ChessBoard& board) const override;
};

#endif // KNIGHT_H