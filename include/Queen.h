//Qusay Edkymish
//Dec/1/2024
//Header file for the Queen class in the Chess game project.

#ifndef QUEEN_H
#define QUEEN_H

#include "ChessBoard.h"     //Provides the ChessBoard class for movement validation.
#include "ChessPiece.h"     //Base class for all chess pieces.
#include "Position.h"       //Represents a position on the chessboard.
#include <string>           //For handling string attributes like color.
#include <vector>           //For storing a list of valid moves.

/**
 * @class Queen
 * @brief Represents a Queen piece in the Chess game.
 *
 * The Queen combines the movement rules of both the Rook and the Bishop.
 * It can move any number of squares horizontally, vertically, or diagonally,
 * but cannot jump over other pieces.
 */
class Queen : public ChessPiece 
{
public:
    /**
     * @brief Constructor for the Queen class.
     *
     * @param color The color of the Queen ("White" or "Black").
     * @param position The initial position of the Queen on the chessboard.
     */
    Queen(const string& color, const Position& position);

    /**
    * @brief Calculates all legal moves for the Queen.
    *
    * This method determines the Queen's possible movements based on-
    * the current state of the chessboard. The Queen can move like-
    * both the Rook and the Bishop.
    *
    * @param board The ChessBoard object representing the current game state.
    * @return A vector of Position objects representing valid moves.
    * @note The Queen cannot jump over other pieces. It stops at obstructions-
    * (friendly pieces block movement, while opponent pieces are capturable).
    */
    vector<Position> getLegalMoves(const ChessBoard& board) const override;
};

#endif // QUEEN_H