class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // TC : O(1) ; SC : O(1)
        vector<unordered_set<int>> vertical(9);
        vector<vector<unordered_set<int>>> sub(3, vector<unordered_set<int>> (3));
        for(int i=0;i<9;i++) {
            unordered_set<int> horizontal;
            for(int j=0;j<9;j++) {
                if(!isdigit(board[i][j]))
                    continue;
                int digit = board[i][j] - '0';
                if(horizontal.find(digit) != horizontal.end())
                    return false;
                horizontal.insert(digit);
                if(vertical[j].find(digit) != vertical[j].end())
                    return false;
                vertical[j].insert(digit);
                int h = floor(i/3), k = floor(j/3);
                if(sub[h][k].find(digit) != sub[h][k].end())
                    return false;
                sub[h][k].insert(digit);
            }
        }
        return true;
    }
};