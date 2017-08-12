#include<stdio.h>
#include"struct.h"

void copy_information(FILE *fp,student s[])
{
	fseek(fp, 47, 0);//在打开文件中因有表头设计，需跳过表头，重新定位，将学生信息输入至数组中。
	int i = 0;
	while (!feof(fp))//循环至文件末尾结束，将七个变量逐一赋值到结构数组中。
	{
		fscanf(fp, "%s %ld %d %d %d %d", s[i].name, &s[i].number, &s[i].math, &s[i].english, &s[i].programc, &s[i].PE);
		i++;
	}
}