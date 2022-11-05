// https://www.acmicpc.net/problem/2630
// 색종이 만들기

#include <iostream>

int CutPaper(int **paper, int x, int y, int size, int *white, int *black)
{
	if(size<=1)
	{
		return paper[x][y];
	}
	else
	{
		int color[4];
		color[0] = CutPaper(paper, x, y, size/2, white, black);
		color[1] = CutPaper(paper, x+(size/2), y, size/2, white, black);
		color[2] = CutPaper(paper, x, y+(size/2), size/2, white, black);
		color[3] = CutPaper(paper, x+(size/2), y+(size/2), size/2, white, black);

		bool isCutted = false;
		int sum = 0;
		for(int i=0; i<4; i++)
		{
			if(color[i]==-1) 
			{
				isCutted=true;
				break;
			}	
			sum += color[i];
		}

		if(!isCutted && (sum==4||sum==0))
		{
			return color[0];
		}
		else
		{
			for(int i=0; i<4; i++)
			{
				if(color[i]==0) (*white)++;
				else if(color[i]==1) (*black)++;
			}
			return -1;
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int **paper = new int*[N];
	for(int i=0; i<N; i++)
	{
		paper[i] = new int[N];
		for(int j=0; j<N; j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}

	int white=0, blue=0;

	int color = CutPaper(paper, 0, 0, N, &white, &blue);
	if(color==0) white++;
	else if(color==1) blue++;

	printf("%d\n%d", white, blue);

	return 0;
};