#include<stdio.h>
#include"struct.h"
#include"copy_information.h"

void input_information(student s[])
{
	FILE *fp=fopen("C:\\student record.txt", "r+");//���ļ���ԭ�����ݲ���ա�
	student c;

	if (fp == NULL)
		printf("file open error!\n");

	printf("\n------Please input student information.------\n\n");//������Ҫ��ӵ�ѧ����Ϣ��
	printf("student name: ");
	scanf("%s", &c.name);
	printf("student number: ");
	scanf("%ld", &c.number);
	printf("student grade: ");
	scanf("%d %d %d %d", &c.math,&c.english,&c.programc,&c.PE);

	fseek(fp, 0, 2);//��λ���ļ�ĩβ�����ļ�׷�����ݡ�
	fprintf(fp, "%-8s%-10ld%-9d%-9d%-9d%-9d\n", c.name,c.number,c.math,c.english,c.programc,c.PE);
	rewind(fp);//��λ���ļ���ͷ�����½��ļ�����������ṹ���飬�Ӷ�������������ݣ��Ա����������
	copy_information(fp, s);
	printf("\n------Next step------\n");
}