#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool queenInDiagonal(const vector<vector<int>> &board, int row, int col) {
    // Check topleft-bottomright diagonal
    int i = row - 1;
    int j = col - 1;
    while(i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return true;
        }
        --i;
        --j;
    }

    i = row + 1;
    j = col + 1;
    while(i < board.size() && j < board[i].size()) {
        if (board[i][j] == 1) {
            return true;
        }
        ++i;
        ++j;
    }

    // Now check topRight - bottomLeft diagonal
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < board[i].size()) {
        if (board[i][j] == 1) {
            return true;
        }
        --i;
        ++j;
    }

    i = row + 1;
    j = col - 1;
    while (i < board.size() && j >= 0) {
        if (board[i][j] == 1) {
            return true;
        }
        ++i;
        --j;
    }

    return false;
}

vector<pair<int, int>> getCandidateQueenSpots(const vector<vector<int>> &board, 
                                                const vector<bool> &queenInRow,
                                                const vector<bool> &queenInCol) {
    vector<pair<int, int>> candidates;
    for (int i = 0; i < board.size(); ++i) {
        if (!queenInRow[i]) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (!queenInCol[j]) {
                    if (!queenInDiagonal(board, i, j)) {
                        candidates.push_back(make_pair(i, j));
                    }
                }
            }   
        }  
    }
    return candidates;
}

bool NQueens (vector<vector<int>> &board, vector<bool> &queenInRow, vector<bool> &queenInCol, int N) {
    // Each queen you place on the board will decrease the number of valid spaces for the next queen.
    // The worst possible outcome is if you place n - 1 queens on the board and there are no longer any more
    // valid spaces for a queen.
    // In that case, you need to go to the n - 1 queen step and place it on a differrent valid space and try 
    // again.

    // Base Case: this call to the function has N of 0, so all queens must have been placed.
    if (N == 0) {
        return true;
    }

    // Retrieve candidate spots. If there are no valid candidate spots, return false.
    vector<pair<int, int>> candidateSpots = getCandidateQueenSpots(board, queenInRow, queenInCol);
    if (candidateSpots.empty()) {
        return false;
    }

    // Iterate through the candidate spots
    for (int i = 0; i < candidateSpots.size(); ++i) {
        int r = candidateSpots[i].first;
        int c = candidateSpots[i].second;

        board[r][c] = 1;
        queenInRow[r] = true;
        queenInCol[c] = true;

        if (NQueens(board, queenInRow, queenInCol, N - 1)) {
            return true;
        } else {
            // After placing this queen, it seems somewhere in the next steps it failed, so try the next candidate.
            board[r][c] = 0;
            queenInRow[r] = false;
            queenInCol[c] = false;
        }
    }

    // All candidates have been iterated through, none were successful so return false.
    return false;
}

pair<int, int> getNextCell(const vector<vector<int>> &board, int row, int col)
{
    // Iterate for the remaining numbers in the row.
    for (int j = col; j < board[row].size(); ++j)
    {
        if (board[row][j] == 0)
        {
            return make_pair(row, j);
        }
    }
    
    // Now iterate through the rest of the board.
    for (int i = row; i < board.size(); ++i) 
    {
        for (int j = 0; j < board[i].size(); ++j) 
        {
            if (board[i][j] == 0)
            {
                return make_pair(i, j);
            }
        }
    }

    // row and col are already at the end
    return make_pair(-1, -1);
}

bool checkValidNumber(const vector<vector<int>> &board, int row, int col, int candidate)
{
    // Check the row
    for (int i = 0; i < board[row].size(); ++i) {
        if (board[row][i] == candidate) {
            return false;
        }
    }
    
    // Check the col
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][col] == candidate) {
            return false;
        }
    }

    // Check the 3x3 cell
    int cellCol = (col / 3) * 3;
    int cellRow = (row / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[cellRow + i][cellCol + j] == candidate) {
                return false;
            }
        }
    }

    return true;
}

vector<int> getCandidates(const vector<vector<int>> &board, int row, int col)
{
    vector<int> candidates;
    for (int i = 1; i <= 9; ++i)
    {
        if (checkValidNumber(board, row, col, i))
        {
            candidates.push_back(i);
        }
    }
    return candidates;
}

bool sudokuSolver(vector<vector<int>> &board, int row, int col)
{
    // return false if there are no possible candidates
    vector<int> candidates = getCandidates(board, row, col);
    if (candidates.empty()) {
        return false;
    }

    // iterate through candidates
    for (int i = 0; i < candidates.size(); ++i) {
        board[row][col] = candidates[i];

        // getNextCell returns -1 meaning we're at the end of the board.
        pair<int, int> nextCell = getNextCell(board, row, col);
        if (nextCell.first == -1) {
            return true;
        }

        // Recurse giving the next cell to fill
        if (!sudokuSolver(board, nextCell.first, nextCell.second)) {
            // if the recurse function returned false, candidates turned up empty, so this current stack has a bad num.
            board[row][col] = 0;
        } else {
            return true;
        }
    }
    
    // done iterating through all the candidates? didn't return anything? all candidates are bad.
    return false;
}

template <typename T>
void printStack(deque<T> s)
{
    for (int i = s.size() - 1; i >= 0; --i)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void printSentences(const string &str, int idx, const unordered_set<string> &dict, deque<string> &wordStack)
{
    // Base Case
    if (idx >= str.length())
    {
        printStack(wordStack);
        return;
    }
    // idx represents the first letter that we should try to form a word with.
    // loop through the rest of the letters, checking the dictionary to see if we get a word.
    for (int i = 1; i < str.length() - idx + 1; ++i)
    {
        // Substr is a word
        string subs = str.substr(idx, i);
        if (dict.find(subs) != dict.end())
        {
            wordStack.push_front(subs);
            printSentences(str, idx + i, dict, wordStack);
            wordStack.pop_front();
        }
    }

    return;
}

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

bool pathExistsFourDirectionsMemo(const vector<vector<int>> &maze, int row, int col, unordered_set<pair<int, int>, hash_pair> &s, unordered_map<pair<int, int>, bool, hash_pair> &m)
{
    // Base Case
    if (row >= maze.size() || col >= maze[0].size() || row < 0 || col < 0 || maze[row][col] == 1)
    {
        return false;
    }
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        return true;
    }

    // Add to current path
    s.insert(make_pair(row, col));

    // Recurse
    vector<pair<int, int>> nextSteps = {make_pair(row + 1, col), make_pair(row, col + 1), make_pair(row - 1, col), make_pair(row, col - 1)};
    for (int i = 0; i < nextSteps.size(); ++i)
    {

        // make sure this next step isn't going to go in a cycle.
        if (s.find(nextSteps[i]) == s.end())
        {

            // check the memo for already known bad paths
            if (m.find(nextSteps[i]) == m.end())
            {

                if (pathExistsFourDirectionsMemo(maze, nextSteps[i].first, nextSteps[i].second, s, m))
                {
                    return true;
                }
                else
                {
                    m[nextSteps[i]] = false;
                }
            }
        }
    }

    s.erase(make_pair(row, col));
    return false;
}

bool pathExistsTwoDirections(const vector<vector<int>> &maze, int row, int col)
{
    // Base Case
    if (row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1)
    {
        return false;
    }
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        return true;
    }

    // Recurse down
    return pathExistsTwoDirections(maze, row + 1, col) || pathExistsTwoDirections(maze, row, col + 1);
}

void printCoinCombinations(const vector<int> &coins, int startIdx, int target, deque<int> &buffer, int currSum)
{
    // Termination Cases
    if (currSum > target)
        return;

    if (currSum == target)
        print(buffer);

    // Find Candidates
    // Loop through the remaining coins
    for (int i = startIdx; i < coins.size(); ++i)
    {
        buffer.push_front(coins[i]);
        printCoinCombinations(coins, i, target, buffer, currSum + coins[i]);
        buffer.pop_front(coins[i]);
    }
}