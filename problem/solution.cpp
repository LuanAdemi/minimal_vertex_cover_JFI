#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin ("input/medium_1.graph");
    ofstream fout ("output/solution_medium1.sol");
    string garbage;
    cout << "HI\n";
    fin >> garbage;
    fin >> garbage;
    cout << "HI\n";
    int n,m;
    fin >> n >> m;
    vector<int> graph[n+2];
    for (int i = 0; i < m; i++){
        int a,b;
        fin >> a >> b;
        cout << a << " " << b << "\n";
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int deg[n+2];
    int best = -1;
    int maxi = 0;
    cout << "HI\n";
    //queue<int> next;
    bool found = false;
    //bool found2 = false;
    for (int i = 0; i < n; i++){
        deg[i] = graph[i].size();
        if (deg[i] == 1){
            best = graph[i][0];
            found = true;
        }
        /*else if (deg[i] == 2 && !found){
            best = graph[i][0];
            next.push(graph[i][1]);
            found2 = true;
        }*/
        if (deg[i] > maxi && !found){//} && !found2){
            maxi = deg[i];
            best = i;
        }
    }
    cout << "HI\n";
    vector<int> marked;
    cout << best << "\n";
    bool visited[n+2] = {};
    bool done = false;
    while (!done){
        marked.push_back(best);
        visited[best] = true;
        for (int adj: graph[best]){
            deg[adj]--;
        }
        /*if (!next.empty()){
            best = next.front();
            next.pop();
            continue;
        }*/
        maxi = 0;
        best = -1;
        //found2 = false;
        for (int i = 0; i < n; i++){
            if (deg[i] == 1 && !visited[i]){
                for (int adj: graph[i]){
                    if (!visited[adj]){
                        best = adj;
                        maxi = 10;
                        /*while(!next.empty()){
                            next.pop();
                        }*/
                        break;
                    }
                }
                break;
            }
            /*else if (deg[i] == 2){
                int k = 0;
                for (int adj: graph[i]){
                    if (!visited[adj]){
                        if (k == 0){
                            best = adj;
                            k++;
                        }
                        else {
                            next.push(adj);
                        }
                        maxi = 10;
                        found2 = true;
                    }
                }
            }*/
            else if (deg[i] > maxi && !visited[i]){ // !found2
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


