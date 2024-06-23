#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

struct Edge{
    int s, e, w;
};
int n ,s, A[MAX][MAX], chuaxet[MAX], ne, neT, T[MAX][MAX], dH;
Edge eArr[MAX], eArr_T[MAX];

void input(){
    cin >> n >> s;
    ne = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> A[i][j];
            if(A[i][j] != 0 && i < j){
                ne++;
                eArr[ne].s = i;
                eArr[ne].e = j;
                eArr[ne].w = A[i][j];
            }
        }
    }
}
void init(){
    for(int i = 1; i <= n; i++){
        chuaxet[i] = 1;
        for(int j = 1; j <= n; j++){
            T[i][j] = 0;
        }
    }
}
void reinit(){
    for(int i = 1; i <= n; i++) chuaxet[i] = 1;
}
void T_DFS(int u){
    chuaxet[u] = 0;
    for(int v = 1; v <= n; v++){
        if(T[u][v] && chuaxet[v]){
            T_DFS(v);
        }
    }
}

bool cmp(Edge e1, Edge e2){
    if(e1.w == e2.w){
        if(e1.s == e2.s) return e1.e < e2.e;
        else return e1.s < e2.s;
    }
    return e1.w < e2.w;
}

void Prim(int u){
    dH = 0;
    init();
    sort(eArr + 1, eArr + ne + 1, cmp);
    neT = 0;
    for(int eT = 1; eT <= n-1; eT++){
        reinit();
        T_DFS(s);
        for(int e = 1; e <= ne; e++){
            if(chuaxet[eArr[e].s]+chuaxet[eArr[e].e] == 1){
                neT++;
                eArr_T[neT].s = eArr[e].s;
                eArr_T[neT].e = eArr[e].e;
                T[eArr[e].s][eArr[e].e] = T[eArr[e].e][eArr[e].s] = 1;
                dH += eArr[e].w;
                break;
            }
        }
    }
    cout << "dH = " << dH << endl;
    for(int e = 1; e <= neT; e++){
        cout << eArr_T[e].s << " " << eArr_T[e].e << endl;
    }
}

int main(){
    input();
    Prim(s);
    return 0;
}