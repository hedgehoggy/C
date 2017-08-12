#include<stdio.h>
#include<string.h>
#include"struct.h"

void search_information(student s[])
{
	FILE *fp = fopen("C:\\student record.txt", "r");
	long int number;
	int i = 0,a;
	char name[20];

	if (fp == NULL)
		printf("File open error!\n");

	printf("\n------Search number or name.------\n");
	printf("1->number\n");
	printf("2->name\n");
	scanf("%d", &a);
	if (a == 1)//��ѧ�ż��������������ѧ����Ϣ��
	{
		printf("\n------Please input the student number you want to search.------\n");
		scanf("%ld", &number);

		for (int j = 0; j < 100; j++)
		{
			if (number == s[j].number)
			{
				printf("\nThe student information��\n");
				printf("name    number    math     english  programc PE\n");
				printf("%-8s%-10ld%-9d%-9d%-9d%d\n", s[j].name, s[j].number, s[j].math, s[j].english, s[j].programc, s[j].PE);
				printf("\n------Next step------\n");
				return;
			}
		}
		printf("Cannot find the student information.\n");//������ʧ�ܣ�����Ҳ���������Ϣ��
	}
	else//���������������������ѧ����Ϣ��
	{
		printf("\n------Please input the student name you want to search.------\n");
		scanf("%s", name);

		for (int j = 0; j <100; j++)
		{
			if (!strcmp(name ,s[j].name))
			{
				printf("\nThe student information��\n");
				printf("name    number    math     english  programc PE\n");
				printf("%-8s%-10ld%-9d%-9d%-9d%d\n", s[j].name, s[j].number, s[j].math, s[j].english, s[j].programc, s[j].PE);
				printf("\n------Next step------\n");
				return;
			}
		}
		printf("Cannot find the student information.\n");//������ʧ�ܣ�����Ҳ���������Ϣ��
	}
	fclose(fp);
	printf("\n------Next step------\n");
}

