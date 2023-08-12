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