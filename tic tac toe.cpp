#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Empty cell found, game is not a draw
            }
        }
    }
    return true; // No empty cell found, game is a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the chosen cell is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update the game board with the player's move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        gameWon = checkWin(board, currentPlayer);

        // Check if the game is a draw
        gameDraw = checkDraw(board);

        // Switch players for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (!gameWon && !gameDraw);

    // Display the final state of the board
    displayBoard(board);

    // Display the result of the game
    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }

    return 0;
}

