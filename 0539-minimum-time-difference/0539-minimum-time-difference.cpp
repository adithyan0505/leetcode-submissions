class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int size = timePoints.size();
        int h1, h2, m1, m2,minutes;
        int minimum = ((timePoints[size-1][0]*10+timePoints[size-1][1])*60+timePoints[size-1][3]*10+timePoints[size-1][4]) - ((timePoints[0][0]*10+timePoints[0][1])*60+timePoints[0][3]*10+timePoints[0][4]);
        minimum = std::min(minimum,1440-minimum);
        for (int i = 0; i < size - 1; i++) {
            h1 = timePoints[i][0] * 10 + timePoints[i][1];
            h2 = timePoints[i + 1][0] * 10 + timePoints[i + 1][1];
            m1 = timePoints[i][3] * 10 + timePoints[i][4];
            m2 = timePoints[i + 1][3] * 10 + timePoints[i + 1][4];
            minutes = ((m2 - m1) + (h2 - h1) * 60);
            minutes = std::min(minutes,1440-minutes);
            if (minutes < minimum)
                minimum = minutes;
        }

        return minimum;
    }
};