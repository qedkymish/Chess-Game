//Qusay Edkymish
//Nov/17/2024
//Position Class: Represents a position on the chessboard (row and column).

#ifndef POSITION_H
#define POSITION_H

#include <stdexcept>    //Provides the std::out_of_range exception class for error handling.

using namespace std;

/**
 * @class Position
 * @brief Represents a position on the chessboard, defined by a row and column.
 *
 * The Position class encapsulates the concept of a chessboard square,
 * identified by its row and column (0-7 for an 8x8 board). It provides
 * utility methods to access and modify these values.
 */
class Position 
{
private:
    int row;    //Row of the position (0-7 for an 8x8 board)
    int col;    //Column of the position (0-7 for an 8x8 board)

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the position to (0, 0).
     */
    Position();

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the position with the given row and column.
     *
     * @param r The row index of the position.
     * @param c The column index of the position.
     */
    Position(int r, int c);
    
    /**
     * @brief Gets the row of the position.
     *
     * @return The row index (0-7).
     */
    int getRow() const;

    /**
    * @brief Gets the column of the position.
    *
    * @return The column index (0-7).
    */
    int getCol() const;

    /**
     * @brief Sets the row of the position.
     *
     * @param r The new row index (0-7).
     */
    void setRow(int r);

    /**
     * @brief Sets the column of the position.
     *
     * @param c The new column index (0-7).
     */
    void setCol(int c);

    /**
     * @brief Comparison operator.
     *
     * Compares two positions to check if they are equal.
     *
     * @param other The other Position to compare with.
     * @return True if both positions have the same row and column; otherwise, false.
     */
    bool operator==(const Position& other) const;

    /**
     * @brief Destructor.
     *
     * Cleans up the Position object.
     */
    ~Position();
};

#endif // !POSITION_H