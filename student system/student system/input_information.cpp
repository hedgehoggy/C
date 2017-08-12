#include<stdio.h>
#include"struct.h"
#include"copy_information.h"

void input_information(student s[])
{
	FILE *fp=fopen("C:\\student record.txt", "r+");//打开文件，原有数据不清空。
	student c;

	if (fp == NULL)
		printf("file open error!\n");

	printf("\n------Please input student information.------\n\n");//输入需要添加的学生信息。
	printf("student name: ");
	scanf("%s", &c.name);
	printf("student number: ");
	scanf("%ld", &c.number);
	printf("student grade: ");
	scanf("%d %d %d %d", &c.math,&c.english,&c.programc,&c.PE);

	fseek(fp, 0, 2);//定位至文件末尾，向文件追加数据。
	fprintf(fp, "%-8s%-10ld%-9d%-9d%-9d%-9d\n", c.name,c.number,c.math,c.english,c.programc,c.PE);
	rewind(fp);//定位至文件开头，重新将文件中数据输入结构数组，从而输入新添加数据，以便后续操作。
	copy_information(fp, s);
	printf("\n------Next step------\n");
}