//Qusay Edkymish
//Dec/1/2024
// Implementation file for the Knight class in the Chess game project.

#include "Knight.h"

/**
 * @brief Constructs a Knight object.
 *
 * @param color The color of the Knight ("White" or "Black").
 * @param position The initial position of the Knight on the chessboard.
 * @note The Knight's symbol is initialized to 'N' and passed to the parent class constructor.
 */
Knight::Knight(const string& color, const Position& position)
    : ChessPiece('N', color, position) {}

/**
 * @brief Calculates all legal moves for the Knight.
 *
 * This method evaluates the Knight's movement based on its unique "L" shape pattern:
 * - Two squares in one direction and one square perpendicular, or vice versa.
 * - The Knight can jump over other pieces but cannot land on a square occupied by a friendly piece.
 *
 * @param board The ChessBoard object representing the current state of the game.
 * @return A vector of Position objects representing valid moves for the Knight.
 * @note Only moves within the bounds of the board and to unoccupied or opponent-occupied squares are added.
 */
vector<Position> Knight::getLegalMoves(const ChessBoard& board) const
{
    //Stores knight legal moves
    vector<Position> legalMoves;

    //Possible knight move offsets (relative to current position)
    int moveOffsets[8][2] = 
    {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };

    int currentRow = this->getPosition().getRow();
    int currentCol = this->getPosition().getCol();

    //Iterate over all potential moves
    for (int i = 0; i < 8; i++) 
    {
        int newRow = currentRow + moveOffsets[i][0];
        int newCol = currentCol + moveOffsets[i][1];

        //Check if the move is within the bounds of the board
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) 
        {
            const ChessPiece* targetPiece = board.getPieceAt(newRow, newCol);

            //Add the position if it's empty or contains an opponent's piece
            if (!targetPiece || targetPiece->getColor() != this->getColor()) 
            {
                legalMoves.push_back(Position(newRow, newCol));
            }
        }
    }
    return legalMoves;
}