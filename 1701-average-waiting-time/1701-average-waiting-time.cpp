class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = customers[0][0], update;
        double wait = 0;
        for(auto cust: customers)
        {
            update = max(time,cust[0]) + cust[1];
            wait += update - cust[0];
            time = update;
        }
        return wait / customers.size();
    }
};