#include<stdio.h>
#include"struct.h"
void count_information(student s[])
{
	FILE *fp;
	fp = fopen("C:\\student record.txt", "r");
	int i = 0, j, N, sum = 0;

	fseek(fp, 47, 0);
	while (!feof(fp))
	{
		fscanf(fp, "%s %ld %d %d %d %d", &s[i].name, &s[i].number, &s[i].math, &s[i].english, &s[i].programc, &s[i].PE);
		i++;
	}
	N = i - 1;//计算实际输入成绩的学生个数。
	printf("\n\n------Please input a number to execute the command------\n");
	printf("1->the average score of math\n");
	printf("2->the average score of english\n");
	printf("3->the average score of programc\n");
	printf("4->the average score of PE\n");
	printf("5->the average score of total points\n");
	printf("6->the sum score of everybody\n");

	int num;
	scanf("%d", &num);
	switch (num)//计算平均分及总分。
	{
	case 1:
		for (j = 0; j < N; j++)
			sum += s[j].math;
		printf("\nThe average score of math is %.2lf.\n\n", sum*1.0 / N);
		break;
	case 2:
		for (j = 0; j < N; j++)
			sum += s[j].english;
		printf("\nThe average score of english is %.2lf.\n\n", sum*1.0 / N);
		break;
	case 3:
		for (j = 0; j < N; j++)
			sum += s[j].programc;
		printf("\nThe average score of programc is %.2lf.\n\n", sum*1.0 / N);
		break;
	case 4:
		for (j = 0; j < N; j++)
			sum += s[j].PE;
		printf("\nThe average score of PE is %.2lf.\n\n", sum*1.0 / N);
		break;
	case 5:
		for (j = 0; j < N; j++)
			sum += (s[j].math + s[j].english + s[j].programc + s[j].PE);
		printf("\nThe average score of total points is %.2lf.\n\n", sum*1.0 / N);
		break;
	case 6:
		for (j = 0; j < N; j++)
		{
			sum = s[j].math + s[j].english + s[j].programc + s[j].PE;
			printf("\nThe sum score of %s is %d.\n\n", s[j].name, sum);
		}
		break;
	default:
		printf("You input the wrong command.");
		break;
	}
	fclose(fp);//关闭文件。
}
