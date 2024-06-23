#include <iostream>
#include <queue>
using namespace std;

int n, k;
int a[25][25];
bool chuaxet[25];
vector<pair<int, int>> dfs, bfs;

void input(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void init(){
    for(int i = 1; i <= n; i++){
        chuaxet[i] = true;
    }
}

void DFS(int u){
    chuaxet[u] = false;
    for(int t = 1; t <= n; t++){
        if(a[u][t] && chuaxet[t]){
            dfs.push_back({u, t});
            DFS(t);
        }
    }
}

void Tree_DFS(int u){
    init();
    DFS(u);
    cout << "DFS tree\n";
    for(auto it : dfs){
        cout << it.first << " " << it.second << endl; 
    }
}

void Tree_BFS(int u){
    init();
    chuaxet[u] = false;
    queue<int> qe;
    qe.push(u);
    while(!qe.empty()){
        int s = qe.front(); qe.pop();
        for(int t = 1; t <= n; t++){
            if(a[s][t] && chuaxet[t]){
                qe.push(t);
                chuaxet[t] = false;
                bfs.push_back({s, t});
            }
        }
    }
    cout << "BFS tree\n";
    for(auto it : bfs){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    input();
    init();
    Tree_DFS(k);
    Tree_BFS(k);
    return 0;
}


