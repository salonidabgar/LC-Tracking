class Solution {
public:
    int reachNumber(int target) {
        int sum =0, nummoves =0, i=1, tar = abs(target);
        while(i)
        {
            // cout << sum <<" "<< nummoves<< endl;
            sum += i;
            nummoves++;
            i++;
            if(sum >= tar and (sum - tar) %2 == 0)
            {
                
                break;
            }
        }
        return nummoves;
    }
};