class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool flag = true;
        int dy = coordinates[1][1]-coordinates[0][1], dx = coordinates[1][0] - coordinates[0][0];
        for(int i=2;i<coordinates.size();i++)
        {
            if(dx*(coordinates[i][1] - coordinates[0][1]) != dy*(coordinates[i][0] - coordinates[0][0]))
            {
                flag = false;
                break;
            } 
        }
        return flag;
    }
};