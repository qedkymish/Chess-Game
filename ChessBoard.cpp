//Qusay Edkymish
//Nov/17/2024
//ChessBoard Class Implementation


#include "ChessBoard.h"
#include "ChessPiece.h"


/**
 * @brief Constructor for the ChessBoard class.
 *
 * Initializes the chessboard by calling the `initializeBoard` method.
 */
ChessBoard::ChessBoard()
{
    initializeBoard();
}

/**
 * @brief Initializes the chessboard with pieces in their starting positions.
 *
 * - Sets all squares to `nullptr` (empty).
 * - Places Pawns, Rooks, Knights, Bishops, Queen, and King for White (Plannig to add black soon).
 */
void ChessBoard::initializeBoard()
{
    //Initialize all spaces with nullptr (empty)
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = nullptr;
        }
    }

    //Place white pieces (bottom side)
    board[7][0] = make_unique<Rook>("White", Position(7, 0));
    board[7][1] = make_unique<Knight>("White", Position(7, 1));
    board[7][2] = make_unique<Bishop>("White", Position(7, 2));
    board[7][3] = make_unique<Queen>("White", Position(7, 3));
    board[7][4] = make_unique<King>("White", Position(7, 4));
    board[7][5] = make_unique<Bishop>("White", Position(7, 5));
    board[7][6] = make_unique<Knight>("White", Position(7, 6));
    board[7][7] = make_unique<Rook>("White", Position(7, 7));

    //Place white pawns
    for (int j = 0; j < SIZE; j++)
    {
        board[6][j] = make_unique<Pawn>("White", Position(6, j));
    }
}

/**
 * @brief Displays the chessboard, optionally highlighting specific positions.
 *
 * - Pieces are displayed using their symbols.
 * - Empty spaces are displayed as '.'.
 * - Highlighted positions (if provided) are marked with 'x'.
 *
 * @param highlightedPositions A vector of positions to highlight (e.g., legal moves). Defaults to an empty vector.
 */
void ChessBoard::displayBoard(const vector<Position>& highlightedPositions) const
{
    cout << "   ";
    for (char c = 'A'; c < 'A' + SIZE; c++) {
        cout << setw(3) << c; // Column headers (A-H)
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << setw(2) << (i + 1) << " "; // Row numbers (1-8)
        for (int j = 0; j < SIZE; j++) {
            Position currentPos(i, j);

            // Check if the current position is in the list of highlighted positions
            if (find(highlightedPositions.begin(), highlightedPositions.end(), currentPos) != highlightedPositions.end()) {
                cout << setw(3) << "x"; // Highlight position
            }
            else if (board[i][j]) {
                cout << setw(3) << board[i][j]->getSymbol(); // Display piece symbol
            }
            else {
                cout << setw(3) << "."; // Empty space
            }
        }
        cout << endl;
    }
}


/**
 * @brief Gets the chess piece at a specific position.
 *
 * @param row The row index of the position (0-7).
 * @param col The column index of the position (0-7).
 * @return A constant pointer to the ChessPiece at the specified position, or nullptr if the square is empty.
 */
const ChessPiece* ChessBoard::getPieceAt(int row, int col) const
{
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) 
    {
        const ChessPiece* piece = board[row][col].get();
        return piece;
    }
    return nullptr;
}

/**
 * @brief Checks if the path between two positions is clear.
 *
 * This method validates that no pieces block the path between the starting and ending positions.
 *
 * @param start The starting position of the path.
 * @param end The ending position of the path.
 * @return True if the path is clear; otherwise, false.
 */
bool ChessBoard::isPathClear(const Position& start, const Position& end) const 
{
    int startRow = start.getRow();
    int startCol = start.getCol();
    int endRow = end.getRow();
    int endCol = end.getCol();

    int rowDelta = endRow - startRow;
    int colDelta = endCol - startCol;

    //Determine the step direction
    int rowStep = (rowDelta == 0) ? 0 : (rowDelta > 0 ? 1 : -1);
    int colStep = (colDelta == 0) ? 0 : (colDelta > 0 ? 1 : -1);

    //Check each position along the path (excluding the start and end)
    int currentRow = startRow + rowStep;
    int currentCol = startCol + colStep;

    while (currentRow != endRow || currentCol != endCol) 
    {
        if (board[currentRow][currentCol] != nullptr) 
        {
            //Path is blocked
            return false;
        }
        currentRow += rowStep;
        currentCol += colStep;
    }
    //Path is clear
    return true;
}

/**
 * @brief Moves a chess piece from one position to another.
 *
 * Updates the board to reflect the move and modifies the piece's internal position.
 *
 * @param from The starting position of the piece.
 * @param to The target position of the piece.
 */
void ChessBoard::movePiece(const Position& from, const Position& to)
{
    //Get the piece at the source position
    ChessPiece* piece = board[from.getRow()][from.getCol()].get();

    //Update the piece's internal position if it exists
    if (piece)
    {
        piece->setPosition(to.getRow(), to.getCol());
    }

    //Move the piece to the new position on the board
    board[to.getRow()][to.getCol()] = move(board[from.getRow()][from.getCol()]);
    //Clear the old position
    board[from.getRow()][from.getCol()] = nullptr;
}

/**
 * @brief Displays all legal moves for the chess piece at a given position.
 *
 * - Legal moves are marked with 'x'.
 * - Empty spaces are marked with '.'.
 * - Piece symbols are displayed normally.
 *
 * @param piecePos The position of the piece to evaluate.
 */
void ChessBoard::displayLegalMoves(const Position& piecePos) const
{
    const ChessPiece* piece = getPieceAt(piecePos.getRow(), piecePos.getCol());

    if (!piece) {
        cout << "No piece at the given position." << endl;
        return;
    }

    // Get the legal moves for the piece
    vector<Position> legalMoves = piece->getLegalMoves(*this);

    // Use the modified displayBoard to highlight legal moves
    displayBoard(legalMoves);
}

/**
 * @brief Destructor for the Chess class.
 *
 * Cleans up resources and finalizes the game.
 */
ChessBoard::~ChessBoard() {};