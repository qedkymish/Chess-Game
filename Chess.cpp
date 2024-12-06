//Qusay Edkymish
//Dec/1/2024
//Chess Class Implementation

#include "Chess.h"

/**
 * @brief Constructor for the Chess class.
 *
 * Initializes the Chess instance and sets up the game environment.
 */
Chess::Chess() {}

/**
 * @brief Displays a menu header with the given name.
 *
 * Creates a visually appealing header for menus with centered titles and borders.
 *
 * @param name The name of the menu to display.
 */
void Chess::menuName(const string& name) const
{
	//Define a minimum width for the title box
	int minWidth = 30;  //Set a minimum width to keep borders wide enough
	int totalWidth = max(static_cast<int>(name.size()) + 8, minWidth);  //Ensure padding, minimum width

	//Calculate padding on each side for centering
	int padding = (totalWidth - static_cast<int>(name.size())) / 2;

	//Top border
	cout << "\n" << string(totalWidth, '=') << "\n";

	//Centered title with padding
	cout << string(padding, ' ') << name << string(padding, ' ');

	//If the title length is odd, add one extra space for alignment
	if (static_cast<int>(name.size()) % 2 != 0)
	{
		cout << " ";
	}

	cout << "\n";

	//Bottom border
	cout << string(totalWidth, '=') << "\n\n";
}

/**
 * @brief Displays the program header with ASCII art and a welcome message.
 *
 * Prompts the user to start the game.
 */
void Chess::displayHeader() const
{
	//ASCII art __By Alefith 22.02.95__
	cout << R"(
                                                        ::
                                            _()_       _::_
                                  _O      _/____\_   _/____\_
           _  _  _     ^^__      / //\    \      /   \      /
          | || || |   /  - \_   {     }    \____/     \____/
          |_______| <|    __<    \___/     (____)     (____)
    _     \__ ___ / <|    \      (___)      |  |       |  |
   (_)     |___|_|  <|     \      |_|       |__|       |__|
  (___)    |_|___|  <|______\    /   \     /    \     /    \
  _|_|_    |___|_|   _|____|_   (_____)   (______)   (______)
 (_____)  (_______) (________) (_______) (________) (________)
 /_____\  /_______\ /________\ /_______\ /________\ /________\
    )" << "\n";
	
	//Prompt user to start the program.
	cout << "Welcome to the Chess Game! Press any key to start...\n";
	cin.get();
}

/**
 * @brief Displays the main menu and handles user navigation.
 *
 * The main menu allows the user to:
 * - Start a game.
 * - View program information.
 * - Exit the program.
 */
void Chess::mainMenu()
{
	//Variable to store the user's menu selection.
	int choice;

	//Main menu loop
	while (true)
	{
		//Print out menu name
		menuName("Main Menu");

		//Display menu options
		cout << "1. Start a Game\n";
		cout << "2. About\n";
		//cout << "3. Options\n";
		cout << "0. Quit\n";


		while (true)
		{
			cout << "Enter your choice: ";
			if (!(cin >> choice) || choice > 2 || choice < 0)
			{
				cin.clear(); //Clear the error state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore any remaining invalid input
				cout << "Invalid input. Please enter a number from 0 to 2.\n";
			}
			//Valid input
			else
			{
				break;
			}
		}

		//Choices
		switch (choice)
		{
		case 1:
			gameMenu();
			break;

		case 2:
			aboutMenu();
			break;

		case 0:
			cout << "\nThanks for playing. Good bye!\n";
			return;

		default:
			cout << "Invalid input. Enter a valid choice (0 to 2.)";
			break;
		}
	}
}

/**
 * @brief Displays the game menu and handles game mode selection.
 *
 * Currently supports Free Play mode. Future updates will add more modes.
 */
void Chess::gameMenu()
{
	int choice;		//Variable to store the user's menu selection.

	//Main menu loop
	while (true)
	{
		//Print out menu name
		menuName("Game Menu");

		//Display menu options
		cout << "1. Free Play\n";
		//cout << "2. 1v1\n";
		//cout << "3. 1vBot\n";
		cout << "0. Back to main menu\n";


		while (true)
		{
			cout << "Choose game mode: ";
			if (!(cin >> choice) || choice > 1 || choice < 0)
			{
				cin.clear(); //Clear the error state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore any remaining invalid input
				cout << "Invalid input. Please enter a number from 0 to 1.\n";
			}
			else
			{
				//Valid input
				break; 
			}
		}

		//Choices
		switch (choice)
		{
		case 1:
			freePlay();
			break;

		case 0:
			return;

		default:
			cout << "Invalid input. Enter a valid choice (0 to 1.)";
			break;
		}
	}
}

/**
 * @brief Parses chess notation into a Position object.
 *
 * Converts a string like "e4" into the corresponding row and column indices.
 *
 * @param notation The chess notation string to parse.
 * @return A Position object representing the parsed location.
 */
Position Chess::parseChessNotation(const string& notation) const 
{
	int col = notation[0] - 'a';          //Convert 'a'-'h' to 0-7
	int row = (notation[1] - '0') - 1;	  //Convert to zero index
	return Position(row, col);
}

/**
 * @brief Converts a Position object into chess notation.
 *
 * Converts board indices into human-readable chess notation (e.g., "e4").
 *
 * @param pos The Position object to convert.
 * @return A string representing the chess notation.
 */
string Chess::formatChessNotation(const Position& pos) const 
{
	char col = 'a' + pos.getCol();        //Convert 0-7 to 'a'-'h'
	char row = '1' + pos.getRow();        //Convert to zero index
	return string(1, col) + string(1, row);
}


/**
 * @brief Starts the Free Play mode.
 *
 * Allows the user to move pieces freely and view legal moves for each piece.
 */
void Chess::freePlay() 
{
	//Instructions and mode information
	cout << "\nInstructions:\n";
	cout << ". Enter a position (e.g., 'e2') to see the legal moves for a piece.\n";
	cout << ". Enter a move command (e.g., 'e2e4') to move a piece.\n";
	cout << ". Enter 'q' at any time to quit the game.\n";
	cout << string(50, '=') << "\n";

	while (true) 
	{
		cout << "\n";

		//Display the board
		chessBoard.displayBoard();

		//Prompt the user
		cout << "\nEnter your move ('e2' for legal moves, 'e2e4' to move, or 'q' to quit): ";
		string input;
		cin >> input;

		if (input == "q") 
		{
			cout << "\nExiting Free Play Mode.\n";

			//Reset the board after quitting
			chessBoard.initializeBoard();
			break;
		}

		if (input.length() == 2) 
		{
			Position pos = parseChessNotation(input);
			const ChessPiece* piece = chessBoard.getPieceAt(pos.getRow(), pos.getCol());

			if (!piece) 
			{
				cout << "\nNo piece at " << input << ". Try again.\n";
			}
			else 
			{
				cout << "\n";
				chessBoard.displayLegalMoves(pos);
				cout << "\nLegal moves for " << input << ": ";
				vector<Position> moves = piece->getLegalMoves(chessBoard);
				for (const Position& move : moves) 
				{
					cout << formatChessNotation(move) << " ";
				}
				cout << endl;
			}
		}
		else if (input.length() == 4) 
		{
			Position from = parseChessNotation(input.substr(0, 2));
			Position to = parseChessNotation(input.substr(2, 2));
			ChessPiece* piece = const_cast<ChessPiece*>(chessBoard.getPieceAt(from.getRow(), from.getCol()));

			if (!piece) 
			{
				cout << "\nNo piece at " << input.substr(0, 2) << ". Try again.\n";
			}
			else 
			{
				vector<Position> moves = piece->getLegalMoves(chessBoard);
				if (find(moves.begin(), moves.end(), to) != moves.end()) 
				{
					chessBoard.movePiece(from, to);
					cout << "\nMoved " << piece->getSymbol() << " to " << input.substr(2, 2) << ".\n";
				}
				else 
				{
					cout << "\nIllegal move for " << piece->getSymbol() << ". Try again.\n";
				}
			}
		}
		else 
		{
			cout << "\nInvalid input. Try again.\n";
		}
	}
}

/**
 * @brief Displays the About menu.
 *
 * Provides details about the program, its purpose, and its features.
 */
void Chess::aboutMenu()
{
	//Print Menu name
	menuName("About This Program");

	//Program information 
	cout << "Program Name: The Chess Game\n";
	cout << "Version: 0.1.0\n";
	cout << "Developer: Qusay Edkymish\n";

	//Purpose of the program
	cout << "\nPurpose:\n";
	cout << "- This program is the final project for the CSIS-297 Intermediate C++ Programming course at Grossmont College.\n";
	cout << "- It demonstrates the application of object-oriented programming principles, including inheritance, polymorphism, and encapsulation.\n";
	cout << "- The project serves as both a learning experience and a functional chess game simulation.\n";
	cout << "- It applies concepts learned throughout the semester, building on skills developed in previous projects.\n";

	//Features of the program
	cout << "\nFeatures:\n";
	cout << "- Full implementation of chess rules for all pieces (Pawn, Rook, Knight, Bishop, Queen, King).\n";
	cout << "- Accurate handling of legal moves, including diagonal captures and two-step pawn moves.\n";
	cout << "- Board visualization with an intuitive interface.\n";
	cout << "- Support for Free Play mode.\n";
	cout << "- Modular design that separates game logic from the UI.\n";	

	//Upcoming features for program
	cout << "\nUpcoming Features:\n";
	cout << "- Add a colorful, visually appealing interface to enhance user experience.\n";
	cout << "- Support for 1v1 multiplayer mode and AI-based opponents.\n";
	cout << "- Add an undo/redo system for moves.\n";
	cout << "- Add check mate move, and special move like: En passant, pawn promotion logic, and castling.\n";
	cout << "- Advanced options menu for customization (e.g., board colors, timer settings).\n";
	cout << "- Save and load game functionality for ongoing matches.\n";
	cout << "- And more.....\n";

	//End of the About menu
	cout << "\nThank you for playing the Chess Game. Enjoy your experience!\n\n";
}

/**
 * @brief Destructor for the Chess class.
 *
 * Cleans up resources and finalizes the game.
 */
Chess::~Chess() {}