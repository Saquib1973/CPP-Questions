class Solution
{
public:
    // @link : https://leetcode.com/problems/valid-sudoku/submissions/
    // @desc In this question we are creating a set of string so as to maintain a record as we have only a single data of the particular number in a row , col ,box .
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<string> s;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    string row = "row" + to_string(i) + board[i][j];
                    string col = "col" + to_string(j) + board[i][j];
                    string box = "box" + to_string((i / 3) * 3 + (j / 3)) + board[i][j];
                    if (s.find(row) == s.end() && s.find(col) == s.end() && s.find(box) == s.end())
                    {
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};