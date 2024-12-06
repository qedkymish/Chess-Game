//Qusay Edkymish
//Dec/1/2024
//Implementation file for the Bishop class in the Chess game project.

#include "Bishop.h"


/**
 * @brief Constructs a Bishop object.
 *
 * @param color The color of the Bishop ("White" or "Black").
 * @param position The initial position of the Bishop on the chessboard.
 * @note The Bishop's symbol is initialized to 'B' and passed to the parent class constructor.
 */
Bishop::Bishop(const string& color, const Position& position)
    : ChessPiece('B', color, position) {}

/**
 * @brief Calculates all legal moves for the Bishop.
 *
 * This method evaluates all diagonals the Bishop can move along, checking
 * for obstructions and valid target squares on the chessboard.
 *
 * @param board The ChessBoard object that represents the current state of the game.
 * @return A vector of Position objects representing the valid moves.
 * @note The Bishop can move in all diagonal directions (up-left, up-right,
 * down-left, down-right) until it encounters an obstruction (either another piece or the board edge).
 */
vector<Position> Bishop::getLegalMoves(const ChessBoard& board) const 
{
    vector<Position> legalMoves;    //Stores valid moves for the Bishop.
    int row = position.getRow();
    int col = position.getCol();

    //Iterate over all diagonal directions
    for (int rDelta : {-1, 1})              //Check upward and downward directions
    { 
        for (int cDelta : {-1, 1})          //Check left and right directions
        {
            for (int r = row + rDelta, c = col + cDelta;
                r >= 0 && r < 8 && c >= 0 && c < 8;     //Ensure within board bounds
                r += rDelta, c += cDelta)               //Move along the diagonal
            {
                Position newPos(r, c);

                //Check if the path to the new position is clear
                if (board.isPathClear(position, newPos)) 
                {
                    const ChessPiece* target = board.getPieceAt(r, c);

                    //Add position to legal moves if it's unoccupied or occupied by an opponent
                    if (!target || target->getColor() != this->getColor()) 
                    {
                        legalMoves.push_back(newPos);

                        //Stop further traversal if an opponent's piece is encountered
                        if (target) break; 
                    }
                    //Stop traversal if a friendly piece blocks the path
                    else break;
                }
            }
        }
    }

    return legalMoves;
}
