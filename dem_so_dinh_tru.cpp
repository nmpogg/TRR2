#include <iostream>

using namespace std;

int n, a[25][25];
bool chuaxet[25];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void Reinit(){
    for(int i = 1; i <= n; i++){
        chuaxet[i] = true;
    }
}

void DFS(int u){
    chuaxet[u] = false;
    for(int v = 1; v <= n; v++)
        if(a[u][v] && chuaxet[v])
            DFS(v);
}

int Test_SLT(){
    for(int u = 1; u <= n; u++){
        if(chuaxet[u]) return 1;
    }
    return 0;
}

int main(){
    input();
    Reinit();
    for(int u = 1; u <= n; u++){
    	chuaxet[u] = false;
        if(u != 1) DFS(1);
        else DFS(2);
        if(Test_SLT()) cout << u << " ";
        Reinit();
    }
}