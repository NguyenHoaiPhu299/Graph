/*
Thuat toan Topo duoc ap dung doi voi do thi co huong
=> Thuat toan Topo se cho ta thu tu neu nhu co duong di tu x toi y thi x se xuat hien truoc y
- BFS - Thuat toan Kahn - Xoa dan dinh
- DFS

1 ---> 2 ---> 3
| D    | D    | D
|      |      |
6      4 ---> 5

Co the co nhieu thu tu Topo
1 6 2 4 3 5
1 2 3 4 5 6

Ap dung vao nhung bai toan vi du nhu hoc cac mon tien quyet

Khong ap dung vao nhung bai co chu trinh
*/

// DFS
/*
Su dung stack: Luu xem dinh nao duoc tham xong dau tien
(Dinh khong co duong di tham dinh khac) 
=> Dinh cuoi cung trong thu tu sap xep topo
Co 3 trang thai:
1. Dinh nao duoc tham xong thi duoc day ra khoi stack
2. Dinh  chua duoc tham xong
3. Dinh chua duoc tham
*/
#if 0
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> topo;
vector<int> adj[1001];
bool visited[1001];
int edge, vertices;

void Input()
{
    cin >> edge >> vertices;
    for (int i = 1; i <= edge; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= vertices; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
            topo.push_back(v);
        }
    }
}

void DFS_Topo()
{
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            for (int v : adj[i])
            {
                if (!visited[v])
                {
                    DFS(v);
                    topo.push_back(v);
                }
            }
            topo.push_back(i);
        }
    }
    reverse(topo.begin(), topo.end());
}

void DFS_2(int u)
{
    visited[u] = true;
    for (int x : adj[u])
    {
        if (!visited[x])
        {
            DFS_2(x);
        }
    }
    topo.push_back(u);
}

void Topo()
{
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            DFS_2(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (int x : topo)
    {
        cout << x << " ";
    }
}

int main()
{
    // Input();
    // DFS_Topo();
    // for (int v : topo)
    // {
    //     cout << v << " ";
    // }
    Input();
    Topo();
    return 0;
}
#endif
// BFS - Kahn - xoa dan dinh
/*
Yeu cau: tinh duoc ban bac vao cua cac dinh cua do thi

Chon ra cac dinh co ban bac vao = 0 (khong co dinh nao di toi) => Cac dinh xuat hien dau tien => Day vao hang doi

Lay dinh dau hang doi ra khoi hang doi => Coi nhu xoa dinh do ra khoi do thi (nen moi goi la thuat toan xoa dan dinh) => Giam ban bac vao cua cac dinh  ke voi dinh do

Kiem tra xem sau khi giam, co dinh nao co ban bac vao = 0 hay khong, neu co thi day vao hang doi
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> topo;
vector<int> adj[1001];
bool visited[1001];
int edge, vertices;
int in[1001];

void Input()
{
    cin >> edge >> vertices;
    for (int i = 1; i <= edge; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= vertices; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
}

void Kahn()
{
    queue<int> q;
    for (int i = 1; i <= vertices; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int x : topo)
    {
        cout << x << " ";
    }
}

int main()
{
    // Input();
    // DFS_Topo();
    // for (int v : topo)
    // {
    //     cout << v << " ";
    // }
    Input();
    Kahn();
    return 0;
}

/*
Thuat toan Kahn de xac dinh chu trinh tren do thi co huong 
=> check xem mot do thi co chu trinh hay khong

=> Neu co chu trinh thi thuat toan Kahn khong the tham het cac dinh
*/