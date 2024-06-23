#include <iostream>
#include <queue>

#define MAX 200
using namespace std;

class Graph{
    private:
    int A[MAX][MAX], n;
    bool chuaxet[MAX];
    public:
    void input();
    void init();
    void BFS(int u);
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

void Graph::BFS(int u){
    queue<int> qe;
    cout << u << " ";
    qe.push(u);
    chuaxet[u] = false;
    while(!qe.empty()){
        int s = qe.front(); qe.pop();
        for(int t = 1; t <= n; t++){
            if(A[s][t] && chuaxet[t]){
                cout << t << " ";
                qe.push(t);
                chuaxet[t] = false;
            }
        }
    }
}

int main(){
    Graph G;
    G.input();
    G.init();
    G.BFS(1);
}