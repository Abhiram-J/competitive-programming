#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;

struct Dijkstra
{
    int n;
    vector<int> visited;
    vector<int> dist;
    vector<int> parent;
    vector<vector<pair<int, int>>> adj;

    Dijkstra(vector<vector<pair<int, int>>> adj, int n)
    {
        this->adj = adj;
        this->n = n;
        visited.resize(n, false);
        dist.resize(n, inf);
        parent.resize(n, -1);
    }

    vector<int> dijkstra(int start)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, start});
        dist[start] = 0;
        while (!q.empty())
        {
            int curr_u = q.top().second;
            q.pop();
            if (visited[curr_u])
                continue;
            visited[curr_u] = 1;

            for (auto &ele : adj[curr_u])
            {
                int curr_v = ele.first;
                int new_w = ele.second;
                if (!visited[curr_v] && dist[curr_u] + new_w < dist[curr_v])
                {
                    dist[curr_v] = dist[curr_u] + new_w;
                    parent[curr_v] = curr_u;
                    q.push({dist[curr_v], curr_v});
                }
            }
        }
        return dist;
    }
};

struct DSU
{
    vector<int> parent;
    DSU(int N) { parent = vector<int>(N, -1); }

    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }

    bool same_set(int a, int b) { return find(a) == find(b); }

    int size(int x) { return -parent[find(x)]; }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (parent[x] > parent[y])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

struct FloydWarshall
{

    int n;
    vector<vector<int>> dp;

    FloydWarshall(vector<vector<int>> dp, int n)
    {
        this->n = n;
        this->dp = dp;
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
    }

    vector<vector<int>> FW()
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dp[i][k] != inf && dp[k][j] != inf)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
        return dp;
    }
};

struct Prims
{

    int n;
    vector<int> dist;
    vector<int> visited;
    vector<vector<pair<int, int>>> adj;

    Prims(vector<vector<pair<int, int>>> adj, int n)
    {
        this->n = n;
        this->adj = adj;
        visited.resize(n, false);
        dist.resize(n, inf);
    }

    int P()
    {
        int u = 0;
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});

        while (!q.empty())
        {

            u = q.top().second;
            if (visited[u])
            {
                q.pop();
                continue;
            }
            q.pop();
            visited[u] = true;

            for (auto v : adj[u])
            {
                if (!visited[v.first])
                {
                    dist[v.first] = min(dist[v.first], v.second);
                    q.push({v.second, v.first});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == inf)
                return -1;
            else
                ans += dist[i];
        }
        return ans;
    }
};

struct Exponentiation
{

    int mod_expo(int a, int b, int mod)
    {
        if (b == 0)
            return 1;
        if (b == 1)
            return a;
        else if (b & 1)
        {
            int ans = mod_expo(a, b / 2, mod) % mod;
            return (((1LL * ans * ans) % mod) * a) % mod;
        }
        else
        {
            int ans = mod_expo(a, b / 2, mod) % mod;
            return (1LL * ans * ans) % mod;
        }
    }
};

struct Bipartite
{

    bool dfs(vector<vector<int>> &adj, int u, vector<int> &color)
    {
        bool ok = 1;
        for (int &v : adj[u])
        {
            if (color[v] == color[u])
                return false;
            if (color[v] == -1)
            {
                color[v] = !color[u];
                ok &= dfs(adj, v, color);
            }
        }
        return ok;
    }

    bool check_bipartite(vector<vector<int>> &adj, int n)
    {
        vector<int> color(n, -1);
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                ok &= dfs(adj, i, color);
            }
            if (!ok)
                return false;
        }
        return true;
    }
};

struct TopologicalSort
{
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<bool> present;
    vector<int> ans;

    TopologicalSort(vector<vector<int>> adj, int n)
    {
        this->V = n;
        this->adj = adj;
        visited.resize(n, false);
        present.resize(n, false);
    }

    bool dfs(int i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            present[i] = true;
            for (int &v : adj[i])
            {
                if (present[v])
                    return false;
                if (!dfs(v))
                    return false;
            }
            ans.push_back(i);
            present[i] = false;
        }
        return true;
    }

    vector<int> topoSort()
    {

        bool ok = 1;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                ok &= dfs(i);
            if (!ok)
            {
                ans.push_back(-1);
                return ans;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

struct SegmentTree
{
    int n;
    vector<int> t;

    SegmentTree(int n, vector<int> a)
    {
        this->n = n;
        t.resize(2 * n);

        for (int i = n; i < 2 * n; i++)
        {
            t[i] = a[i - n];
        }
    }

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = t[2 * i] + t[2 * i + 1];
    }

    void modify(int p, int value)
    {
        for (t[p += n] = value; p > 1; p /= 2)
            t[p / 2] = t[p] + t[p ^ 1];
    }

    int query(int l, int r)
    {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct OrderedSet
{
    // tree definition
    typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update>ordered_set;

};

struct BIT
{
    int n;
    vector<int> t, a;
    bool init;
    BIT() {}
    BIT(int n, vector<int> &a)
    {
        this->n = n;
        this->a = a;
        t.resize(n + 1, 0);
        init = true;
        for (int i = 0; i < n; i++)
        {
            this->update(i + 1, a[i]);
        }
        init = false;
    }
    int query(int i)
    {
        int ans = 0;
        for (; i >= 1; i -= (i & -i))
            ans += t[i];
        return ans;
    }
    void update(int i, int val)
    {
        if (!init)
            val -= a[i - 1], a[i - 1] += val;
        if (i <= 0)
            return;
        for (; i <= n; i += (i & -i))
            t[i] += val;
    }
    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};


struct sparseTable{

    int N , K;
    vector<int> lg;
    vector<vector<int>> st;

    sparseTable(int n , vector<int> &a){

        this->N = n + 1;

        lg.resize(N+1);
        lg[1] = 0;
        for (int i = 2; i <= N; i++) lg[i] = lg[i/2] + 1;

        this->K = lg[N];
        st.resize(K + 1, vector<int> (N));

        for (int i = 0; i < n; i++) st[0][i] = a[i];

        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

    }

    int query ( int l , int r ){         // zero based index

        int i = lg[r - l + 1];
        int minimum = min(st[i][l], st[i][r - (1 << i) + 1]);
        return minimum;

    }

};


void sieveOfErasthosthenes(){
    int N;

    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= N; i++) {
    if (is_prime[i] && (long long)i * i <= N) {
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }

    }
};
