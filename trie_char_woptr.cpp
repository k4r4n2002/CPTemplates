struct node{
    map<char, ll> m;
    bool end=0;
};
struct Trie{
    node a[100100];
    ll ptr=2;
    void insert(string s){
        ll curr=1;
        for(auto& child: s){
            if(a[curr].m.count(child)){
                curr=a[curr].m[child];
            }
            else {
                a[curr].m[child]=ptr;
                ptr++;
                curr=a[curr].m[child];
            }
        }
        a[curr].end=1;
    }
    bool search(string s){
        ll curr=1;
        for(auto& child: s){
            if(! a[curr].m.count(child)) return 0;
            curr=a[curr].m[child];
        }
        return a[curr].end;
    }
    bool startsWith(string s){
        ll curr=1;
        for(auto& child: s){
            if(! a[curr].m.count(child)) return 0;
            curr=a[curr].m[child];
        }
        return 1;
    }
};