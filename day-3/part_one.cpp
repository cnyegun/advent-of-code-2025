#include <bits/stdc++.h>
using namespace std;

int to_int(char a, char b) {
	return ((a - '0') * 10) + (b - '0');
}

int main() {
	ifstream file("input");
	string bank;

	int sum = 0;
	while (file >> bank) {
		int len = bank.length();
		int max_n = to_int(bank[0], bank[1]);
		for (int i = 0; i < len - 1; i++ ) {
			for (int j = i + 1; j < len; j++) {
				int val = to_int(bank[i], bank[j]);
				if (val > max_n) max_n = val;
			}
		}
		cout << max_n  << endl;
		sum += max_n;
	}
	cout << sum << endl;
	return 0;
}
