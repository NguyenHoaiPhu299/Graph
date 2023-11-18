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
using namespace std;
#define MAX 100001

using ll = long long;

int n, m;
vector<pair<int, int>> adj[MAX];

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

const int INF = 1e9;

void Dijkstra(int s)
{
    // Mang luu khoang cach duong di
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<
    pair<int, int>, 
    vector<pair<int, int>>, 
    greater<pair<int, int>> > Q;
}

int main()
{
    Input();
    return 0;
}