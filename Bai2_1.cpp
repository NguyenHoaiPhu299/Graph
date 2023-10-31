#include <iostream>
#include <vector>
using namespace std;

int n, m; // dinh va canh
int a[1001][1001];

void Change_EdgeList_Matrix()
{
    for (int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> adj1[1001]; // adj[i] luu danh sach ke cua dinh i
void Use_Vector_Change_EdgeList_AdjacencyList()
{
    for (int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        adj1[x].push_back(y);
        adj1[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<int, int>> edge;
void Change_Matrix_EdgeList()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 1 && i < j)
            {
                edge.push_back({i, j});
            }
        }
    }
    for (auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    cin >> n;
    // cout << "Chuyen tu danh sach canh sang ma tran ke:" << endl;
    // Change_EdgeList_Matrix();
    // cout << "\nChuyen tu danh sach canh sang danh sach ke:" << endl;
    // Use_Vector_Change_EdgeList_AdjacencyList();
    cout << "\nChuyen tu ma tran ke sang danh sach canh:" << endl;
    Change_Matrix_EdgeList();
    return 0;
}

/*
input: 
5 9
1 2
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5
input:
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
*/