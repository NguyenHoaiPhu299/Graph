#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

int point, edge;
vector<int> adj[1001];
bool visited[1001];
stack<int> s;

void Input()
{
    cin >> point >> edge;
    for (int i = 1; i <= edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= point; i++)
		sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= point; i++)
        visited[i] = false;
}

void DFS(int u)
{
    stack<int> s;
    s.push(u);
    visited[u] = true;
    cout << u << " ";
    while (!s.empty())
    {
        int x = s.top();
        // s.pop();
        
        for (int i = 0; i < adj[x].size(); i++)
        {
            int neighbor = adj[x][i];
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
                cout << neighbor << " ";
                break;
            }
            if (i == adj[x].size() - 1 && visited[neighbor] == true)
                s.pop();
        }
    }
}

int main()
{
    Input();
    DFS(1);
    return 0;
}
