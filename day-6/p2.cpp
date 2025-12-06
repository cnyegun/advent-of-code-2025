#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("small", "r", stdin);

	vector<vector<char>> C;
	vector<char> ops;

	string line;
	while (getline(cin, line)) {
		vector<char> C_row;
		for (auto c : line) {
			if (c == '*' or c == '+') {
				ops.push_back(c);
			}
			else {
				C_row.push_back(c);
			}
		}
		C.push_back(C_row);
	}

	for (auto &cs : C) {
		for (auto c : cs) {
			cout << c;
		}
		cout << endl;
	}

	for (auto op : ops) {
		cout << op << " ";
	}

	cout << endl;


	return 0;
}
