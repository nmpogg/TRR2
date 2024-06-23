#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define MAX 200

class Graph{
  private:
    int A[MAX][MAX], n, truoc[MAX];
    int s, t;
    bool chuaxet[MAX];
  public:
    void input();
    void init();
    void DFS(int u);
    void BFS(int u);
    void DuongDi();
};

void Graph::input(){
    cin >> n;
    cin >> s >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            cin >> A[i][j];
        }
    }
}

void Graph::init(){
    for(int i = 1; i <= n; i++){
        chuaxet[i] = true;
    }
    for(int i = 1; i <= n; i++){
        truoc[i] = 0;
    }
}

void Graph::DFS(int u){
    chuaxet[u] = false;
    for(int v = 1; v <= n; v++){
        if(A[u][v] && chuaxet[v]){
            truoc[v] = u;
            DFS(v);
        }
    }
}

void Graph::BFS(int i){
    queue<int> qe;
    qe.push(i);
    chuaxet[i] = false;
    while(!qe.empty()){
        int u = qe.front();
        qe.pop();
        for(int v = 1; v <= n; v++){
            if(A[u][v] && chuaxet[v]){
                qe.push(v);
                chuaxet[v] = false;
                truoc[v] = u;
            }
        }
    }
}

void Graph::DuongDi(){
	DFS(s);
    if(truoc[t] == 0){
        cout << "no path";
        return;
    }
    cout << "DFS path: ";
    vector<int> path;
    int j = t;
    while(truoc[j] != 0){
        path.push_back(j);
        j = truoc[j];
    }
    path.push_back(s);
    for(auto x : path) cout << x << " ";
    path.clear();
    init();
    BFS(s);
    cout << endl;
    cout << "BFS path: ";
    j = t;
    while(truoc[j] != 0){
        path.push_back(j);
        j = truoc[j];
    }
    path.push_back(s);
    for(auto x : path) cout << x << " ";
}


int main(){
    Graph G;
    G.input();
    G.init();
    G.DuongDi();
}