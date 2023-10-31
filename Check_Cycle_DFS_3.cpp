// DFS Check Directed_Undirected Graph Cycles Disconnected Use Parent Array
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int edge, point;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

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

bool DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            if (DFS(v))
                return true;
        }
        else if (v != parent[u])
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
            if (DFS(i))
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}