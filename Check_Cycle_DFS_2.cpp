// DFS Check Directed_Undirected Graph Cycles Disconnected
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int edge, point;
vector<int> adj[1001];
bool visited[1001];

void Input()
{
    cin >> edge >> point;
    for (int i = 1; i <= edge; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

bool DFS(int u, int par)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            if (DFS(v, u))
                return true;
        }
        else if (v != par)
            return true;
    }
    return false;
}

int main()
{
    Input();
    for (int i = 1; i <= point; i++)
    {
        if (!visited[i])
        {
            if (DFS(i, 0))
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}