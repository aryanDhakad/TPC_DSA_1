#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int findNearestOne(vector<vector<int>> &g)
{
    int n = g.size();
    int m = g[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 1)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int sz = q.size();

        int x = q.front().first, y = q.front().second;
        q.pop();

        for (auto &t : dir)
        {
            int nx = x + t.first;
            int ny = y + t.second;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (auto &x : dist)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j])
                count1++;
        }
    }
    if (count1 == 0)
    {
        cout << "Invalid Matrix, no 1's present" << endl;
        return;
    }
    findNearestOne(g);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
