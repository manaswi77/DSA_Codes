#include <bits/stdc++.h>
using namespace std;

bool isPositionSafe(const vector<int> &queenPositions, int currentRow, int currentCol)
{
    for (int col = 0; col < queenPositions.size(); ++col)
    {
        int placedRow = queenPositions[col];
        int placedCol = col + 1;

        if (abs(placedRow - currentRow) == abs(placedCol - currentCol))
        {
            return false;
        }
    }

    return true;
}

void solveNQueens(int col, int n, vector<int> &queenPositions,
                  vector<vector<int>> &solutions, vector<bool> &rowUsed)
{
    if (col > n)
    {
        solutions.push_back(queenPositions);
        return;
    }

    for (int row = 1; row <= n; ++row)
    {
        if (!rowUsed[row] && isPositionSafe(queenPositions, row, col))
        {
            rowUsed[row] = true;
            queenPositions.push_back(row);

            solveNQueens(col + 1, n, queenPositions, solutions, rowUsed);

            queenPositions.pop_back();
            rowUsed[row] = false;
        }
    }
}

vector<vector<int>> findNQueensSolutions(int n)
{
    vector<vector<int>> solutions;
    vector<int> queenPositions;
    vector<bool> rowUsed(n + 1, false);

    solveNQueens(1, n, queenPositions, solutions, rowUsed);
    return solutions;
}

int main()
{
    int n = 4;

    vector<vector<int>> solutions = findNQueensSolutions(n);

    for (const auto &solution : solutions)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            cout << solution[i];
            if (i != n - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
