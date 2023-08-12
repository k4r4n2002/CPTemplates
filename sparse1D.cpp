const long long N=100001;
const long long M=21;
 
ll tab[N+1][M+1];
ll arr[N+1];
ll L[N+1];
struct sparsetable{
    ll n;
    sparsetable(ll _n){
        n=_n;
    }
    ll f(ll x, ll y){
        // function, it can be anything
        return gcd(x, y);
    }
    void build(){
        for(int i=2;i<=N;i++) L[i]=L[i/2]+1;
        fl(i,n){
            tab[i][0]=arr[i];
        }
        for(int j=1;j<=M;j++){
            for(int i=0;i<n;i++){
                if(i+(1<<j)-1<n){
                    tab[i][j]= f(tab[i][j-1], tab[i+(1<<(j-1))][j-1]);
                }
            }
        }
    }
    // non-idempotent query- not recommended, segtree better for this
    ll niquery(ll l, ll r){
        ll len=r-l+1;
        ll idx=l;
        // neutral element
        ll tot=0; // coz we took minimum as function
        for(int j=M;j>=0;j--){
            if(len&(1<<j)){
                tot= f(tot, tab[idx][j]);
                idx+=(1<<j);
            }
        }
        return tot;
    }
 
    // idempotent query
    ll iquery(ll l, ll r){
        ll lg= L[r-l+1];
        return f(tab[l][lg], tab[r-(1<<lg)+1][lg]);
    }
};
 
 