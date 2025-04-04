#ifndef NQUEENS_H
#define NQUEENS_H

#include <vector>
#include <iostream>
#include <unordered_set>

class NQueens
{
public:
    // Run function is an endless loop until user exits console.
    void run();
private:
    // Run function calls this function after receiving user input.
    void solveNQueens(const int& n);
    // Backtracking helper function
    void backtrack(std::vector<std::vector<int>>& grid, const int& row, const int& n);
    // Helper function checks if queen placement is valid.
    bool place(const int& pd, const int& nd, const int& col) const;
    // Function to print a solution.
    static void write(const std::vector<std::vector<int>>& grid);
    // Unordered sets to store which columns and diagonals are used for fast lookup.
    std::unordered_set<int> positiveDiagonal, negativeDiagonal, columns;
};

#endif //NQUEENS_H