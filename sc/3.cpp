//
// Created by Donggeon Byeon on 2024-10-15.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
void addLineSize(int& a, int& b, int& c, int bendCount)
{
	switch(bendCount)
	{
		case 0 : a++;
			break;
		case 1 : b++;
			break;
		case 2 : c++;
			break;
		default:
			//err
			break;
	}
}

int caluateSiteSize(vector<vector<int>>& cell, int N, int M, int i, int j, int bendCount=0, int a=0, int b=0, int c=0, int direction = 0)
{
	if(a == c+1 && b != 0){
		return a+b+c+3;
	}
	if(bendCount == 2 && b == 0) return -1;
	int res = -1;

	if(i > 0 && cell[i][j] == cell[i-1][j]) // 상
	{
		if(direction == 0 || direction == 1)
		{
			addLineSize(a, b, c, bendCount);
			res = max(res,caluateSiteSize(cell, N, M, i-1, j, bendCount, a, b, c, 1));
		}

		if(direction == 4 && bendCount < 2)
		{
			res = max(res,caluateSiteSize(cell, N, M, i-1, j, bendCount+1, a, b, c, 1));
		}
	}

	if(j < M-1 && cell[i][j] == cell[i][j+1]) // 우
	{
		if(direction == 0 || direction == 2)
		{
			addLineSize(a, b, c, bendCount);
			res = max(res,caluateSiteSize(cell, N, M, i, j+1, bendCount, a, b, c, 2));
		}

		if(direction == 1 && bendCount < 2)
		{
			res = max(res,caluateSiteSize(cell, N, M, i, j+1, bendCount+1, a, b, c, 2));
		}
	}

	if(i < N-1 && cell[i][j] == cell[i+1][j]) // 하
	{
		if(direction == 0 || direction == 3)
		{
			addLineSize(a, b, c, bendCount);
			res = max(res,caluateSiteSize(cell, N, M, i+1, j, bendCount, a, b, c, 3));
		}

		if(direction == 2 && bendCount < 2)
		{
			res = max(res,caluateSiteSize(cell, N, M, i+1, j, bendCount+1, a, b, c, 3));
		}
	}

	if(j > 0 && cell[i][j] == cell[i][j-1]) // 좌
	{
		if(direction == 0 || direction == 4)
		{
			addLineSize(a, b, c, bendCount);
			res = max(res,caluateSiteSize(cell, N, M, i, j-1, bendCount, a, b, c, 4));
		}

		if(direction == 3 && bendCount < 2)
		{
			res = max(res,caluateSiteSize(cell, N, M, i, j-1, bendCount+1, a, b, c, 4));
		}
	}

	return res;
}

int solution(vector<string> cells) {
	int answer = -1;

	int N, M;
	vector<vector<int>> C;
	for(string line : cells)
	{
		vector<int> cLine;
		for(char oner : line)
		{
			int onerNum = oner - 'A';
			cLine.push_back(onerNum);
		}
		C.push_back(cLine);
	}

	N = C.size();
	M = C[0].size();

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			answer = max(answer,caluateSiteSize(C, N, M, i, j));
		}
	}

	return answer;
}

*/


int solution(vector<string> cells) {
	int answer = -1;

	int N, M;
	vector<vector<int>> C;
	for(string line : cells)
	{
		vector<int> cLine;
		for(char oner : line)
		{
			int onerNum = oner - 'A';
			cLine.push_back(onerNum);
		}
		C.push_back(cLine);
	}

	// C = {{0, 0, 0, 0,0,0,0}, {0, 0, 0, 0,0,0,0},{0, 0, 0, 0,0,0,0},{0, 0, 0, 0,0,0,0},{0, 0, 0, 0,0,0,0},{0, 0, 0, 0,0,0,0}};

	N = C.size();
	M = C[0].size();

	vector<vector<int>> right(N, vector<int>(M));
	vector<vector<int>> down(N, vector<int>(M));
	vector<vector<int>> left(N, vector<int>(M));
	vector<vector<int>> up(N, vector<int>(M));

	for(int i = 0; i< N; i++)
	{
		right[i][M-1] = 0;
		for(int j=M-2; j>=0; j--)
		{
			if(C[i][j] == C[i][j+1]) right[i][j] = right[i][j+1] + 1;
			else right[i][j] = 0;
		}
	}

	for(int j = 0; j< M; j++)
	{
		down[N-1][j] = 0;
		for(int i=N-2; i>=0; i--)
		{
			if(C[i][j] == C[i+1][j]) down[i][j] = down[i+1][j] + 1;
			else down[i][j] = 0;
		}
	}

	for(int i = 0; i< N; i++)
	{
		left[i][0] = 0;
		for(int j=1; j<M; j++)
		{
			if(C[i][j] == C[i][j-1]) left[i][j] = left[i][j-1] + 1;
			else left[i][j] = 0;
		}
	}

	for(int j = 0; j< M; j++)
	{
		up[0][j] = 0;
		for(int i=1; i<N; i++)
		{
			if(C[i][j] == C[i-1][j]) up[i][j] = up[i-1][j] + 1;
			else up[i][j] = 0;
		}
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			int rightLength = right[i][j];
			int downLength = down[i][j];

			if(rightLength > 1 && downLength > 0)
			{
				for(int k=j+2; k-j<=rightLength; k++)
				{
					if(down[i][k] == 0) continue;
					int a = k-j+1;
					int b = min(downLength, down[i][k]);
					answer = max(answer, a+b*2);
				}
			}

			if(downLength > 1 && rightLength > 0)
			{
				for(int k=i+2; k-i<=downLength; k++)
				{
					if(right[k][j] == 0) continue;
					int a = k-i+1;
					int b = min(rightLength, right[k][j]);
					answer = max(answer, a+b*2);
				}
			}

			int leftLength = left[i][j];
			int upLength = up[i][j];

			if(leftLength > 1 && upLength > 0)
			{
				for(int k=j-2; j-k<=leftLength; k--)
				{
					if(up[i][k] == 0) continue;
					int a = j-k+1;
					int b = min(upLength, up[i][k]);
					answer = max(answer, a+b*2);
				}
			}

			if(upLength > 1 && leftLength > 0)
			{
				for(int k=i-2; i-k<=upLength; k--)
				{
					if(left[k][j] == 0) continue;
					int a = i-k+1;
					int b = min(leftLength, left[k][j]);
					answer = max(answer, a+b*2);
				}
			}
		}
	}

	return answer;
}

int main()
{
	// vector<string> cells = {"AAAAAA", "BABBAA", "BBABAA", "BBABAA", "AAAAAB"};
	vector<string> cells =
			{"AABAACAAA", "AAAAAADAA", "AAAADAAAA", "AAADAAAAA", "AADAAAAAA", "AAAEAAAAA", "AAAAAFAAA", "AAAZAAAAA", "AAAAZZZAA", "AAAAAZAAA", "AZZZZZAAA"};

	auto res = solution(cells);
	cout << res;

	return 0;
}