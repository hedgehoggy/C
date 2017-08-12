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

	fp = fopen("C:\\student record.txt", "r");//打开文件，将文件中信息输入至数组中，并关闭。
	copy_information(fp, s);
	fclose(fp);

	printf("------main menu------\n");//在控制台界面显示主菜单。

begin: 
	printf("1->input information\n");
	printf("2->edit information\n");
	printf("3->search information\n");
	printf("4->delete information\n");
	printf("5->count information\n");
	printf("0->exit\n");
	printf("\n------Please input a number to execute the command.------\n");

	int c;
	scanf("%d", &c);//输入执行选项。
	switch(c)//分支，开始执行程序。
	{
	case 1:
		input_information(s);//输入新的学生信息。
		goto begin;//结束任务后返回主菜单循环，下同。
		break;
	case 2:
		edit_information(s);//编辑错误学生信息。
		goto begin;
		break;
	case 3:
		search_information(s);//查找学生信息。
		goto begin;
		break;
	case 4:
		delete_information(s);//删除学生信息。
		goto begin;
		break;
	case 5:
		count_information(s);//计算平均分及总分。
		goto begin;
		break;
	case 0:
		break;//退出程序。
	default:
		printf("You input the wrong command.\n");
		break;
	}
	return 0;
}