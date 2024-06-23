#include <iostream>

using namespace std;

int n;
int a[25][25];
bool chuaxet[25];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
}

void DFS(int u){
    chuaxet[u] = false;
    for(int v = 1; v <= n; v++){
        if(a[u][v] && chuaxet[v])
            DFS(v);
    }
}

void Reinit(){
    for(int i = 1; i <= n; i++) chuaxet[i] = true;
}

bool check_LTM(){
   for(int u = 1; u <= n; u++){
       if(chuaxet[u]) return false;
   }
   return true;
}

bool Strong_Conective(){
    input();
    Reinit();
    for(int u = 1; u <= n; u++){
        DFS(u);
        if(!check_LTM()) return false;
        Reinit();
    }
    return true;
}
int main(){
    if(Strong_Conective()) cout << "strongly connected";
    else cout << "not strongly connected";
    return 0;
}