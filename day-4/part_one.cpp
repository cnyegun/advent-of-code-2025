#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("input", "r", stdin);
	vector<string> M;

	string line = "";

	while (cin >> line) {
		M.push_back(line);
	}

	int height = M.size();
	int width = M[0].length();

	int total = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int count = 0;
			if (M[i][j] == '.') continue;
			// TOP_LEFT
			if ((i - 1) >= 0 && (j - 1) >= 0 
				&& M[i - 1][j - 1] == '@')
				count++;
			// TOP
			if ((i - 1) >= 0
				&& M[i - 1][j] == '@')
				count++;
			// TOP RIGHT
			if ((i - 1) >= 0 && (j + 1) < width
				&& M[i - 1][j + 1] == '@')
				count++;
			// LEFT
			if ((j - 1) >= 0 
				&& M[i][j - 1] == '@')
				count++;
			// RIGHT
			if ((j + 1) < width
				&& M[i][j + 1] == '@')
				count++; 
			// BOT LEFT
			if ((i + 1) < height && (j - 1) >= 0
				&& M[i + 1][j - 1] == '@')
				count++;
			// BOT 
			if ((i + 1) < height
				&& M[i + 1][j] == '@')
				count++;
			// BOT RIGHT
			if ((i + 1) < height && (j + 1) < width
				&& M[i + 1][j + 1] == '@')
				count++;

			if (count < 4) total++;

		}
	}

	cout << total << '\n';

	return 0;
}
