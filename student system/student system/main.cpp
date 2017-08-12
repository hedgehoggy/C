#include<stdio.h>
#include"struct.h"
#include"copy_information.h"
#include"input_information.h"
#include"edit_information.h"
#include"search_information.h"
#include"delete_information.h"
#include"count_information.h"

int main()
{
	FILE *fp;
	student s[100] = {0};

	fp = fopen("C:\\student record.txt", "r");//���ļ������ļ�����Ϣ�����������У����رա�
	copy_information(fp, s);
	fclose(fp);

	printf("------main menu------\n");//�ڿ���̨������ʾ���˵���

begin: 
	printf("1->input information\n");
	printf("2->edit information\n");
	printf("3->search information\n");
	printf("4->delete information\n");
	printf("5->count information\n");
	printf("0->exit\n");
	printf("\n------Please input a number to execute the command.------\n");

	int c;
	scanf("%d", &c);//����ִ��ѡ�
	switch(c)//��֧����ʼִ�г���
	{
	case 1:
		input_information(s);//�����µ�ѧ����Ϣ��
		goto begin;//��������󷵻����˵�ѭ������ͬ��
		break;
	case 2:
		edit_information(s);//�༭����ѧ����Ϣ��
		goto begin;
		break;
	case 3:
		search_information(s);//����ѧ����Ϣ��
		goto begin;
		break;
	case 4:
		delete_information(s);//ɾ��ѧ����Ϣ��
		goto begin;
		break;
	case 5:
		count_information(s);//����ƽ���ּ��ܷ֡�
		goto begin;
		break;
	case 0:
		break;//�˳�����
	default:
		printf("You input the wrong command.\n");
		break;
	}
	return 0;
}