#include <iostream>
#include <stack>
#include <vector>

using namespace std;
/*
10
1
0 1 0 0 1 0 0 1 0 1
1 0 1 1 0 1 0 0 0 0
0 1 0 1 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
1 0 0 0 0 1 1 1 1 1
0 1 0 0 1 0 0 0 0 0
0 0 0 0 1 0 0 1 1 1
1 0 0 0 1 0 1 0 0 1
0 0 0 0 1 0 1 0 0 0
1 0 0 0 1 0 1 1 0 0
*/
#define MAX 200

int A[MAX][MAX], n, u;
vector<int> CE;

void input(){
    cin >> n >> u;
    for(int i = 1;i  <= n; i++){
        for(int j = 1; j <= n; j++) cin >> A[i][j];
    }
}

void Euler_Cycle(){
    stack<int> st;
    st.push(u);
    while(!st.empty()){
        int s = st.top();
        bool flag = false;
        for(int t = 1; t <= n; t++){
            if(A[s][t]){
                flag = true;
                st.push(t);
                A[s][t] = 0;
                A[t][s] = 0;
                break;
            }
        }
        if(!flag){
            CE.push_back(s);
            st.pop();
        }
    }
    for(int i = CE.size()- 1; i >= 0; i--) cout << CE[i] << ' ';
}

int main(){
    input();
    Euler_Cycle();
    return 0;
}

