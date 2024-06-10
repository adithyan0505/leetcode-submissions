int heightChecker(int* heights, int heightSize) {
    int max = heights[0];
    for(int i=1;i < heightSize;i++)
        if(max < heights[i])
            max = heights[i];
    int count[max+1];
    for(int i=0;i < max+1;i++)
        count[i] = 0;
    for(int i=0;i < heightSize;i++)
        count[heights[i]]++;
    for(int i=1;i <= max;i++)
        count[i] += count[i-1];
    int expected[heightSize];
    for(int i=0;i < heightSize;i++)
        expected[--count[heights[i]]] = heights[i];
    int c = 0;
    for(int i=0;i < heightSize;i++)
        if(heights[i] != expected[i])
            c++;
    return c;
}