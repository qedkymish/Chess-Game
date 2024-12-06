//Qusay Edkymish
//Nov/17/2024
//Position Class Implementation

#include "Position.h"

using namespace std;

/**
 * @brief Default Constructor.
 *
 * Initializes the position to the top-left corner of the board (0, 0).
 */
Position::Position() : row(0), col(0) {}

/**
 * @brief Parameterized Constructor.
 *
 * Initializes the position with the given row and column values.
 *
 * @param r The row index of the position.
 * @param c The column index of the position.
 */
Position::Position(int r, int c) : row(r), col(c) {}

/**
 * @brief Gets the row of the position.
 *
 * @return The row index (0-7).
 */
int Position::getRow() const { return row; }

/**
 * @brief Gets the column of the position.
 *
 * @return The column index (0-7).
 */
int Position::getCol() const { return col; }

/**
 * @brief Sets the row of the position.
 *
 * Validates that the row is within the bounds of the chessboard (0-7).
 * Throws an exception if the value is out of bounds.
 *
 * @param r The new row index to set.
 * @throws std::out_of_range If the row index is not between 0 and 7.
 */
void Position::setRow(int r)
{
    //Validates that the row is within the bounds of the chessboard (0-7)
    if (r >= 0 && r < 8)
    {
        //Valid input
        row = r;
    }
    else
    {
        //Invalid input
        throw out_of_range("Row out of bounds");
    }

}

/**
 * @brief Sets the column of the position.
 *
 * Validates that the column is within the bounds of the chessboard (0-7).
 * Throws an exception if the value is out of bounds.
 *
 * @param c The new column index to set.
 * @throws std::out_of_range If the column index is not between 0 and 7.
 */
void Position::setCol(int c)
{
    //Validates that the column is within the bounds of the chessboard (0-7)
    if (c >= 0 && c < 8)
    {
        //Valid input
        col = c;
    }
    else
    {
        //Invalid input
        throw out_of_range("Column out of bounds");
    }
}

/**
 * @brief Comparison operator.
 *
 * Checks if this position is equal to another position.
 *
 * @param other The Position object to compare with.
 * @return True if both positions have the same row and column values; otherwise, false.
 */
bool Position::operator==(const Position& other) const
{ return row == other.row && col == other.col; }

/**
 * @brief Destructor.
 *
 * Cleans up the Position object.
 */
Position::~Position() {};