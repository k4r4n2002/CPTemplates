/cache friendly
const int N =1000;
const int M = 10;
#define ll int
ll tab[M+1][M+1][N+1][N+1];
ll L[N+1];
ll a[N+1][N+1];
ll s[N+1][N+1];
 
//ll [N+1][N+1];
 
struct st2{
    int n,m;
 
    st2(ll _n,ll _m){
        n=_n;
        m=_m;
        for(ll i=2;i<=N;i++){
            L[i]=L[i/2]+1;
        }
    }
 
    int f(ll x,ll y,ll z=0,ll w=0){
        return max({x,y,z,w});
    }
 
    void build(){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                tab[0][0][i][j]=a[i][j];
            }
        }
 
        for(ll y=1;y<=M;y++){
            for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                    if(j+(1<<y)-1<m)
                        tab[0][y][i][j]=f(tab[0][y-1][i][j],tab[0][y-1][i][j+(1<<(y-1))]);
                }
            }
        }
 
        for(ll x=1;x<=M;x++){
            for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                    if(i+(1<<x)-1<n)
                        tab[x][0][i][j]=f(tab[x-1][0][i][j],tab[x-1][0][i+(1<<(x-1))][j]);
                }
            }
        }
 
        for(ll x=1;x<=M;x++){
            for(ll y=1;y<=M;y++){
                for(ll i=0;i<n;i++){
                    for(ll j=0;j<m;j++){
                        if(i+(1<<x)-1<n && j+(1<<y)-1<m){
                            tab[x][y][i][j]=f(
                                    tab[x-1][y-1][i][j],
                                    tab[x-1][y-1][i+(1<<(x-1))][j],
                                    tab[x-1][y-1][i][j+(1<<(y-1))],
                                    tab[x-1][y-1][i+(1<<(x-1))][j+(1<<(y-1))]
                                    );
                        }
                    }
                }
            }
        }
    }
 
    int qry_i(ll x,ll y,ll _x,ll _y){
 
        ll lx=L[_x-x+1];
        ll ly=L[_y-y+1];
 
        return f(
                tab[lx][ly][x][y],
                tab[lx][ly][_x-(1<<lx)+1][y],
                tab[lx][ly][x][_y-(1<<(ly))+1],
                tab[lx][ly][_x-(1<<lx)+1][_y-(1<<(ly))+1]
                );
 
    }
 
};
 