#include <iostream>
#define MAX 200
using namespace std;

class Graph{
    private:
        int A[MAX][MAX], n;
        bool unUsed[MAX];
    public:
        void input();
        void init();
        void recursiveDFS(int u);
};

void Graph::input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> A[i][j];
    }
}

void Graph:: init(){
    for(int i = 1; i <= n; i++){
        unUsed[i] = true;
    }
}

void Graph::recursiveDFS(int u){
    cout << u << " ";
    unUsed[u] = false;
    for(int v = 1; v <= n; v++){
        if(A[u][v] && unUsed[v])
            recursiveDFS(v);
    }
}

int main(){
    Graph G;
    G.input();
    G.init();
    G.recursiveDFS(1);
    return 0;
}
