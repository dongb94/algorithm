#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> bf) {
	vector<vector<int>> answer;

	int **a = new int*[n+1];
	for (int i = 0; i < n+1; i++) {
		a[i] = new int[n+1];
		for (int j = 0; j < n + 1; j++) {
			a[i][j] = -1;
		}
	}
	
	for (int i = 0; i < bf.size(); i++) {
		int x = bf[i][0];
		int y = bf[i][1];
		if (bf[i][3] == 0) {
			if (a[x][y] == -1) continue;
			if (a[x][y] != bf[i][2] && a[x][y] !=2) continue;
			if (bf[i][2] = 0) {
				if (a[x][y + 1] == -1);
				else if (a[x][y + 1] = 0) {
					if (x == 0) continue;
					if (a[x - 1][y + 1] == 1 || a[x - 1][y + 1] == 2);
					else continue;
				}
				else{
					if (x != n) {
						if (a[x + 1][y] == 0 || a[x + 1][y] == 2);
						else if (x == 0) continue;
						else if ((a[x - 1][y + 1] == 1 || a[x - 1][y + 1] == 2)
							&& (a[x+1][y+1] == 1 || a[x+1][y+1] == 2));
						else continue;
					}
				}

				if (x == 0);
				else if (a[x-1][y+1] == 1 || a[x-1][y+1] ==2) {
					if (a[x - 1][y] == 0 || a[x - 1][y] == 2);
					else if (x - 1 == 0) continue;
					else if ((a[x-2][y+1] == 1 || a[x - 2][y + 1] == 2)
						&& (a[x][y + 1] == 1 || a[x][y + 1] == 2));
					else continue;
				}

				a[x][y] == 2 ? a[x][y] = 1: a[x][y] = -1;
			}
			else {
				if (a[x][y] == 2) {
					if (a[x][y - 1] == 0 || a[x][y - 1] == 2);
					else if (x == 0) continue;
					else if (a[x - 1][y] == 1 || a[x - 1][y] == 2);
					else continue;
				}
				
				if (a[x + 1][y] == 0) {
					if (a[x + 1][y - 1] == 0 || a[x + 1][y - 1] == 2);
					else continue;
				}
				else {
					if (a[x + 1][y - 1] == 0 || a[x + 1][y - 1] == 2);
					else if (a[x + 2][y - 1] == 0 || a[x + 2][y - 1] == 2);
					else continue;
				}

				if (x == 0);
				else if (a[x - 1][y] == 1 || a[x - 1][y] == 2) {
					if (a[x - 1][y - 1] == 0 || a[x - 1][y - 1] == 2);
					else if (a[x][y - 1] == 0 || a[x][y - 1] == 2);
					else continue;
				}

				a[x][y] == 2 ? a[x][y] = 0 : a[x][y] = -1;
			}
		}
		else {
			if (bf[i][2] == 0) {
				if (y == n) continue;
				if (y == 0);
				else if (a[x][y - 1] == 0 || a[x][y - 1] == 2);
				else if (a[x][y] == 1);
				else if (x == 0) continue;
				else if (a[x - 1][y] == 1 || a[x - 1][y] == 2);
				else continue;

				a[x][y] == 1 ? a[x][y] = 2 : a[x][y] = 0;
			}
			else {
				if (x == n || y == 0) continue;
				if (a[x][y - 1] == 0 || a[x][y - 1] == 2);
				else if (a[x + 1][y - 1] == 0 || a[x + 1][y - 1] == 2);
				else if (x == 0) continue;
				else if ((a[x-1][y] == 1 || a[x-1][y] == 2) 
					&& (a[x+1][y] == 1 || a[x+1][y] == 2));
				else continue;

				a[x][y] == 0 ? a[x][y] = 2 : a[x][y] = 1;
			}
		}
		
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (a[i][j] == 0) {
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				v.push_back(0);
				answer.push_back(v);
			}
			else if (a[i][j] == 1) {
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				v.push_back(1);
				answer.push_back(v);
			}
			else if (a[i][j] == 2) {
				vector<int> v, v2;
				v.push_back(i);
				v.push_back(j);
				v.push_back(0);
				v2.push_back(i);
				v2.push_back(j);
				v2.push_back(1);
				answer.push_back(v);
				answer.push_back(v2);
			}
		}
	}

	return answer;
}