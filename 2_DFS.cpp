/*
Pseudocode:
DFS (u)
{
    <tham dinh u>;
    visited[u] = true; // danh sau la u da duoc tham
    for (int u : v) // duyet cac dinh ke voi dinh u
        if (!visited[v]) // Neu v chua duoc tham
            DfS(v);
}

Do phuc tap cua thuat toan DFS phu thuoc vao cach bieu dien ma tran
G = <V, E>
Bieu dien bang ma tran ke:      O (V * V)
Bieu dien bang danh sach canh:  O (V * E)
Bieu dien bang danh sach ke:    O (V + E)
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int edge, point;
vector<int> adj[1001];
bool visited[1001];

// Ham input
void Input()
{
    cin >> point >> edge;
    for (int i = 1; i <= edge; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Neu do thi co huong thi bo dong nay
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    // Bat dau duyet tu dinh u
    cout << u << " "; // Tham dinh u
    visited[u] = true; // Danh dau dinh u da duoc tham

    // Duyet cac dinh ke voi dinh u 
    for (int v : adj[u])
        if (!visited[v])
            DFS(v);
}

int main()
{
    Input();
    DFS(1);
    return 0;
}
/*
9 9
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
8 9
*/

/*
9 10
1 2
1 3
1 5
2 4
3 6
3 7
5 8
6 7
8 9
9 3
*/

/*
Khi thuat toan DFS chay => tao thanh 1 cay tim kiem DFS
Co 4 loai canh:
+ canh ma theo do tu mot dinh ta den tham mot dinh moi
+ Canh nguoc la canh di tu con chau den to tien => Duoc dung de ap dung cac thuat toan sau nay
+ Canh toi la canh di tu to tien den hau due
+ Canh vong la canh noi 2 dinh khong co quan he ho hang
*/