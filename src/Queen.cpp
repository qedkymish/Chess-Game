//Qusay Edkymish
//Dec/1/2024
//Implementation file for the Queen class in the Chess game project.


#include "Queen.h"

/**
 * @brief Constructs a Queen object.
 *
 * @param color The color of the Queen ("White" or "Black").
 * @param position The initial position of the Queen on the chessboard.
 * @note The Queen's symbol is initialized to 'Q' and passed to the parent class constructor.
 */
Queen::Queen(const std::string& color, const Position& position)
    : ChessPiece('Q', color, position) {}

/**
 * @brief Calculates all legal moves for the Queen.
 *
 * The Queen combines the movement abilities of both the Rook and the Bishop.
 * This method retrieves the Rook-like and Bishop-like moves using their respective logic-
 * and merges them into a single list of legal moves for the Queen.
 *
 * @param board The ChessBoard object representing the current state of the game.
 * @return A vector of Position objects representing valid moves for the Queen.
 * @note The Queen cannot jump over other pieces. Rook-like and Bishop-like moves are-
 * evaluated independently to handle obstructions.
 */
vector<Position> Queen::getLegalMoves(const ChessBoard& board) const
{
    //Stores the combined valid moves for the Queen
    vector<Position> legalMoves;

    //Use Rook and Bishop movement logic
    Rook rookPart(this->getColor(), this->getPosition());
    Bishop bishopPart(this->getColor(), this->getPosition());

    //Get Rook-like moves
    auto rookMoves = rookPart.getLegalMoves(board);

    //Get Bishop-like moves
    auto bishopMoves = bishopPart.getLegalMoves(board);

    //Combine the Rook and Bishop moves into one list
    legalMoves.insert(legalMoves.end(), rookMoves.begin(), rookMoves.end());
    legalMoves.insert(legalMoves.end(), bishopMoves.begin(), bishopMoves.end());

    return legalMoves;
}