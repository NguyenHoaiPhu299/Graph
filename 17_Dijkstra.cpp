/*
Thuat toan dijkstra duoc ap dung de tim duong di ngan nhat giua mot
dinh voi cac dinh con lai cua do thi, ap dung cho ca do thi co huong va vo huong. Chu y: Khong co trong so am.

BFS => Tim duong di ngan nhat trong truong hop bai toan khong co trong so

dijkstra la mot giai thuat tham lam tuong tu thuat toan Prim
1. dat khoang cach tu dinh nguon toi dinh nguon = 0 va cac dinh con lai = vo cung lon
2. Dat dinh hien tai la dinh nguon
3. Danh dau dinh nay da duoc tham
4. Tom gon bang cong thuc
Gia su: d[u] = 50 (khoang cach tu dinh nguon toi dinh u = 50)
        d[v] = 120 (khoang cach tu dinh nguon toi dinh v = 120)
        d[v - u] = 30 (trong so giua hai dinh u va v)
=> Khoang cach ngan nhat d[v] = min (d[v], d[v - u] + d[u]) = 80


|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
| iteration  |      unmarked         |       marked      |   current     |  d[1] |  d[2] |  d[3] |  d[4] |  d[5] |  d[6] |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
|            |     1,2,3,4,5,6       |                   |               |   0   |  inf  |  inf  |  inf  |  inf  |  inf  |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
| 1          |      2,3,4,5,6        |         1         |      u = 1    |   0   |   7   |  12   |  inf  |  inf  |  inf  |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
| 2          |       3,4,5,6         |        1,2        |      u = 2    |   0   |   7   |  9    |  16   |  inf  |  inf  |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
| 3          |        4,5,6          |       1,2,3       |      u = 3    |   0   |   7   |  9    |  16   |  19   |  inf  |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
| 4          |         5,6           |      1,2,3,4      |      u = 4    |   0   |   7   |  9    |  16   |  19   |  17   |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
| 5          |          5            |     1,2,3,4,6     |      u = 6    |   0   |   7   |  9    |  16   |  19   |  17   |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
| 6          |                       |    1,2,3,4,5,6    |      u = 5    |   0   |   7   |  9    |  16   |  19   |  17   |
|------------|-----------------------|-------------------|---------------|-------|-------|-------|-------|-------|-------|
|                                        Relaxation: d[v] = min (d[v], d[v - u] + d[u])                                  |
|------------------------------------------------------------------------------------------------------------------------|


*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001

using ll = long long;

int n, m, s, t;
vector<pair<int, int>> adj[MAX];

void Input()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

const int INF = 1e9;

void Dijkstra(int s)
{
    // Mang luu khoang cach duong di
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    // Luu {khoang cach cua dinh nguon den dinh hien tai, dinh hien tai} 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        // Chon ra dinh co khoang cach tu s nho nhat
        pair<int, int>  top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u])
        {
            continue;
        }
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

void Dijkstra_2(int s)
{
    // Mang luu khoang cach duong di
    vector<ll> d(n + 1, INF);
    vector<bool> visited(n + 1, false);
    d[s] = 0;
    // Luu {khoang cach cua dinh nguon den dinh hien tai, dinh hien tai} 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        // Chon ra dinh co khoang cach tu s nho nhat
        pair<int, int>  top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;
        if (visited[u]) continue;
        visited[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

int pre[MAX];

void Dijkstra(int s, int t)
{
    // Mang luu khoang cach duong di
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    pre[s] = s;
    // Luu {khoang cach cua dinh nguon den dinh hien tai, dinh hien tai} 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        // Chon ra dinh co khoang cach tu s nho nhat
        pair<int, int>  top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u])
        {
            continue;
        }
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }
    cout << d[t] << endl;
    vector<int> path;
    while (1)
    {
        path.push_back(t);
        if (t == s)
        {
            break;
        }
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
    {
        cout << x << " ";
    }
}

int main()
{
    Input();
    Dijkstra(s);
    Dijkstra(s, t);
    return 0;
}
/*
6 8 1 5
1 2 7 
1 3 12
2 3 2
2 4 9
3 5 10
5 4 4
5 6 5
4 6 1
*/