/*
Hai do thi vo huong, lien thong khi giua hai dinh luon co duong di
+ Dem so thanh phan lien thong
+ Check xem do thi co lien thong hay khong 

pseudocode:
ConnectedComponent()
{
    // Khoi tao so thanh phan lien thong an dau cua do thi = 0
    cnt = 0;
    // Dem so thanh phan lien thong
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ++cnt; // tang so thanh phan lien thong
            dfs(i); // bfs(i)
        }
    }
    return cnt;
}
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001] = {false};

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
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
        visited[v] = true;
        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int ConnectComponent()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            cout << "Thanh phan lien thong thu " << cnt << ": ";
            DFS(i); // BFS();
            cout << endl;
        }
    }
    return cnt;
}

bool CheckConnect()
{
    if (ConnectComponent() != 1)
        return false;
    return true;
}

int main()
{
    input();
    cout << "So thanh phan lien thong cua do thi la: " << ConnectComponent() << endl;
    if (CheckConnect())
        cout << "Connect";
    else cout << "Not Connect";
    return 0;
}
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