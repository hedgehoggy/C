#pragma once
#define N 22

class SnakePosition
{
public:
	int X,Y;
	void initialize(int &);
};

class SnakeMap
{
public:
	SnakeMap(int,int,int,int,char);
	void initialize();
	void ShowGame();
	void GetGrade();
	void display();
	void SetPoint();
	bool UpdateGame();
private:
	char s[N][N];
	int grade,length;
	int gamespeed;
	char direction;
	int head, tail;
	int score;
	bool gameauto;
};

SnakeMap::SnakeMap(int h=4,int t=1,int l=4,int s=0,char d=77)
{
	head = h;
	tail = t;
	length = l;
	score = s;
	direction = d;
}
