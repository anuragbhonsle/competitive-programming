#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
        if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false;
    }
    return true;
}

void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    solve(0, board, ans, n);

    for (auto& solution : ans) {
        for (auto& row : solution) cout << row << "\n";
        cout << "\n";
    }
}
