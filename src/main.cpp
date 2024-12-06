//Qusay Edkymish
//Nov/17/2024
//Main source file for the Chess game project.

#include "Chess.h"

/**
 * @file main.cpp
 * @brief Entry point for the Chess game program.
 *
 * This file initializes the Chess game by creating a `Chess` object,
 * displaying the header, and starting the main menu.
 */

 /**
  * @brief Main function, the entry point of the Chess game program.
  *
  * This function initializes the `Chess` object, displays the program header,
  * and launches the main menu where the user can interact with the game.
  *
  * @return Returns 0 to indicate successful execution.
  */
int main()
{
    //Create a Chess object to manage the game
    Chess chess;

    //Display the welcome header
    chess.displayHeader();

    //Launch the main menu
    chess.mainMenu();

    //End the program
    return 0;
}
