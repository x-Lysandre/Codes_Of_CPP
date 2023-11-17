#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canMove(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> maze)
{
    /*for rat to be able to move we have 3 conditions (next step):
    1.it should be inside the maze.
    2.maze should allow that move(i.e it should be 1).
    3.visited matrix of correspondig should be 0.
    */
    if ((x < n ) && (y < n ) && x >= 0 && y >= 0 && visited[x][y] == 0 && maze[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solution(vector<vector<int>> maze, int x, int y, int n, string path, vector<string> &ans, vector<vector<int>> & visited)
{

   
    // base case
    if (x == (n - 1) && y == (n - 1))
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;
    // moving left
    int newX = x;
    int newY = y - 1;
    if (canMove(newX, newY, n, visited, maze))
    {
        path.push_back('L');
        solution(maze, newX, newY, n, path, ans, visited);
        path.pop_back();
    }

    // moving right
    newX = x;
    newY = y + 1;
    if (canMove(newX, newY, n, visited, maze))
    {
        path.push_back('R');
        solution(maze, newX, newY, n, path, ans, visited);
        path.pop_back();
    }

    // moving down
    newX = x + 1;
    newY = y;
    if (canMove(newX, newY, n, visited, maze))
    {
        path.push_back('D');
        solution(maze, newX, newY, n, path, ans, visited);
        path.pop_back();
    }

    // moving up
    newX = x - 1;
    newY = y;
    if (canMove(newX, newY, n, visited, maze))
    {
        path.push_back('U');
        solution(maze, newX, newY, n, path, ans, visited);
        path.pop_back();
    }
    visited[x][y] = 0;
}

int main()
{

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    // starting point
    int srcx = 0;
    int srcy = 0;

    // size of the maze 4x4
    int n = 4;

    // if the iniial position has a 0 then the rat can't start
    if (maze[srcx][srcy] == 0)
    {
        return -1;
    }
    
    vector<string> ans;
    string path = "";

    // creating an array which will keep track of already visited places
    vector<vector<int>> visited(n, vector<int>(n, 0));

    solution(maze,srcx,srcy,n,path,ans,visited);

    cout << "The answer is : " << endl;
    for (string i : ans)
    {
        cout << i << " ";
    }
}