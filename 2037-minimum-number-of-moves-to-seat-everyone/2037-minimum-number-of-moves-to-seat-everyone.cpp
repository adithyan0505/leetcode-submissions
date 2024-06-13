class Solution {
public:
    vector<int> count_sort(vector<int>& arr){
        int max = arr[0];
        for(int num: arr)
            if(num > max)
                max = num;
        vector<int> count(max+1,0);
        for(int num: arr)
            count[num]++;
        for(int i = 1;i <= max;i++)
            count[i] += count[i-1];
        vector<int> out(arr.size(),-1);
        for(int num: arr)
            out[--count[num]] = num;
        return out;
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        seats = count_sort(seats);
        students = count_sort(students);
        int moves = 0, size = seats.size();
        for(int i = 0;i < size;i++)
            moves += abs(seats[i] - students[i]);
        return moves;
    }
};