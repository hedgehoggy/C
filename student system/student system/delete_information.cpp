#include<stdio.h>
#include<string.h>
#include"struct.h"

void delete_information(student s[])
{
	FILE *fp;
	int j,i,a, N = 100;
	long int number;
	char name[20];
	char ch;

	fp = fopen("C:\\student record.txt", "a+");
	if ((fp = fopen("C:\\student record.txt", "a+")) == NULL)
		printf("File open error!\n");

	printf("\n------Search number or name.------\n");//选择检索方式。
	printf("1->number\n");
	printf("2->name\n");
	scanf("%d", &a);
	if (a == 1)//按学号检索。
	{
		printf("\n------Please input the student number you want to delete.------\n");
		scanf("%ld", &number);
		for (j = 0; j < N; j++)
		{
			if (number == s[j].number)
			{
				printf("\nThe student information:\n");//在控制台界面输出学生信息，确认是否删除。
				printf("name    number    math     english  programc PE\n");
				printf("%-8s%-10ld%-9d%-9d%-9d%d\n", s[j].name, s[j].number, s[j].math, s[j].english, s[j].programc, s[j].PE);
				printf("Delete or not?(Y/N)\n");
				getchar();//跳过回车字符。
				scanf("%c", &ch);
				if (ch == 'Y' || ch == 'y')
				{
					for (; j < N; j++)
						s[j] = s[j + 1];
					N--;
					printf("\nDelete successfully!\n\n");
					fclose(fp);
					fp = fopen("C:\\student record.txt", "w+");//再次打开文件，使文件原内容清空，重新输入表头及数据。
					fprintf(fp, "name    number    math     english  programc PE\n");
					for (int i = 0; s[i].number != 0; i++)
					{
						fprintf(fp, "%-8s%-10ld%-9d%-9d%-9d%d\n", s[i].name, s[i].number, s[i].math, s[i].english, s[i].programc, s[i].PE);
					}
				}
				else
					return;
			}
			else
				if (j == N - 1)
					printf("Cannot find the student information.\n");
		}
	}
	else//按姓名检索。
	{
		printf("\n------Please input the student name you want to delete.------\n");
		scanf("%s", name);
		for (j = 0; j < N; j++)
		{
			if (!strcmp(name,s[j].name))
			{
				printf("\nThe student information:\n");
				printf("name    number    math     english  programc PE\n");
				printf("%-8s%-10ld%-9d%-9d%-9d%d\n", s[j].name, s[j].number, s[j].math, s[j].english, s[j].programc, s[j].PE);
				printf("Delete or not?(Y/N)\n");
				getchar();
				scanf("%c", &ch);
				if (ch == 'Y' || ch == 'y')
				{
					for (; j < N; j++)
						s[j] = s[j + 1];
					N--;
					printf("Delete successfully!\n");
					fclose(fp);
					fp = fopen("C:\\student record.txt", "w+");
					fprintf(fp, "name    number    math     english  programc PE\n");
					for (int i = 0; s[i].number != 0; i++)
					{
						fprintf(fp, "%-8s%-10ld%-9d%-9d%-9d%d\n", s[i].name, s[i].number, s[i].math, s[i].english, s[i].programc, s[i].PE);
					}

				}
				else
					return;
			}
			else
				if (j == N - 1)
					printf("Cannot find the student information.\n");
		}
	}
	fclose(fp);
}
