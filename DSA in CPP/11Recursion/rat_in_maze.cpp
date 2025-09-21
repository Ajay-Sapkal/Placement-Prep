#include <iostream>
#include <vector>
using namespace std;

// Function to solve the rat in a maze problem
void solveMaze(vector<vector<int>>& maze, int row, int col, vector<string>& ans ,string path) {

    int n = maze.size();

    
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || maze[row][col] == -1)
    {
        return;
    }
    
    if (row == n-1 && col == n-1)
    {
        ans.push_back({path});
        return;
    }

    maze[row][col] = -1;

    solveMaze(maze, row+1, col, ans, path + "D");
    solveMaze(maze, row, col+1, ans, path + "R");
    solveMaze(maze, row-1, col, ans, path + "U");
    solveMaze(maze, row, col-1, ans, path + "L");

    maze[row][col] = 1;

}

int main() {
    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    // vector<vector<bool>> vis(n, vector(n, false));
    vector<string> ans;
    string path;
    solveMaze(maze, 0, 0, ans, path);

    cout << "Paths found: \n";
    for (const string& path : ans) {
        cout << path << endl;
    }

    return 0;
}
