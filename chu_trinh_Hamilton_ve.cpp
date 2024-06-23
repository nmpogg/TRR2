/* by Neptune */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

int n;
int a[100][100];
int vs[100] = { 0 };
int x[100] = { 0 };
map<int, string> mp;

struct Data {
	int len;
	int base;
};

int cnt = 0;

Data Hamilton(int k) {
	int lengthNode = 0;
	int st = 0;
	int l = 0;
	int isLeafNode = 1;
	bool check = 0;
	for (int v = 1; v <= n; v++) {
		if (a[x[k - 1]][v]) {
			if (k == n + 1) {
				if (v == x[1]) {
					for (int i = 1; i <= k - 1; i++) cout << x[i] << (i < n ? " -> " : "");
					cout << endl;
				}
			}
			else if (vs[v] == 0) {
				vs[v] = 1; x[k] = v;
				isLeafNode = 0;
				Data d = Hamilton(k + 1);
				l = d.len;
				if (!check) {
					//check = 1;
					st = d.base;
					while (mp[k].length() < st) mp[k] += " ";
				}

				lengthNode += l;
				l = l + l * 2;
				string s = "";
				for (int i = 1; i <= l / 2; i++) s += " ";
				if (!check) {
					check = 1;
					s[0] = '|';
				}
				s += to_string(v);
				int r = l - s.length();
				for (int i = 1; i <= r; i++) s += " ";
				mp[k] += s;
				vs[v] = 0;
			}
		}
	}

	if (mp[k].size()) {
		mp[k][mp[k].length() - 1] = '|';
	}

	if (isLeafNode) {
		int st = cnt * 3;
		cnt++;
		return { 1, st };
	}

	return { lengthNode, st };
}

void LietKeHamilton(int u) {
	for (int v = 1; v <= n; v++) vs[v] = 0;
	vs[u] = 1;
	x[1] = u;
	cout << "\nChu trinh Hamilton xuat phat tu dinh " << u << " la : \n";
	Hamilton(2);

	cout << "\nXay dung cay tim kiem: \n";

	int len = mp[2].length();

	string s = "";
	for (int i = 1; i < len / 2; i++) s += " ";
	s += to_string(u);
	int r = len - s.length();
	for (int i = 1; i <= r; i++) s += " ";
	//s.at(s.length() - 1) = '|';
	cout << s << endl;
	for (int i = 2; i <= n; i++) {
		string tmp = "";
		string tmp0 = "";
		for (int j = 0; j < mp[i].length(); j++) {
			tmp += " ";
			tmp0 += " ";
		}
		int flag = 0;
		for (int j = 0; j < mp[i].length(); j++) {
			if (mp[i][j] == '|') {
				flag = 1;
				for (int k = j - 1; k >= 0; k--) {
					tmp0[k] = ' ';
					if (isdigit(mp[i][k])) break;
				}
			}
			if (flag == 0) tmp0[j] = '-';
			if (isdigit(mp[i][j])) {
				tmp[j] = '|';
				flag = 0;
			}
		}
		cout << tmp0 << endl;
		cout << tmp << endl;
		for (auto x : mp[i]) {
			if (x == '|') x = ' ';
			cout << x;
		}
		cout << endl;

	}
}

int main() {
	int u;
	cout << "Nhap n: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	cout << "Nhap dinh bat dau: ";
	cin >> u;
	LietKeHamilton(u);
	return 0;
}


