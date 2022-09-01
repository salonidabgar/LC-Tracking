class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 =-1, num2=-1, c1=0,c2=0;
        for(auto e:nums)
        {
            if(e == num1) c1++;
            else if(e == num2) c2++;
            else if(c1==0)
            {
                num1 = e;
                c1 =1;
            }
            else if(c2==0)
            {
                num2 = e;
                c2 =1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        vector<int> v;
        for(auto e: nums)
        {
            if(e ==num1) c1++;
            else if( e == num2) c2++;
        }
        if(c1 > ceil(n/3)) v.push_back(num1);
        if(c2 > ceil(n/3)) v.push_back(num2);
        return v;
    }
};