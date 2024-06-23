#include <iostream>
using namespace std;

int n, s, a[25][25], truoc[25], d[25];
bool chuaxet[25];

void input(){
	cin >> n;
	cin >> s;
	for(int i = 1; i <= n; i++){
		truoc[i] = 0;
		chuaxet[i] = true;
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 0) a[i][j] = 1e9;
		}
	}
}

void dijkstra(){
	//b1 khoi tao
	for(int v = 1; v <= n; v++){
		d[v] = a[s][v];
		truoc[v] = s;
	}
	d[s] = 0;
//	cout << "done1\n";
	chuaxet[s] = false;
	//b2 lap
	while(true){
		int idx = 0, minx = 1e9;
		for(int u = 1; u <= n; u++){
			if(chuaxet[u]){
				if(d[u] < minx){
					minx = d[u];
//					cout << "finding...\n";
					idx = u;
				}
			}
		}
//		cout << "found\n";
		if(idx == 0) return;
		chuaxet[idx] = false;
		for(int v = 1; v <= n; v++){
			if(chuaxet[v]){
				if(d[v] > d[idx] + a[idx][v]){
					d[v] = d[idx] + a[idx][v];
					truoc[v] = idx;
				}
			}
		}
	}
}

void pogg(){
	for(int t = 1; t <= n; t++){
		cout << "K/c " << s << "-> " << t << " = ";
		if(d[t] == 1e9){
			cout << "INF;\n";
			continue;
		}
		else cout << d[t] << "; ";
		int res = t;
		cout << res << " <- ";
		res = truoc[res];
		while(res != s){
			cout << res << " <- ";
			res = truoc[res];
		}
		cout << s << endl;
	}
}

int main(){
	input();
	dijkstra();
	pogg();
	return 0;
}