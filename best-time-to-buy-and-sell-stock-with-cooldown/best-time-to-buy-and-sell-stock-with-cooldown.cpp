class Solution {
public:
//     struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const
//     {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };
    
//      unordered_map<pair<int, bool> , int, hash_pair> dp;
    
//      int dfs(int i, bool buy, vector<int>& prices)
//         {
//             if(i>= prices.size())
//             {
//                 return 0;
//             }
//             if(dp.find((i, buy)) != dp.end())
//             {
//                 return dp[(i, buy)];
//             }
//             int cooldown = dfs(i+1, buy, prices);
            
//             if(buy)
//             {
//                 int buying = dfs(i+1, not buy, prices) -prices[i];
//                 dp[(i, buy)] = max(buying, cooldown);
//             }
//             else
//             {
//                 selling = dfs(i+2, not buy, prices) + prices[i];
//                 dp[(i, buy)] = max(selling, cooldown);   
//             }
//             return dp[(i, buy)];
//         }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
       
        
       
        // return dfs(0, True, prices);
        
    
    }
};