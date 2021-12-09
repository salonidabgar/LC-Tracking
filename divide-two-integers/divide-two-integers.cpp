class Solution {
public:
    int divide(int dividend, int divisor) {
//         if(!dividend) return 0;
        
//         if(dividend == 1<<31 and divisor == -1) return INFINITY;
        
//         bool sign = (dividend>=0) == (divisor>=0)? true:false;
//         dividend = abs(dividend);
//         divisor = abs(divisor);
//         int result;
        
//         while(dividend - divisor>=0)
//         {
//             int count =0;
            
//             while(dividend-(divisor<<1<<count) >=0){
//                 count++;
//             }
//             result += 1<< count;
//             dividend -= divisor<< count;
//         }
        
//         return sign?result: -result;
//         if(dividend == 1<<31 && divisor == -1) return INT_MAX;
        
//         bool sign = (dividend>=0) == (divisor >=0) ? true : false;
        
//         dividend = abs(dividend);
//         divisor = abs(divisor);
//         int result=0;
//         while(dividend - divisor >= 0 ){
//             int count=0;
//             while(dividend  - (divisor << 1 << count) >= 0 ){
//                 count++;
//             }
            
//             result += 1 << count;
//             dividend -= divisor << count ;
//         }
        
//         return sign?result: -result ;
       
         if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};