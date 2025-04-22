#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited;
vector<vector<int> > graph;

int bfs(int root)
{
    int count = 0;
    queue<int> q;

    q.push(root);
    visited[root] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        bool isExecute = false;
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            if (!visited[graph[cur][i]])
            {
                visited[graph[cur][i]] = 1;
                q.push(graph[cur][i]);
                isExecute = true;
            }
        }
        
        if (!isExecute)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int N;
    cin >> N;
    visited.resize(N, 0);
    graph.resize(N);

    int root = 0;

    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        
        if (n == -1) root = i;
        else
        {
            graph[n].push_back(i);
        }
    }

    int remove;
    cin >> remove;

    if (remove == root) cout << '0';
    else
    {
        visited[remove] = 1;
        cout << bfs(root);
    }
}
