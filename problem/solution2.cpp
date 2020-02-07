#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin ("input/easy_1.graph");
    ofstream fout ("output/solution_easy1.sol");
    string garbage;
    cout << "HI\n";
    fin >> garbage;
    fin >> garbage;
    cout << "HI\n";
    int n,m;
    fin >> n >> m;
    vector<int> graph[n];
    for (int i = 0; i < m; i++){
        int a,b;
        fin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int deg[n];
    int best = -1;
    int mini = 1e9;
    cout << "HI\n";
    for (int i = 0; i < n; i++){
        deg[i] = graph[i].size();
        if (deg[i] < mini && deg[i] > 0){
            mini = deg[i];
            best = i;
        }
    }
    int maxi = 0;
    int real_best = -1;
    for (int adj: graph[best]){
        if (deg[adj] > maxi){
            maxi = deg[adj];
            real_best = adj;
        }
    }
    best = real_best;
    cout << "HI\n";
    vector<int> marked;
    bool visited[n] = {};
    bool done = false;
    while (!done){
        marked.push_back(best);
        visited[best] = true;
        for (int adj: graph[best]){
            deg[adj]--;
        }
        mini = 1e9;
        best = -1;
        for (int i = 0; i < n; i++){
            if (deg[i] < mini && deg[i] > 0 && !visited[i]){
                mini = deg[i];
                best = i;
            }
        }
        maxi = 0;
        real_best = -1;
        for (int adj: graph[best]){
            if (deg[adj] > maxi){
                maxi = deg[adj];
                real_best = adj;
            }
        }
        best = real_best;
            if (maxi == 0){
                done = true;
            }
        }
    cout << "HI\n";
    for (int x: marked){
        fout << x+1 << "\n";
        cout << x+1 << "\n";
    }
    fout << "\nlength: " << marked.size() << "\n";
    cout << "\nlength: " << marked.size() << "\n";
}


