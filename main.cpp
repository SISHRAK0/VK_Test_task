#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("graph.txt");
    if (!fin) {
        cerr << "Ошибка: не удалось открыть файл graph.txt" << endl;
        return 1;
    }
    int n, k;
    fin >> n >> k;
    vector<vector<int>> graph(n);
    int u, v;
    for (int i = 0; i < k; i++) {
        fin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist(n,-1);

    int start;
    fin >> start;
    fin.close();
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int neigh : graph[curr]){
            if(dist[neigh] == -1){
                dist[neigh] = dist[curr] + 1;
                q.push(neigh);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << endl;
    }

}
