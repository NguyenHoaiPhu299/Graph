// BFS, DFS tren luoi
/*
Di chuyen 4 o chung canh

                    |   i - 1 , j   |
    ----------------|---------------|----------------
    (i) , (j - 1)   |     i , j     |   (i) , (j + 1)
    ----------------|---------------|----------------
                    |   i + 1 , j   |

Di chuyen 8 o chung dinh

    (i - 1) , (j - 1) |   i - 1 , j   |   (i - 1) , (j + 1)
    ------------------|---------------|--------------------
      (i) , (j - 1)   |     i , j     |     (i) , (j + 1)
    ------------------|---------------|--------------------
    (i + 1) , (j - 1) |   i + 1 , j   |   (i + 1) , (j + 1)

*/

// Bai 1: Dem so thanh phan lien thong tren luoi
#if 0
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int edge, point;
char arr[1001][1001];
bool visited[1001][1001];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void DFS(int i, int j)
{
    cout << i << " " << j << endl;
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= point && j1 >= 1 && j1 <= point && arr[i1][j1] == 'x' && !visited[i1][j1])
        {
            DFS(i1, j1);
        }
    }
}

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    arr[i][j] = 'o';
    cout << i << " " << j << endl;
    while (!q.empty())
    {
        pair<int, int> top = q.front(); q.pop();

        // duyet cac dinh ke
       for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= point && j1 >= 1 && j1 <= point && arr[i1][j1] == 'x' && !visited[i1][j1])
        {
            cout << i1 << " " << j1 << endl;
            q.push({i1, j1});
            arr[i1][j1] = 'o';
        }
    } 
    }
}

void Input()
{
    cin >> edge >> point;
    for (int i = 1; i <= point; i++)
    {
        for (int j = 1; j <= point; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int count = 0;
    for (int i = 1; i <= point; i++)
    {
        for (int j = 1; j <= point; j++)
        {
            if (arr[i][j] == 'x' && !visited[i][j])
            {
                cout << "Thanh phan lien thong thu " << count + 1 << endl;
                DFS(i, j);
                ++count;
            }
        }
    }
    cout << count << endl;
}


void DFS_1(int i, int j)
{
    cout << i << " " << j << endl;
    arr[i][j] = 'o';
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= point && j1 >= 1 && j1 <= point && arr[i1][j1] == 'x')
        {
            DFS(i1, j1);
        }
    }
}

void Input_1()
{
    cin >> edge >> point;
    for (int i = 1; i <= point; i++)
    {
        for (int j = 1; j <= point; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int count = 0;
    for (int i = 1; i <= point; i++)
    {
        for (int j = 1; j <= point; j++)
        {
            if (arr[i][j] == 'x')
            {
                cout << "Thanh phan lien thong thu " << count + 1 << endl;
                DFS(i, j);
                ++count;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    Input();
    return 0;
}
/*
6 6
xxxooo
ooxooo
oxxxxo
ooooox
xxoxox
xoxxox
*/
#endif

// Bai 2: Kiem tra duong di giua 2 diem tren luoi
/*

    1   2   3   4   5   6
1   A   o   o   x   o   o
2   o   x   o   o   o   o
3   o   x   o   o   o   o
4   o   o   o   o   x   x
5   B   o   o   o   x   o
6   o   o   o   x   x   x

o: co duong di
x: khong co duong di

*/

#if 0
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int edge, point, x1, y1, x2, y2;
char arr[1001][1001];
bool visited[1001][1001];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool DFS(int i, int j)
{
    cout << i << " " << j << endl;
    if (arr[i][j] == 'B')
        return true;
    arr[i][j] = 'x';
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= point && j1 >= 1 && j1 <= point && arr[i1][j1] != 'x')
        {
            if (DFS(i1, j1))
                return true;
        }
    }
    return false;
}

bool BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    arr[i][j] = 'o';
    cout << i << " " << j << endl;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        // duyet cac dinh ke
        for (int k = 0; k < 4; k++)
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if (i1 >= 1 && i1 <= point && j1 >= 1 && j1 <= point && arr[i1][j1] != 'x')
            {
                cout << i1 << " " << j1 << endl;
                if (arr[i1][j1] == 'B')
                    return true;
                q.push({i1, j1});
                arr[i1][j1] = 'o';
            }
        }
    }
    return false;
}

void Input()
{
    cin >> edge >> point;
    for (int i = 1; i <= point; i++)
    {
        for (int j = 1; j <= point; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                x1 = i; y1 = j;
            }
            else if (arr[i][j] == 'B')
            {
                x2 = i; y2 = j;
            }

        }
    }
    memset(visited, false, sizeof(visited));
    if (BFS(x1, y1))
    {
        cout << "YES";
    }
    else
        cout << "NO";
}

int main()
{
    Input();
    return 0;
}

/*
6 6
Aooxoo
oxoooo
oxoooo
ooooxx
Boooxo
oooxxx
*/
#endif 

// Bai 3: Tim so buoc di toi thieu giua 2 o tren luoi
/*
=> Su dung thuat toan BFS
*/
#if 1
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int edge, point, x1, y1, u, v;
char arr[1001][1001];
bool visited[1001][1001];
int d[1001][1001]; // d[i][j] : luu so buoc di tu o bat dau toi o i,j

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    arr[i][j] = 'o';
    d[i][j] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        // duyet cac dinh ke
        for (int k = 0; k < 4; k++)
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if (i1 >= 1 && i1 <= point && j1 >= 1 && j1 <= point && arr[i1][j1] != 'x')
            {
                d[i1][j1] = d[top.first][top.second] + 1;
                if (arr[i1][j1] == 'B')
                    return;
                q.push({i1, j1});
                arr[i1][j1] = 'x';
            }
        }
    }
}

void Input()
{
    cin >> edge >> point;
    for (int i = 1; i <= point; i++)
    {
        for (int j = 1; j <= point; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                x1 = i; y1 = j;
            }
            else if (arr[i][j] == 'B')
            {
                u = i; v = j;
            }
            
        }
    }
    memset(visited, false, sizeof(visited));
    BFS(x1, y1);
    if (!d[u][v])
    {
        cout << "Khong";
    }
    else
        cout << d[u][v] << " ";
}

int main()
{
    Input();
    return 0;
}
/*
6 6
Aooxoo
oxoooo
oxoooo
xoooxx
Bxooxo
oxoxxx

giai bai tap:
Tim duong di cho bai tren: vi du o bai tren se la di xuong 4 lan => in ra Down Down Down Down

Di chuyen giua hai o nao do co so luong buoc di cho truoc

Di chuyen giua hai o nao do nhung khong cho phep thay doi huong di qua n lan
*/
#endif