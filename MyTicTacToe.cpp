#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class TicTacToe {
private:
    int board[3][3];

public:
    TicTacToe() {
        clearBoard();
    }

    void clearBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }
    }

    string to_string() const {
        string result;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result += std::to_string(board[i][j]);

                if (j < 2) {
                    result += " | ";
                }
            }

            result += '\n';

            if (i < 2) {
                result += "----------\n";
            } else if (i < 2 * 2) {
                result += "\n";
            }
        }

        return result;
    }

    int gameStatus() const {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
                return board[i][0];
            }

            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
                return board[0][i];
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
            return board[0][0];
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
            return board[0][2];
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    return 0;
                }
            }
        }

        return 3;
    }

    bool move(int player, int row, int col) {
        if (board[row][col] == 0) {
            board[row][col] = player;
            return true;
        } else {
            return false;
        }
    }

    void autoMove(int player) {
        int row, col;

        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (board[row][col] != 0);

        board[row][col] = player;
    }
};

int main() {
    srand(time(0));  

    TicTacToe game;
    int currentPlayer = 1;

    while (game.gameStatus() == 0) {
        cout << game.to_string();

        if (currentPlayer == 1) {
            int row, col;
            cout << "Player 1, enter your move with a space in the middle (row and column): ";
            cin >> row >> col;

            if (game.move(1, row, col)) {
                currentPlayer = 2;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        } else {
            game.autoMove(2);
            currentPlayer = 1;
        }

        
    }

    cout << game.to_string();

    int status = game.gameStatus();

    if (status == 1) {
        cout << "Player 1 wins!\n";
    } else if (status == 2) {
        cout << "Player 2 (computer) wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}
