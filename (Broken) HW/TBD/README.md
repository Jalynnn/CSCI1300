Tasks for the Instructions:

* srand(time(0)) should be used in the main function to avoid repeated "random" sequences
* I included a list of advisors to mention in the instructions in random_events.txt
* An additional predefined stat is experience

Completed:

# riddles.txt
* Removed rows from riddles that included topics we didn't teach such as pointers and exceptions.

# characters.txt
* Changed the character relevance to match DNA scientists
* Points remained the same
* However, I did change the stat titles including...
* * Age --> Experience
* * Strength --> Accuracy
* * Stamina --> Efficiency
* * Wisdom --> Insight
* * pridePoints --> discoveryPoints

# random_events.txt
* Every random event storyline was changed
* Points remained the same

# Tile.h
* No changes.

# Board.h
* Added comments for concepts we didn't teach including...
* * #ifndef / #define / #endif
* * static 
* Added comments to recall specific concepts including...
* * Composition
* * Constructors
* * Const

# Board.cpp
* Lines 1-23 Organization
* * Improved the flow of the preprocessor directives
* * Added comments to elaborate on specific preprocessor directives
* * Elaborated on each of the #define lines
* Included preprocessor directives that were not already there...
* * Using namespace std
* * #include<iostream>
* * #include<string>
* Complete Source File Organization
* * Reoganized the functions to match the header file. Does not influence code implementation since all functions were defined in the header files.
* * Added comments to separate the constructors from the public and private member functions
* Constructors
* * Previously there were two constructors, with the default commented out. The board is a single object that tracks all players (only ever two, never more or less). Thus, I created only one constructor that initializes both players.

## Board::initializeBoard()
* No functionality changes
* Only changes to the comments to add clarity

## Board::initializeTiles(int)
* No functionality changes
* Only changes to the comments to add clarity

## Board::displayTile(int, int)
* Changed the long if/else statements to a cleaner switch case statement
* Changes to the comments to add clarity

## Board::displayTrack(int)
* No changes

## Board::displayBoard()
* No changes

## Board::movePlayers(int)
* Was previously commented out -- Uncommented now
* No changes

## Board::getPlayerPosition(int)
* Was previously commented out -- Uncommented now
* No changes

# testBoard.cpp (New)
* Added a new file to test the board.cpp source file functions