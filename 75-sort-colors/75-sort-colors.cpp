class Solution {
public:
    void sortColors(vector<int>& A) {
       int i =0, twos = A.size()-1, ones =0;
        while(i<= twos)
        {
            while(A[i] == 2 and i< twos)
            {
                swap(A[i], A[twos]);
                twos--;
            }
            while(A[i] ==0 and i>ones)
            {
                swap(A[i], A[ones]);
                ones++;
            }
            
            i++;
            // for(auto it: A)
            // {
            //     cout <<it<<" ";
            // }
            // cout <<endl;
        }
            
    }
};