#include<stdio.h>
#include<string.h>
#include"struct.h"

void edit_information(student s[])
{
	FILE *fp = fopen("C:\\student record.txt", "w+");
	long int number;
	int a,grade;
	char name[20];

	if (fp == NULL)
		printf("file open error!\n");
	
	printf("\n------Search number or name.------\n");//选择查找方式。姓名与学号方式大致相同，因此除第一步查找以外，后续编辑操作代码相同。
	printf("1->number\n");
	printf("2->name\n");
	scanf("%d", &a);
	if (a == 1)//按学号检索。
	{
		printf("\n------Please input the number of student you want to edit.------\n");
		scanf("%ld", &number);

		for (int j = 0; j < 101; j++)//以学号方式查找该学生。
		{
			if (number == s[j].number)//找到该学生后输出该生信息至控制台界面，选择要改动信息。
			{
				printf("\nThe student information：\n");
				printf("name    number    math     english  programc PE\n");
				printf("%-8s%-10ld%-9d%-9d%-9d%d\n", s[j].name, s[j].number, s[j].math, s[j].english, s[j].programc, s[j].PE);
				printf("\n------Please input the information you want to correct.------\n");
				printf("1->math\n");
				printf("2->english\n");
				printf("3->programc\n");
				printf("4->PE\n");
				int t;
				scanf("%d", &t);
				switch (t)
				{
				case 1:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].math = grade;
					break;
				case 2:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].english = grade;
					break;
				case 3:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].programc = grade;
					break;
				case 4:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].PE = grade;
					break;
				default:
					printf("\nYou input the wrong command.\n");
					break;
				}
			}
		}
	}
	else//按姓名检索。
	{
		printf("\n------Please input the name of student you want to edit.------\n");
		scanf("%s", name);

		for (int j = 0; j < 101; j++)
		{
			if (!strcmp(name,s[j].name))
			{
				printf("\nThe student information：\n");
				printf("name    number    math     english  programc PE\n");
				printf("%-8s%-10ld%-9d%-9d%-9d%d\n", s[j].name, s[j].number, s[j].math, s[j].english, s[j].programc, s[j].PE);
				printf("\n------Please input the information you want to correct.------\n");
				printf("1->math\n");
				printf("2->english\n");
				printf("3->programc\n");
				printf("4->PE\n");
				int t;
				scanf("%d", &t);
				switch (t)
				{
				case 1:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].math = grade;
					break;
				case 2:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].english = grade;
					break;
				case 3:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].programc = grade;
					break;
				case 4:
					printf("\n------Please input the correct grade.------\n");
					scanf("%d", &grade);
					s[j].PE = grade;
					break;
				default:
					printf("\nYou input the wrong command.\n");
					break;
				}
			}
		}
	}
	rewind(fp);//重新定位至文件开头，输入表头及学生信息，此时错误信息已被更正。
	fprintf(fp, "name    number    math     english  programc PE\n");
	for (int i = 0; s[i].number != 0; i++)
	{
		fprintf(fp, "%-8s%-10ld%-9d%-9d%-9d%d\n", s[i].name, s[i].number, s[i].math, s[i].english, s[i].programc, s[i].PE);
	}

	fclose(fp);
	printf("\n------Next step------\n");
}