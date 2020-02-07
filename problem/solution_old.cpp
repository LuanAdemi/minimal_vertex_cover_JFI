#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin ("input/easy_2.graph");
    ofstream fout ("output/solution_easy2.sol");
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
    int maxi = 0;
    cout << "HI\n";
    for (int i = 0; i < n; i++){
        deg[i] = graph[i].size();
        if (deg[i] > maxi){
            maxi = deg[i];
            best = i;
        }
    }
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
        maxi = 0;
        best = -1;
        for (int i = 0; i < n; i++){
            if (deg[i] > maxi && !visited[i]){
                maxi = deg[i];
                best = i;
            }
        }
        if (maxi == 0){
            done = true;
        }
    }
    cout << "HI\n";
    fout << marked.size() << "\n";
    for (int x: marked){
        fout << x+1 << " ";
        cout << x+1 << "\n";
    }
    cout << "\nlength: " << marked.size() << "\n";
}


