#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream file("in");

	int total = 50;
	int count = 0;

	string line;
	while (file >> line) {
		char sign = line[0];
		int val = atoi(line.c_str() + 1);
		
		if (sign == 'L') {
			total = (total - val) % 100;
		}
		else {
			total = (total + val) % 100;
		}

		if (total == 0) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}
