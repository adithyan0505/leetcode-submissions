class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int size = garbage.size(), travel_size = travel.size();
        for(int i = 1;i < travel_size;i++)
            travel[i] += travel[i-1];
        int timeM,timeP,timeG;
        timeM = timeP = timeG = 0;
        for(int i = size-1;i >= 0;i--)
        {
            for(char ch: garbage[i])
            {
                if(ch=='M'){
                    if(timeM == 0 && i!=0)
                        timeM += travel[i-1];
                    timeM++;
                }
                else if(ch=='P'){
                    if(timeP == 0 && i!=0)
                        timeP += travel[i-1];
                    timeP++;
                }
                else if(ch=='G'){
                    if(timeG == 0 && i!=0)
                        timeG += travel[i-1];
                    timeG++;                    
                }
            }
        }
        return (timeM+timeP+timeG);
    }
};