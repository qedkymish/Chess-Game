//Qusay Edkymish
//Dec/1/2024
//Implementation file for the Pawn class in the Chess game project.

#include "Pawn.h"

/**
 * @brief Constructs a Pawn object.
 *
 * @param color The color of the Pawn ("White" or "Black").
 * @param position The initial position of the Pawn on the chessboard.
 * @note The Pawn's symbol is initialized to 'P' and passed to the parent class constructor.
 */
Pawn::Pawn(const string& color, const Position& position)
    : ChessPiece('P', color, position) {}

/**
 * @brief Calculates all legal moves for the Pawn.
 *
 * This method evaluates the Pawn's unique movement rules based on the current
 * state of the chessboard. It considers:
 * - Forward movement (one or two squares).
 * - Diagonal captures of opponent pieces.
 *
 * @param board The ChessBoard object representing the game state.
 * @return A vector of Position objects representing valid moves for the Pawn.
 * @note Pawns cannot move backward and must adhere to chess rules for diagonal captures.
 */
vector<Position> Pawn::getLegalMoves(const ChessBoard& board) const
{
    //Stores valid moves for the Pawn.
    vector<Position> legalMoves;
    int row = position.getRow();
    int col = position.getCol();

    //Determine the movement direction based on the color of the pawn
    //(Upward for the white, and downward the black)
    int direction = (getColor() == "White") ? -1 : 1;

    //Single square forward
    int nextRow = row + direction;

    //Ensure the move stays within board bounds
    if (nextRow >= 0 && nextRow < 8)
    {
        //Check if the square is unoccupied
        if (board.getPieceAt(nextRow, col) == nullptr)
        {
            legalMoves.push_back(Position(nextRow, col));
        }
    }

    //Two squares forward (only from the starting position)
    int startRow = (getColor() == "White") ? 6 : 1;        //Starting row depends on pawn's color


    if (row == startRow && board.getPieceAt(nextRow, col) == nullptr &&
        board.getPieceAt(row + 2 * direction, col) == nullptr)
    {
        legalMoves.push_back(Position(row + 2 * direction, col));
    }

    //Diagonal capture
    for (int dCol : {-1, 1})    //Check left and right diagonals
    {
        int newCol = col + dCol;

        //Ensure within bounds
        if (newCol >= 0 && newCol < 8 && nextRow >= 0 && nextRow < 8)
        {
            const ChessPiece* target = board.getPieceAt(nextRow, newCol);

            // Opponent piece on diagonal
            if (target && target->getColor() != this->getColor())
            {
                legalMoves.push_back(Position(nextRow, newCol));
            }
        }
    }

    return legalMoves;
}