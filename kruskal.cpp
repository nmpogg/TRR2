#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    int s, e, w;
};

Edge eArr[100], eArr_T[100];
int n, a[100][100], ne, neT, t[100][100], dH;
bool chuaxet[100];

void input(){
    cin >> n;
    ne = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] && i < j){
                ne++;
                eArr[ne].s = i; eArr[ne].e = j; eArr[ne].w = a[i][j];
            }
        }
    }
}

void init(){
    for(int i = 1; i <= n; i++){
        chuaxet[i] = true;
        for(int j = 1; j <= n; j++) t[i][j] = 0;
    }
}

void reinit(){
    for(int i = 1; i <= n; i++) chuaxet[i] = true;
}

void DFS(int u){
    chuaxet[u] = false;
    for(int v = 1; v <= n; v++){
        if(t[u][v] && chuaxet[v]){
            DFS(v);
        }
    }
}

bool eCompare(Edge e1, Edge e2){
    if(e1.w == e2.w){
        return e1.s < e2.s;
    }
    return e1.w < e2.w;
}

void kruskal(){
    dH = 0;
    init();
    sort(eArr+1, eArr+ne+1, eCompare);
    neT = 0;
    for(int e = 1; e <= ne; e++){
        reinit();
        DFS(eArr[e].s);
        if(chuaxet[eArr[e].e]){
            neT++;
            eArr_T[neT].s = eArr[e].s;
            eArr_T[neT].e = eArr[e].e;
            t[eArr[e].s][eArr[e].e] = t[eArr[e].e][eArr[e].s] = 1;
            dH += eArr[e].w;
        }
    }
    cout << "dH = " << dH << endl;
    for(int e = 1; e <= neT; e++){
        cout << eArr_T[e].s << " " << eArr_T[e].e << endl;
    }
}

int main(){
    input();
    kruskal();
    return 0;
}