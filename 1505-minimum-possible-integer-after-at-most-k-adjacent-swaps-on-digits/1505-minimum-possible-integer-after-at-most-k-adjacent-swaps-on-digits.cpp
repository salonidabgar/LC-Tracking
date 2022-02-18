class BIT{
public:
    int n;
    vector<int> nodes;
    
    BIT(int n){
        this->n = n;
        nodes = vector<int>(n+1);
    }
    
    void update(int i, int delta){
        ++i;
        while(i <= n){
            nodes[i] += delta;
            i += (i&-i);
        }
    }
    
    int query(int i){
        ++i;
        int sum = 0;
        
        while(i > 0){
            sum += nodes[i];
            i -= (i&-i);
        }
        
        return sum;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        vector<queue<int>> qs(10);
        int n = num.size();
        
        for(int i = 0; i < n; ++i){
            qs[num[i]-'0'].push(i);
        }
        
        string lhs;
        vector<bool> removed(n, false);
        BIT* tree = new BIT(n);
        
        while(k > 0){
            bool found = false;
            for(int d = 0; d <= 9; ++d){
                if(!qs[d].empty()){
                    int pos = qs[d].front();
                    int shifted = tree->query(pos-1);
                    if(pos - shifted <= k){
                        k -= pos-shifted;
                        tree->update(pos, 1);
                        qs[d].pop();
                        lhs += ('0'+d);
                        removed[pos] = true;
                        found = true;
                        break;
                    }
                }
            }
            if(!found) break;
        }
        
        string rhs;
        for(int i = 0; i < n; ++i){
            if(!removed[i]){
                rhs += num[i];
            }
        }
        
        return lhs + rhs;
    }
};