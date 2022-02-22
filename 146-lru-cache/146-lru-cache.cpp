class LRUCache {
public:
    class node
    {
        public:
        int key;
        int val; 
        node*next;
        node*prev;
        
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->next = head;
  
    }
    
    void addnode(node* add)
    {
        node* temp = head->next;
        add->next = temp;
        add->prev = head;
        head->next = add;
        temp->prev = add;
    }
    
    void delnode(node* del)
    {
        node* delprev = del->prev;
        node* delnext = del->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(m.find(key) != m.end())
        {
            node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            delnode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            node* existingnode = m[key];
            m.erase(key);
            delnode(existingnode);
        }
        if(m.size() == cap)
        {
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */