/*
BFS (Breath First Search)
Tu tuong cua thuat toan BFS la tim kiem uu tien chieu rong hon la chieu sau
Thuat toan se tim kiem xung quanh de mo rong truoc khi di xuong xau hon

Pseudocode:
BFS (u)
{
    // Step 1: Khoi tao
    queue = empty; // Tao mot hang doi rong
    push(queue, u); // Day dinh u vao hang doi
    visited[u] = true; // danh dau dinh u da duoc tham

    // step 2: lap khi hang doi van con phan tu
    while (queue != empty)
    {
        v = queue.front(); // lay ra dinh o dau hang doi
        queue.pop(); // xoa dinh khoi dau hang doi
        <tham dinh v>;
        // Duyet cac dinh ke voi dinh v ma chua duoc tham va day vao hang doi
        for (int x : ke[v])
        {
            if (!visited[x]) // neu x chua duoc tham
            {
                push(queue, x);
                visited[x] = true;
            }
        }
    }
}

doi voi nhung bai toan khong co trong so, thi BFS se cho ta duong di ngan nhat
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int edge, point;
vector<int> adj[1001];
bool visited[1001] = {false};

void Use_Vector_Change_EdgeList_AdjacencyList()
{
    cin >> edge >> point;
    for (int i = 1; i <= edge; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Trong do thi vo huong thi bo dong nay
    }
    // memset(visited, false, sizeof(visited));
}

void BFS(int u)
{
    // Step 1: Khoi tao
    // Tao mot hang doi rong
    queue<int> q;
    q.push(u); // Day dinh u vao hang doi
    visited[u] = true; // Danh dau da tham dinh u

    // Step 2: Lap khi hang doi van con phan tu
    while (!q.empty())
    {
        int v = q.front(); // Lay ra dinh dau hang doi
        q.pop(); // Xoa dinh khoi dau hang doi
        cout << v << " "; // Tham dinh v

        // Duyet cac dinh ke voii v ma chua duoc tham va day vao hang doii
        for (int x : adj[v])
        {
            if (!visited[x]) // Neu x chua duoc tham
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }

}

int main()
{
    Use_Vector_Change_EdgeList_AdjacencyList();
    BFS(1);
    return 0;
}
/*
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 7
3 9
6 7
5 8
8 9
*/

/*
10 11
1 2
1 3
1 10
2 4
3 5
3 6
5 8
5 10
6 7
7 3
8 9
*/

// From 28tech

