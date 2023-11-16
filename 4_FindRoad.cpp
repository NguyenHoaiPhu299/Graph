// Tim duong di giua hai dinh tren do thi: (Co huong va vo huong)
/*
Code tuong tu thuat toan dfs va bfs nhung duy tri them mang parent de truy vet duong di.
*/
/*
10 8
1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
*/
//dinh:     1   2   3   6   7
//parent:   0   1   2   3   6

/*
- Check co duong di hay khong:
+ Ban dau khoi tao parent = 0
+ Gia su tim duong di tu u den v
+ check parent cua v co khac 0 hay khong
+ neu khac => co duong di
+ neu khong => khong co duong di

- Truy vet duong di:

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 100000
using namespace std;

int edge, point;
int parent[MAX];
vector<int> adj[MAX];
bool visited[MAX];

void Input()
{
    cin >> point >> edge;
    for (int i = 1; i <= edge; ++i)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Co huong thi bo dong nay di
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            DFS(v);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int x : adj[v])
        {
            if (!visited[x]) // Neu x chua duoc tham
            {
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }

}

void Path(int s, int t)
{
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    BFS(s); // BFS(s);
    if (!visited[t])
    {
        cout << "Khong co duong di !";
    }
    else
    {
        // truy vet duong di
        vector<int> path;
        // Bat dau tu dinh t
        while (t != s)
        {
            path.push_back(t);
            // Lan nguoc lai
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path)
        {
            cout << x << " ";
        }
    }
}

int main()
{
    Input();
    int s, t;
    cin >> s >> t;
    Path(1, 7);
    return 0;
}
// Doi voi do thi co huong thi tuong tu
/* Trong truong hop no cho mot do thi vo huong, co n truy van, moi truy van co a va b
hoi giua hai dinh a va b co duong di hay khong
=> Dung map hoac mang de duy tri xem cac dinh thuoc thanh phan lien thong thu may
check cung thuoc mot thanh phan lien thong la co duong di ngay */