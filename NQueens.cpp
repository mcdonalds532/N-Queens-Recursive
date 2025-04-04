#include "NQueens.h"

void NQueens::run()
{
    while(true)
    {
        int n;
        std::cout << "Enter a value for n: ";
        std::cin >> n;
        solveNQueens(n);
    }
}

void NQueens::solveNQueens(const int& n)
{
    // Initialize the 2D grid to all empty tiles, represented by 0s.
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
    backtrack(grid, 0, n);
}

void NQueens::backtrack(std::vector<std::vector<int>>& grid, const int& row, const int& n)
{
    // Stop condition: if there is a call made to backtrack where row == n, then all the queens have been placed so the write/print function is called.
    if(row == n)
    {
        write(grid);
        return;
    }
    for(int col = 0; col < n; col++)
    {
        if(place(row - col, row + col, col))
        {
            grid[row][col] = 1;
            positiveDiagonal.insert(row - col);
            negativeDiagonal.insert(row + col);
            columns.insert(col);
            backtrack(grid, row + 1, n);
            grid[row][col] = 0;
            positiveDiagonal.erase(row - col);
            negativeDiagonal.erase(row + col);
            columns.erase(col);
        }
    }
}

bool NQueens::place(const int& pd, const int& nd, const int& col) const
{
    // .contains only works on C++20!
    return !(positiveDiagonal.contains(pd) || negativeDiagonal.contains(nd) || columns.contains(col));
}

void NQueens::write(const std::vector<std::vector<int>>& grid)
{
    for(const auto& row : grid)
    {
        for(const auto& tile : row)
        {
            // If it is a 0, then print an empty tile.
            if(!tile)
                std::cout << "[ ]";
            // Otherwise print a tile with a queen.
            else
                std::cout << "[Q]";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}