#include <iostream>
#include <vector>

// Function declarations
void initializeBoard(std::vector<std::vector<char>>& board);
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col);
bool checkWin(const std::vector<std::vector<char>>& board, char currentPlayer);
bool checkDraw(const std::vector<std::vector<char>>& board);
void switchPlayer(char& currentPlayer);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    bool gameOn = true;

    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

        initializeBoard(board);
        displayBoard(board);

        while (gameOn) {
            int row, col;

            do {
                std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                std::cin >> row >> col;
            } while (!makeMove(board, currentPlayer, row, col));

            displayBoard(board);

            if (checkWin(board, currentPlayer)) {
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw(board)) {
                std::cout << "It's a draw!\n";
                break;
            }

            switchPlayer(currentPlayer);
        }

        gameOn = playAgain();

    } while (gameOn);

    std::cout << "Thanks for playing!\n";

    return 0;
}

void initializeBoard(std::vector<std::vector<char>>& board) {
    // Initialize the game board with empty spaces
    for (auto& row : board) {
        for (char& cell : row) {
            cell = ' ';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    // Display the current state of the game board
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col) {
    // Update the game board with the player's move
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        std::cout << "Invalid move. Try again.\n";
        return false;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char currentPlayer) {
    // Check if the current player has won
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;  // Check rows
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;  // Check columns
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;  // Check diagonal from top-left to bottom-right
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;  // Check diagonal from top-right to bottom-left
    }
    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    // Check if the game is a draw (all cells filled)
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  // If any cell is empty, the game is not a draw
            }
        }
    }
    return true;
}

void switchPlayer(char& currentPlayer) {
    // Switch turns between "X" and "O" players
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    // Ask if the players want to play another game
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
