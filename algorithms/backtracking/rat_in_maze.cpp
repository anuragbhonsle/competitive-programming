#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y]);
}

void solve(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited, string path, vector<string>& ans, int n) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    if (isSafe(x + 1, y, maze, visited, n)) solve(x + 1, y, maze, visited, path + "D", ans, n);
    if (isSafe(x, y - 1, maze, visited, n)) solve(x, y - 1, maze, visited, path + "L", ans, n);
    if (isSafe(x, y + 1, maze, visited, n)) solve(x, y + 1, maze, visited, path + "R", ans, n);
    if (isSafe(x - 1, y, maze, visited, n)) solve(x - 1, y, maze, visited, path + "U", ans, n);

    visited[x][y] = 0; // backtrack
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;
    solve(0, 0, maze, visited, "", ans, n);

    for (string& path : ans) cout << path << "\n";
}
