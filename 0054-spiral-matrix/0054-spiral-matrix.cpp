class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int cstart=0, cend=matrix[0].size()-1;
        int rstart=0, rend=matrix.size()-1;
        int net = (cend+1)*(rend+1);
        while(spiral.size() != net)
        {
            for(int i = cstart;i <= cend;i++)
                if(rstart <= rend)
                    spiral.push_back(matrix[rstart][i]);
            rstart++;
            for(int j = rstart;j <= rend;j++)
                if(cstart <= cend)
                    spiral.push_back(matrix[j][cend]);
            cend--;
            for(int i = cend;i >= cstart;i--)
                if(rstart <= rend)
                    spiral.push_back(matrix[rend][i]);
            rend--;
            for(int j = rend;j >= rstart;j--)
                if(cstart <= cend)
                    spiral.push_back(matrix[j][cstart]);
            cstart++;    
        }
        return spiral;
    }
};