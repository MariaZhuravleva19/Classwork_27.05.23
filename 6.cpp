#include <iostream>
#include <vector>

using namespace std;

void search_euler(int v, vector <vector<int>>& D, vector <int>& c)
{
    for (int i = 0; i < D[v].size(); ++i)
        if (D[v][i])
        {
            D[v][i] = 0;
            search_euler(i, D, c);
        }
    c.push_back(v);
}

void euler(vector <vector<int>> D, vector <int>& c)
{
    int i, j;
    int n = D.size();
    c.clear();

    vector < int > degree(n, 0);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            if (D[i][j])
                ++degree[i];

    int count = 0;
    j = 0;
    for (i = 0; i < n; ++i)
        if (degree[i] % 2 != 0)
        {
            ++count;
            if (count > 2)
                return;
            j = i;
        }

    search_euler(j, D, c);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> c;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    euler(graph,c);

    for (int i : c)
    {
        cout << i << endl;
    }
}