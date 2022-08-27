class Solution {
public:
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    int atMostK(vector<int>& A, int K) {
        int n = A.size();
        int i = 0,j=0, res = 0;
        unordered_map<int, int> count;
        while(j<n) {
            if (count[A[j]] ==0)
                K--;
                count[A[j]]++;
            
            while (K < 0) {
                count[A[i]]--;
                if (count[A[i]] ==0)
                    K++;
                i++;
            }
            j++;
            res += j - i + 1;
        }
        return res;
    }
};