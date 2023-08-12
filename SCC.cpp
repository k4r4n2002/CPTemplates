struct SCC
{
    ll n;
    vll g[100100], rg[100100], topsort, sccnum, sccs, vis;
    SCC(ll _n)
    {
        n = _n;
        vis.resize(n);
        sccnum.resize(n, -1);
    }
    void addedge(ll u, ll v)
    {
        g[u].pb(v);
        rg[v].pb(u);
    }
    void dfs(ll node)
    {
        vis[node] = 1;
        for (auto child : g[node])
        {
            if (!vis[child])
                dfs(child);
        }
        topsort.pb(node);
    }
    void rdfs(ll node, ll comp)
    {
        sccnum[node] = comp;
        for (auto child : rg[node])
        {
            if (sccnum[child] == -1)
            {
                rdfs(child, comp);
            }
        }
    }
    void solve(ll _N)
    {
        for (int i = 1; i <= _N; i++)
        {
            if (!vis[i])
                dfs(i);
        }
        reverse(vr(topsort));
        for (auto child : topsort)
        {
            if (sccnum[child] == -1)
            {
                rdfs(child, child);
                sccs.pb(child);
            }
        }
    }
};