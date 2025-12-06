#include <bits/stdc++.h>
using namespace std;

long string_to_long(string S, int n) {
	long r = 0;
	for (int i = 0; i < n; i++) {
		r = r * 10 + (S[i] - '0');
	}
	return r;
}

long max_joltage(string line, int batteries) {
	long to_remove = line.length() - batteries;

	string S = "";
	S.reserve((long)line.size());

	for (char c : line) {
		while (!S.empty() && c > S.back() && to_remove > 0) {
			S.pop_back();
			to_remove--;
		}
		S.push_back(c);
	}

	return string_to_long(S, batteries);
}

int main() {
	ifstream file("bigboy");
	string line;

	long long sum = 0;

	while (file >> line) {
		long mj = max_joltage(line, 12);
		sum += mj;
	}

	cout << sum << endl;

	return 0;
}
