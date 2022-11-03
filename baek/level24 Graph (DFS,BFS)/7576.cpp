//https://www.acmicpc.net/problem/7576
//토마토

#include <iostream>
#include <queue>

int arround[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct tomato
{
	int x, y;
};

std::queue<tomato> ripeTomato;
std::queue<tomato> nextTomato;

int ripe(int N, int M, int **box)
{
	while (!ripeTomato.empty())
	{
		tomato t = ripeTomato.front();
		for(int i=0; i<4; i++)
		{
			int x=t.x + arround[i][0];
			int y=t.y + arround[i][1];

			if(x>=N
			|| x<0
			|| y>=M
			|| y<0) continue;

			if(box[x][y]==0)
			{
				box[x][y] = 1;
				nextTomato.push({x,y});
			} 
			else continue;
		}
		ripeTomato.pop();
	}

	if(nextTomato.empty()) return 0;
	
	ripeTomato.swap(nextTomato);

	return 1;
}

int main(void)
{
	int M,N;
	scanf("%d %d", &M, &N);

	int **box = new int*[N];
	for(int i=0; i<N; i++)
	{
		box[i] = new int[M];
		for(int j=0; j<M; j++)
		{
			scanf("%d", &box[i][j]);
			if(box[i][j]==1) ripeTomato.push({i,j});
		}
	}

	int count = 0;
	while(ripe(N,M,box))
	{
		count++;
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(box[i][j]==0) 
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	printf("%d", count);

	return 0;
}