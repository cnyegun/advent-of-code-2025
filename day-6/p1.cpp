#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("input", "r", stdin);
	vector<vector<string>> M;
	
	string line;
	while (getline(cin, line, '\n')) {
		stringstream ss(line);
		string num;
		vector<string> Mi;
		while (getline(ss, num, ' ')) {
			if (num.empty()) continue;
			Mi.push_back(num);
		}
		M.push_back(Mi);
	}

	ll result = 0;

	for (auto &xs : M) {
		for (auto x : xs) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int j = 0; j < M[0].size(); j++) {

		cout << M.back()[j] << endl;
		bool add = M.back()[j] == "+";
		ll total = add ? 0 : 1;

		for (int i = M.size() - 2; i >= 0; i--) {
			ll n = stol(M[i][j]);

			cout << n << endl;

			if (add) {
				total += n;
			} else {
				total *= n;
			}
		}

		cout << total << endl << endl;
		result += total;
	}

	cout << result << endl;

	return 0;
}
