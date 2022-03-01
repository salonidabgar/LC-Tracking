class Solution {
public:
    
    vector<int> countBits(int n) {
         vector<int> ans;
		
		// iterating fromt 0 to n
        for(int i = 0; i<=n; i++)
        {
			// sum is initialised as 0
            int sum = 0;
            int x =i;
			// while num not equals zero
            while(x!=0)
            {
				// we have to count 1's in binary representation of i, therefore % 2
                sum += x%2;
                x = x/2;
            }
			// add sum to ans vector
            ans.push_back(sum);
        }
		// return 
        return ans;
    }
};