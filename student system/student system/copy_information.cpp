#include<stdio.h>
#include"struct.h"

void copy_information(FILE *fp,student s[])
{
	fseek(fp, 47, 0);//�ڴ��ļ������б�ͷ��ƣ���������ͷ�����¶�λ����ѧ����Ϣ�����������С�
	int i = 0;
	while (!feof(fp))//ѭ�����ļ�ĩβ���������߸�������һ��ֵ���ṹ�����С�
	{
		fscanf(fp, "%s %ld %d %d %d %d", s[i].name, &s[i].number, &s[i].math, &s[i].english, &s[i].programc, &s[i].PE);
		i++;
	}
}