//Qusay Edkymish
//Dec/1/2024
//Implementation file for the Rook class in the Chess game project.

#include "Rook.h"

/**
 * @brief Constructs a Rook object.
 *
 * @param color The color of the Rook ("White" or "Black").
 * @param position The initial position of the Rook on the chessboard.
 * @note The Rook's symbol is initialized to 'R' and passed to the parent class constructor.
 */
Rook::Rook(const std::string& color, const Position& position)
    : ChessPiece('R', color, position) {}

/**
 * @brief Calculates all legal moves for the Rook.
 *
 * This method evaluates all horizontal and vertical movements for the Rook,
 * checking for obstructions and valid target squares on the chessboard.
 *
 * @param board The ChessBoard object representing the current state of the game.
 * @return A vector of Position objects representing the valid moves.
 * @note The Rook can move in straight lines (up, down, left, right) until
 * it encounters another piece or the edge of the board.
 */
vector<Position> Rook::getLegalMoves(const ChessBoard& board) const 
{
    vector<Position> legalMoves;    //Stores valid moves for the Rook.
    int row = position.getRow();
    int col = position.getCol();

    //Check all vertical directions (up and down)
    for (int delta : {-1, 1})
    { 
        for (int r = row + delta; r >= 0 && r < 8; r += delta) 
        {
            Position newPos(r, col);

            //Check if the path to the new position is clear
            if (board.isPathClear(position, newPos)) {
                const ChessPiece* target = board.getPieceAt(r, col);

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

    //Check all horizontal directions (left and right)
    for (int delta : {-1, 1})
    {
        for (int c = col + delta; c >= 0 && c < 8; c += delta) 
        {
            Position newPos(row, c);

            //Check if the path to the new position is clear
            if (board.isPathClear(position, newPos)) {
                const ChessPiece* target = board.getPieceAt(row, c);

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
    return legalMoves;
}