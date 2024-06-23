#include <iostream>
using namespace std;

int n, s, a[25][25], truoc[25], d[25];
bool chuaxet[25];

void input(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
    	truoc[i] = 0;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) a[i][j] = 1e9;
        }
    }
}

void bellman(){
    for(int v = 1; v <= n; v++){
        d[v] = a[s][v];
        truoc[v] = s;
    }
    d[s] = 0;
    for(int k = 1; k <= n-2; k++){
        for(int v = 1; v <= n; v++){
            if(v == s) continue;
            for(int u = 1; u <= n; u++){
                if(d[v] > d[u] + a[u][v]){
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
    }
}

void pogg(){
    for(int t = 1; t <= n; t++){
        cout << "K/c " << s << " -> " << t << " = ";
        if(d[t] > 1e8){
            cout << "INF;\n";
            continue;
        }
        else cout << d[t] << "; ";
        int res = t;
        cout << res << " <- ";
        res = truoc[res];
        while(res != s){
            cout << res << " -> ";
            res = truoc[res];
        }
        cout << s << endl;
    }
}

int main(){
    input();
    bellman();
    pogg();
    return 0;
}