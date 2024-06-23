#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1e9;

void Path(vector<vector<int>> next, int i, int j) {
    cout << "  " << i;
    while(i != j){
        i = next[i][j];
        cout << " --> " << i;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<vector<int>> next(n+1, vector<int>(n+1, -1));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int weight;
            cin >> weight;
            if(weight != 0 || i == j){
                dist[i][j] = weight;
                next[i][j] = j;
            }
        }
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }


    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i != j && dist[i][j] == INF){
                cout << "K/c " << i << " -> " << j << " = INF; " << endl;
            }
			else{
                cout << "K/c " << i << " -> " << j << " = " << dist[i][j] << "; ";
                Path(next, i, j);
            }
        }
        cout << endl;
    }

    return 0;
}
