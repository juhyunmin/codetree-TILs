#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int R, C, K;
int map[81][81];
bool EX[81][81];

struct G{
	int c;
	int d;
};

struct Node {
	int x;
	int y;
	int num;
};
G golem[1011];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ans;


void input()
{
	cin >> R >> C >> K;
	for (int i = 1; i <= K; i++)
	{
		int c, d;
		cin >> c >> d;
		golem[i].c = c;
		golem[i].d = d;
	}
}

bool move_down(int x, int y)
{
	int X1 = x + 2;
	int Y1 = y;

	int X2 = x + 1;
	int Y2 = y - 1;

	int X3 = x + 1;
	int Y3 = y + 1;

	if (X1 > R || X2 > R || Y2 <= 0 || X3 > R || Y3 > C) {
		return false;
	}

	if (map[X1][Y1] == 0 && map[X2][Y2] == 0 && map[X3][Y3] == 0) {
		return true;
	}
	 
	return false;
}
bool move_left(int x, int y)
{
	int X1 = x;
	int Y1 = y - 2;

	int X2 = x - 1;
	int Y2 = y - 1;

	int X3 = x + 1;
	int Y3 = y - 1;

	if (Y1 <= 0 || Y2 <= 0 || X3 > R || Y3 <= 0) {
		return false;
	}
	if (map[X1][Y1] == 0 && map[X2][Y2] == 0 && map[X3][Y3] == 0) {
		if (move_down(x, y - 1)){
			return true;
		}
	}
	return false;
}
bool move_right(int x, int y)
{
	int X1 = x;
	int Y1 = y + 2;

	int X2 = x - 1;
	int Y2 = y + 1;

	int X3 = x + 1;
	int Y3 = y + 1;
	if (Y1 > C || Y2 > C || X3 > R || Y3 > C)
		return false;
	if (map[X1][Y1] == 0 && map[X2][Y2] == 0 && map[X3][Y3] == 0)
	{
		if (move_down(x, y + 1))
			return true;
	}return false;
}

void move_go(int n, int x, int y)
{
	int exit_x = x + dx[golem[n].d];
	int exit_y = y + dy[golem[n].d];

	bool visited[71][71] = { false };

	queue <Node> q;

	q.push({ exit_x,exit_y,n });

	visited[exit_x][exit_y] = true;

	int temp_x = 0;
	while (!q.empty())
	{
		int num = q.front().num;
		if (q.front().x > temp_x)
		{
			temp_x = q.front().x;
		}
		for (int i = 0; i < 4; i++)
		{
			int X = q.front().x + dx[i];
			int Y = q.front().y + dy[i];
			if (X > 0 && Y > 0 && X <= R && Y <= C && !visited[X][Y] && map[X][Y] != 0)
			{
				if (num == map[X][Y])
				{
					q.push({ X,Y,map[X][Y] });
					visited[X][Y] = true;
				}
				else if (EX[q.front().x][q.front().y])
				{
					q.push({ X,Y ,map[X][Y] });
					visited[X][Y] = true;
				}
			}
		}
		q.pop();
	}
	ans += temp_x;
}
void clean()
{
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			map[i][j] = 0;
			EX[i][j] = 0;
		}
}
void move_golem(int n)
{
	int x = -1;
	int y = golem[n].c;

	while (true)
	{
		if (move_down(x, y))
		{
			x++;
		}
		else if (move_left(x, y))
		{
			x++;
			y--;
			golem[n].d--;
			if (golem[n].d == -1)
				golem[n].d = 3;
		}
		else if (move_right(x, y))
		{
			x++;
			y++;
			golem[n].d++;
			if (golem[n].d == 4)
				golem[n].d = 0;
		}
		else
			break;
	}

	if (x <= 1)
	{
		clean();
	}
	else
	{
		map[x][y] = n;
		EX[x + dx[golem[n].d]][y + dy[golem[n].d]] = true;
		for (int i = 0; i < 4; i++)
		{
			map[x + dx[i]][y + dy[i]] = n;
		}
		move_go(n, x, y);
	}
}

int main()
{
	//freopen("sample.txt", "r", stdin);
	input();

	for (int i = 1; i <= K; i++) {
		move_golem(i);
	}

	cout << ans;
	return 0;
}