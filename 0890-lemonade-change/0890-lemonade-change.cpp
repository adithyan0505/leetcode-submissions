class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        bool out = true;
        for(int bill: bills)
        {
            if(bill==5)
                five++;
            else if(bill==10)
            {
                ten++;
                if(five!=0)
                    five--;
                else
                {
                    out = false;
                    break;
                }
            }
            else if(bill==20)
            {
                if(ten!=0)
                {
                    if(five!=0)
                    {
                        five--;
                        ten--;
                    }
                    else
                    {
                        out = false;
                        break;
                    }
                }
                else if(five>=3)
                    five-=3;
                else
                {
                    out = false;
                    break;
                }
            }
        }
        return out;
    }
};