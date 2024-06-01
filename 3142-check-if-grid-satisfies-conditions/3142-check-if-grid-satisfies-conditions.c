bool satisfiesConditions(int** grid, int row, int* colmn) {
    int col = colmn[0];
    if((row > 1)&&(col > 1))
    {
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(grid[i][j] == grid[i][j-1]) 
                    return false;
                if(grid[i][j] != grid[i-1][j])
                    return false;
            }
        }
    }
    else
    {
        if(row > 1)
        {
            for(int i=1;i<row;i++)
                if(grid[i][0] != grid[i-1][0])
                    return false;
        }
        else
        {
            for(int j=1;j<col;j++)
                if(grid[0][j-1] == grid[0][j])  
                    return false;
        }
    }
    return true;
}