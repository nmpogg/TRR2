#include <iostream>
#include <stack>

using namespace std;

#define MAX 200

int n, s, A[MAX][MAX], X[MAX];
bool chuaxet[MAX];

void input(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        chuaxet[i] = true;
    }
    X[1] = s;
   chuaxet[s] = false;
}

void GhiNhan(){
    for(int i = 1; i <= n; i++){
        cout << X[i] << " ";
    }
    cout << s << endl;
}

void Hamilton(int k){
    for(int y = 1; y <= n; y++){
        if(A[X[k-1]][y]){
            if(k == n+1 && y == s){
                GhiNhan();
            }
            else if(chuaxet[y]){
                X[k] = y;
                chuaxet[y] = false;
                Hamilton(k+1);
                chuaxet[y] = true;
            }
        }
    }
}

int main(){
    input();
    Hamilton(2);
    return 0;
}