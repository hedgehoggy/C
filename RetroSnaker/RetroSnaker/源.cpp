#include<iostream>
#include<cstdlib>
#include<time.h>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include"class.h"
#define N 22

using namespace std;

SnakePosition position[(N - 2)*(N - 2)-1];
bool gameover;
long start;
int x, y;
int m, n;//随机出米

int main()
{
	char ctn = 'y';
	bool nodead; 
	cout << "\n\n\n\n\n\t\t\t 欢迎进入贪吃蛇游戏!" << endl;//欢迎界面;
	cout<<"\n\n\n\t\t\t 按任意键马上开始"<<endl;//准备开始;;
	getch(); 
	while( ctn=='y'||ctn=='Y' ) 
	{ 
		system("cls"); // 清屏
		SnakeMap snake; 
		snake.initialize(); 
		cout << "\n\n请输入数字选择游戏等级：" << endl;
		cout << "\n\n\n\t\t\t1.等级一：速度 1000 \n\n\t\t\t2.等级二：速度 800 \n\n\t\t\t3.等级三：速度 600 "; 
		cout << "\n\n\t\t\t4.等级四：速度 400 \n\n\t\t\t5.等级五：速度 200 \n\n\t\t\t6.等级六：速度 100 \n\n\t\t\t7.自动升级模式" << endl;
		snake.GetGrade();//获取等级 
		for(int i=1;i<=4;i++) 
		{
			position[i].initialize(i);//初始化坐标
		}
		snake.SetPoint(); // 产生第一个米
		do 
		{ 
			snake.ShowGame(); 
			nodead = snake.UpdateGame(); 
		}while(nodead);
		system("cls"); //清屏
		cout << "\n\n\n\t\t\t\tGameover！\n\n"<<endl; 
		snake.display();//输出等级/得分情况
		cout << "\n\n\n\t\t 是否选择继续游戏？输入 Y 继续，N 退出" << endl; 
		cin >> ctn; 
	}
	return 0;
}

void SnakePosition::initialize(int &j)
{
	x = 1;
	y = j;
}

void SnakeMap::initialize()
{
	int i, j;
	for (i = 1; i < N - 1; i++)
	{
		for (j = 1; j < N - 1; j++)
			s[i][j] = ' ';
	}
	for (i = 1; i <= head-1; i++)
		s[1][i] = '*';
	s[1][head] = '#';
	for (i = 0; i < N; i++)
	{
		s[0][i] = '-';
		s[N - 1][i] = '-';
	}
	for (j = 0; j < N; j++)
	{
		s[j][0] = '|';
		s[j][N - 1] = '|';
	}
}

void SnakeMap::ShowGame()
{
	system("cls");
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << s[i][j] << " ";
		}
		cout << endl;

		if (i == 2) cout << "\t等级：" << grade;
		if (i == 6) cout << "\t速度：" << gamespeed;
		if (i == 10) cout << "\t得分：" << score << "分";
		if (i == 14) cout << "\t暂停：按一下空格键";
		if (i == 18) cout << "\t继续：按两下空格键";
	}
}

void SnakeMap::GetGrade()
{
	cin >> grade;
	while (grade > 7 || grade < 1)
	{
		cout << "请输入1-7以内的数字\n";
		cin >> grade;
	}
	switch (grade)
	{
	case 1:
		gamespeed = 1000;
		gameauto = 0;
		break;
	case 2:
		gamespeed = 800;
		gameauto = 0;
		break;
	case 3:
		gamespeed = 600;
		gameauto = 0;
		break;
	case 4:
		gamespeed = 400;
		gameauto = 0;
		break;
	case 5:
		gamespeed = 200;
		gameauto = 0;
		break;
	case 6:
		gamespeed = 100;
		gameauto = 0;
		break;
	case 7:
		grade = 1;
		gamespeed = 1000;
		gameauto = 1;
		break;
	}
}

void SnakeMap::display()
{
	cout << "\n\t\t\t\t等级：" << grade;
	cout << "\n\n\n\t\t\t\t速度：" << gamespeed;
	cout << "\n\n\n\t\t\t\t得分：" << score << "分";
}

void SnakeMap::SetPoint()
{
	srand(time(0));
	do
	{
		m = rand() % (N - 2) + 1;
		n = rand() % (N - 2) + 1;
	} while (s[m][n] != ' ');
	s[m][n] = '*';
}

bool SnakeMap::UpdateGame()
{
	char key;
	gameover =true;
	key = direction;
	start = clock();
	while ((gameover = (clock() - start <= gamespeed)) && !kbhit())
	{
		if (gameover)
		{
			//getch();
			key = getch();
		}
		if (key == ' ')
		{
			while (getch()!= ' ') {}
		}
		else
			direction = key;
		switch (direction)
		{
		 case 72: 
			 x = position[head].X - 1; 
			 y = position[head].Y;
			 break;  
		 case 80: 
			 x= position[head].X + 1;
			 y= position[head].Y;
			 break; 
		 case 75: 
			 x= position[head].X;
			 y= position[head].Y - 1;
			 break; 
		 case 77: 
			 x= position[head].X; 
			 y= position[head].Y + 1; 
			 break;
		}

		if (!(direction == 72 || direction == 75 || direction == 77 || direction == 80))
			gameover = false;
		else if (x == 0 || x == N - 1 || y == 0 || y == N - 1)
			gameover = false;
		else if (s[x][y] != ' ' && !(x == m&&y == n))
			gameover = false;
		else if (x == m&&y == n)
		{
			length++;
			if (length >= 8 && gameauto) 
			{
				length -= 8;
				grade++; 
				if (gamespeed >= 200)
					gamespeed -= 200; 
				else 
					gamespeed = 100;
			}
			s[x][y] = '#'; //更新蛇头 
			s[position[head].X][position[head].Y] = '*'; //吃米后将原先蛇头变为蛇身
			head = (head+1) % ( (N-2)*(N-2) ); //取蛇头坐标 
			position[head].X = x; 
			position[head].Y = y; 
			ShowGame(); 
			gameover = 1; 
			score += grade*20; //加分 
			SetPoint(); //产生米
		}
		else
		{
			s[position[tail].X][position[tail].Y] = ' ';//将蛇尾置空 
			tail= (tail+1) % ( (N-2) * (N-2) );//更新蛇尾坐标 
			s[position[head].X][position[head].Y]='*'; //将蛇头更为蛇身 
			head= (head+1) % ( (N-2) * (N-2) ); 
			position[head].X = x; 
			position[head].Y = y;
			s[position[head].X][position[head].Y]='#'; //更新蛇头
			gameover = true;
		}
	}
	return gameover;
}