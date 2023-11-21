
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

#define kd 1;

// Speed
//  #define Code ios_base::sync_with_stdio(false);
//  #define By cin.tie(NULL);
//  #define Asquare cout.tie(NULL);

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()

// Debug
#ifdef kd
#define debug(x)       \
    cerr << #x << " "; \
    cerr << x << " ";  \
    cerr << endl;
#else
#define debug(x) ;
#endif

// Mathematical functions
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Graph-dfs
//  bool gone[MN];
//  vector<int> adj[MN];
//  void dfs(int loc){
//      gone[loc]=true;
//      for(auto x:adj[loc])if(!gone[x])dfs(x);
//  }

// Sorting
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Bits
string decToBinary(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

// Check
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
// Graphs


vpll v[200001];
vll dis(200001, mod);

void Dijkstra(ll n)
{
    priority_queue<pll, vector<pll>, greater<pll>> pq; // dis, node
    pq.push({0, n});

    while (!pq.empty())
    {

        pll j = pq.top();
        pq.pop();
        for (auto c : v[j.second])
        {
            if (dis[c.first] > j.first + c.second)
            {
                dis[c.first] = j.first + c.second;
                pq.push({dis[c.first], c.first});
            }
        }
    }
}

vll g[200100];
void graph(ll n, ll m){
    fl(i,m){
        ll u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

class DSU
{
    vector<ll> rank, size, par;

public:
    DSU(ll n)
    {
        rank.resize(n + 3);
        par.resize(n + 3);
        size.resize(n + 3);
        fl(i, n + 1)
        {
            par[i] = i;
            size[i] = 1;
        }
    }
    ll find(ll node)
    {
        if (node == par[node])
            return node;
        return par[node] = find(par[node]);
    }

    void union_size(ll u, ll v)
    {
        ll ultimatepar_u = find(u);
        ll ultimatepar_v = find(v);
        if (ultimatepar_u == ultimatepar_v)
            return;
        if (size[ultimatepar_u] < size[ultimatepar_v])
        {
            par[ultimatepar_u] = ultimatepar_v;
            size[ultimatepar_v] +=size[ultimatepar_u];
        }
        else
        {
            par[ultimatepar_v] = ultimatepar_u;
            size[ultimatepar_u] +=size[ultimatepar_v];
        }
    }
    void union_rank(ll u, ll v)
    {
        ll ultimatepar_u = find(u);
        ll ultimatepar_v = find(v);
        if (ultimatepar_u == ultimatepar_v)
            return;
        if (rank[ultimatepar_u] < rank[ultimatepar_v])
        {
            par[ultimatepar_u] = ultimatepar_v;
            // size[ultimatepar_v]+size[ultimatepar_u];
        }
        else if (rank[ultimatepar_v] < rank[ultimatepar_u])
        {
            par[ultimatepar_v] = ultimatepar_u;
            // size[ultimatepar_v]+size[ultimatepar_u];
        }
        else
        {
            par[ultimatepar_v] = ultimatepar_u;
            // size[ultimatepar_u]+size[ultimatepar_v];
            rank[ultimatepar_u]++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        
    }
    // asquare();
    // fl(i,t) //Kickstart
    // {
    //     cout<<"Case #"<<i+1<<": ";
    //     asquare();
    //     cout<<"\n";
    // }
    return 0;
}
