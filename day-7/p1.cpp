#include <bits/stdc++.h>
using namespace std;

void print_M(const vector<vector<char>> &M) {
	for (auto &cs : M) {
		for (auto c : cs) {
			cout << c;
		}
		cout << endl;
	}
}

int main() {
	freopen("small", "r", stdin);
	vector<vector<char>> M;

	string line;
	while (getline(cin, line)) {
		vector<char> Mi;
		for (auto c : line) {
			Mi.push_back(c);
		}
		M.push_back(Mi);
	}

	print_M(M);
}


