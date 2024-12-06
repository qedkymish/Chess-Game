//Qusay Edkymish
//Dec/1/2024
//Implementation file for the King class in the Chess game project.

#include "King.h"

/**
 * @brief Constructs a King object.
 *
 * @param color The color of the King ("White" or "Black").
 * @param position The initial position of the King on the chessboard.
 * @note The King's symbol is initialized to 'K' and passed to the parent class constructor.
 */
King::King(const std::string& color, const Position& position)
    : ChessPiece('K', color, position) {}

/**
 * @brief Calculates all legal moves for the King.
 *
 * This method evaluates the King's possible movements based on its ability
 * to move one square in any direction (horizontally, vertically, or diagonally).
 * The King cannot move to a square occupied by a friendly piece.
 *
 * @param board The ChessBoard object representing the current game state.
 * @return A vector of Position objects representing valid moves for the King.
 * @note The King cannot move into a square that would place it in check.
 */
vector<Position> King::getLegalMoves(const ChessBoard& board) const
{
    //Stores king legal moves
    vector<Position> legalMoves;

    //Possible directions for King
    int directions[8][2] = 
    {
        {-1, -1}, {-1, 0}, {-1, 1}, //Up
        {0, -1},         {0, 1},    //Left and Right
        {1, -1}, {1, 0}, {1, 1}     //Down
    };

    int row = position.getRow();
    int col = position.getCol();

    //Iterate through all possible directions
    for (int i = 0; i < 8; i++) 
    {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        //Ensure the move is within the bounds of the board
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
        {
            const ChessPiece* target = board.getPieceAt(newRow, newCol);

            //Add position to legal moves if it's unoccupied or occupied by an opponent
            if (!target || target->getColor() != this->getColor()) 
            {
                legalMoves.push_back(Position(newRow, newCol));
            }
        }
    }
    return legalMoves;
}
