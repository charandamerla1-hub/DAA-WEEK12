#include <iostream>
using namespace std;

int board[10][10], n;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

void solve(int row) {
    if (row == n) {
        print();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "Enter N: ";
    cin >> n;
    solve(0);
    return 0;
}
