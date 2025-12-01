#include <bits/stdc++.h>
using namespace std;

int main() {
	string fileName;
	cin >> fileName;
	ifstream file(fileName);

	int total = 50;
	int count = 0;

	cout << "The dial starts by pointing at 50\n";
	
	string line;
	while (file >> line) {
		char sign = line[0];
		int val = atoi(line.c_str() + 1);
		int wraps = val / 100;	
		int prev = total;

		val -= wraps * 100;

		count += wraps;

		if (sign == 'L') {
			if (total != 0 && val > total) {
				count += 1;
			}
			total = (((total - val) % 100) + 100) % 100;
		}
		else {
			if (total != 0 && val + total > 100) {
				count += 1;
			}
			total = (((total + val) % 100) + 100) % 100;
		}

		if (total == 0) {
			count++;
		}

		cout << prev << " + " + line << " -> " << total << " | Count: " << count << endl;
	}

	cout << count << endl;

	return 0;
}
