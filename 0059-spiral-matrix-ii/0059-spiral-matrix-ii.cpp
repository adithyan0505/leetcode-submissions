class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n));
        int cstart=0, cend=n-1;
        int rstart=0, rend=n-1;
        int num = 1, net = n*n;
        while(num <= net)
        {
            for(int i = cstart;i <= cend;i++)
                if(num <= net)
                    matrix[rstart][i] = num++;
            rstart++;
            for(int j = rstart;j <= rend;j++)
                if(num <= net)
                    matrix[j][cend] = num++;
            cend--;
            for(int i = cend;i >= cstart;i--)
                if(num <= net)
                    matrix[rend][i] = num++;
            rend--;
            for(int j = rend;j >= rstart;j--)
                if(num <= net)
                    matrix[j][cstart] = num++;
            cstart++; 
        }
        return matrix;
    }
};