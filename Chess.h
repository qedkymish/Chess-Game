//Qusay Edkymish
//Dec/1st/2024
//Header file for the Chess class, handling the main game logic and user interactions.

#ifndef CHESS_H
#define CHESS_H

#include "ChessBoard.h"		//Manage the chessboard and its pieces.
#include "Position.h"		//Provides the Position class for piece location.
#include <string>			//For handling string attributes.


/**
 * @class Chess
 * @brief Handles the main game logic and user interactions for the Chess game.
 *
 * The Chess class provides menus, game modes, and utility functions for converting
 * between chess notation and board positions. It serves as the primary interface
 * for running the chess program.
 */
class Chess
{
private:
	//Instance of ChessBoard to manage the game board and pieces.
	ChessBoard chessBoard;

public:
	/**
	 * @brief Constructor for the Chess class.
	 *
	 * Initializes the game and sets up the chessboard.
	 */
	Chess();

	/**
	 * @brief Displays a menu header with the given name.
	 *
	 * @param name The name of the menu to display.
	 */
	void menuName(const string& name) const;

	/**
	 * @brief Displays the main menu for the program.
	 *
	 * Handles navigation to other menus, such as game mode or about menu.
	 */
	void mainMenu();

	/**
	 * @brief Displays the game menu for starting and playing the game.
	 */
	void gameMenu();

	/**
	 * @brief Displays the about menu with information about the program.
	 */
	void aboutMenu();

	/**
	 * @brief Parses chess notation into a Position object.
	 *
	 * Converts strings like "e4" into a corresponding Position on the chessboard.
	 *
	 * @param notation The chess notation string to parse (e.g., "e4").
	 * @return A Position object representing the parsed location.
	 */
	Position parseChessNotation(const string& notation) const;

	/**
	 * @brief Converts a Position object into chess notation.
	 *
	 * Converts a board position into a human-readable chess notation string.
	 *
	 * @param pos The Position object to convert.
	 * @return A string representing the chess notation (e.g., "e4").
	 */
	string formatChessNotation(const Position& pos) const;

	/**
	 * @brief Displays the program's header information.
	 *
	 * Includes details like the program title and author.
	 */
	void displayHeader() const;

	/**
	 * @brief Starts the Free Play mode.
	 *
	 * In this mode, players can move pieces freely without rules enforcement.
	 */
	void freePlay();

	/**
	 * @brief Destructor for the Chess class.
	 *
	 * Cleans up resources and finalizes the game.
	 */
	~Chess();
};

#endif // !CHESS_H