//Qusay Edkymish
//Dec/1/2024
//Header file for the Rook class in the Chess game project.

#ifndef ROOK_H
#define ROOK_H

#include "ChessBoard.h"     //Provides the ChessBoard class for movement validation.
#include "ChessPiece.h"     //Base class for all chess pieces.
#include "Position.h"       //Represents a position on the chessboard.
#include <string>           //For handling string attributes like color.
#include <vector>           //For storing a list of valid moves.

/**
 * @class Rook
 * @brief Represents a Rook piece in the Chess game.
 *
 * The Rook can move horizontally or vertically across the board
 * until it is blocked by another piece or the edge of the board.
 */
class Rook : public ChessPiece
{
public:
    /**
     * @brief Constructor for the Rook class.
     *
     * @param color The color of the Rook ("White" or "Black").
     * @param position The initial position of the Rook on the chessboard.
     */
    Rook(const string& color, const Position& position);

    /**
    * @brief Calculates all legal moves for the Rook.
    *
    * This method determines the Rook's possible movements based on
    * the current state of the chessboard.
    *
    * @param board The ChessBoard object representing the game state.
    * @return A vector of Position objects representing valid moves.
    * @note The Rook can move in straight lines (horizontally or vertically)
    * until it encounters another piece or the edge of the board.
    */
    vector<Position> getLegalMoves(const ChessBoard& board) const override;
};

#endif // ROOK_H