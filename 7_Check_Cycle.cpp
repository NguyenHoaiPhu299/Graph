/*
Chu trinh la duong di co dinh dau trung dinh cuoi
+ Chu trinh tren do thi co huong
+ Chu trinh tren do thi vo huong

=> May chot la canh nguoc => Cay co canh nguoc thi khi do se co chu trinh
*/

// Xac dinh chu trinh tren do thi vo huong bang DFS
/*
Pseudocode:
bool DFS(int u, int par) // par la dinh cha cua u (dinh mo rong ra u)
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
            reuturn true; // Ton tai canh nguoc (v, u)
    }
    return false;
}
*/
// DFS Check Directed_Undirected Graph Cycles Connected
#if 0
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
    if (DFS(1, 0))
    {
        cout << "Co chu trinh !";
    }
    else
    {
        cout << "Khong co chu trinh !";
    }
    return 0;
}
#endif

// DFS Check Directed_Undirected Graph Cycles Disconnected
#if 0
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
#endif

// DFS Check Directed_Undirected Graph Cycles Disconnected Use Parent Array
#if 0
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

}
#endif

// Ap dung cho do thi khong lien thong => Tong quat hon
#if 1
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int edge, point, st, en;
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
        {
            st = v; en = u;   
            return true;
        }
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
                vector <int> cycle; cycle.push_back(st);
                while (en != st)
                {
                    cycle.push_back(en);
                    en = parent[en];
                }
                cycle.push_back(st);
                reverse(cycle.begin(), cycle.end());
                for (int x : cycle)
                {
                    cout << x << " ";
                }
                return 0;
            }
        }
    }
    cout << "No";

}
/*
6 7
1 2
2 3
2 4
3 6
6 7
7 3
*/
#endif