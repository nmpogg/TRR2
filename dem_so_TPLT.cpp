#include <iostream>
#include <stack>
#define MAX 200
using namespace std;

class Graph{
    private:
        int A[MAX][MAX], n;
        bool chuaxet[MAX];
    public:
    void input();
    void init();
    void DFS(int u);
    int dem();
};

void Graph::input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> A[i][j];
    }
}

void Graph::init(){
    for(int i = 1; i <= n; i++){
        chuaxet[i] = true;
    }
}

void Graph::DFS(int u){
    chuaxet[u] = false;
    for(int v = 1; v <= n; v++){
        if(A[u][v] && chuaxet[v])
            DFS(v);
    }
}

int Graph::dem(){
    int cnt = 0;
    for(int u = 1; u <= n; u++){
        if(chuaxet[u]){
            cnt++;
            DFS(u);
        }
    }
    return cnt;
}

int main(){
    Graph G;
    G.input();
    G.init();
    cout << G.dem();
}