class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min = arrays[0].front(), max = arrays[0].back(),
            size = arrays.size(), diff = 0, curr_diff;
        int curr_min, curr_max;
        for (int i = 1; i < size; i++) {
            curr_min = arrays[i].front(), curr_max = arrays[i].back();
            curr_diff = std::max(abs(max - curr_min), abs(curr_max - min));
            if (diff < curr_diff)
                diff = curr_diff;
            if (curr_min < min)
                min = curr_min;
            if (curr_max > max)
                max = curr_max;
        }
        return diff;
    }
};