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
int m, n;//�������

int main()
{
	char ctn = 'y';
	bool nodead; 
	cout << "\n\n\n\n\n\t\t\t ��ӭ����̰������Ϸ!" << endl;//��ӭ����;
	cout<<"\n\n\n\t\t\t ����������Ͽ�ʼ"<<endl;//׼����ʼ;;
	getch(); 
	while( ctn=='y'||ctn=='Y' ) 
	{ 
		system("cls"); // ����
		SnakeMap snake; 
		snake.initialize(); 
		cout << "\n\n����������ѡ����Ϸ�ȼ���" << endl;
		cout << "\n\n\n\t\t\t1.�ȼ�һ���ٶ� 1000 \n\n\t\t\t2.�ȼ������ٶ� 800 \n\n\t\t\t3.�ȼ������ٶ� 600 "; 
		cout << "\n\n\t\t\t4.�ȼ��ģ��ٶ� 400 \n\n\t\t\t5.�ȼ��壺�ٶ� 200 \n\n\t\t\t6.�ȼ������ٶ� 100 \n\n\t\t\t7.�Զ�����ģʽ" << endl;
		snake.GetGrade();//��ȡ�ȼ� 
		for(int i=1;i<=4;i++) 
		{
			position[i].initialize(i);//��ʼ������
		}
		snake.SetPoint(); // ������һ����
		do 
		{ 
			snake.ShowGame(); 
			nodead = snake.UpdateGame(); 
		}while(nodead);
		system("cls"); //����
		cout << "\n\n\n\t\t\t\tGameover��\n\n"<<endl; 
		snake.display();//����ȼ�/�÷����
		cout << "\n\n\n\t\t �Ƿ�ѡ�������Ϸ������ Y ������N �˳�" << endl; 
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

		if (i == 2) cout << "\t�ȼ���" << grade;
		if (i == 6) cout << "\t�ٶȣ�" << gamespeed;
		if (i == 10) cout << "\t�÷֣�" << score << "��";
		if (i == 14) cout << "\t��ͣ����һ�¿ո��";
		if (i == 18) cout << "\t�����������¿ո��";
	}
}

void SnakeMap::GetGrade()
{
	cin >> grade;
	while (grade > 7 || grade < 1)
	{
		cout << "������1-7���ڵ�����\n";
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
	cout << "\n\t\t\t\t�ȼ���" << grade;
	cout << "\n\n\n\t\t\t\t�ٶȣ�" << gamespeed;
	cout << "\n\n\n\t\t\t\t�÷֣�" << score << "��";
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
			s[x][y] = '#'; //������ͷ 
			s[position[head].X][position[head].Y] = '*'; //���׺�ԭ����ͷ��Ϊ����
			head = (head+1) % ( (N-2)*(N-2) ); //ȡ��ͷ���� 
			position[head].X = x; 
			position[head].Y = y; 
			ShowGame(); 
			gameover = 1; 
			score += grade*20; //�ӷ� 
			SetPoint(); //������
		}
		else
		{
			s[position[tail].X][position[tail].Y] = ' ';//����β�ÿ� 
			tail= (tail+1) % ( (N-2) * (N-2) );//������β���� 
			s[position[head].X][position[head].Y]='*'; //����ͷ��Ϊ���� 
			head= (head+1) % ( (N-2) * (N-2) ); 
			position[head].X = x; 
			position[head].Y = y;
			s[position[head].X][position[head].Y]='#'; //������ͷ
			gameover = true;
		}
	}
	return gameover;
}