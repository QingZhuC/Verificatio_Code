#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

char RAND()
{
	char a = 0;
	a = rand() % 3;
		//a = rand() % 75 + 48;
	if (a == 0)
	{
		a = rand() % 10 + 48;
	}
	else if (a == 1)
	{
		a = rand() % 26 + 65;
	}
	else
	{
		a = rand() % 26 + 97;
	}
	
	return a;
}

void menu()
{
	printf("################################\n");
	printf("##         1.生成验证码       ##\n");
	printf("##            0.退出          ##\n");
	printf("################################\n");
}

int main()
{
	char word[] = "aaaa";
	int in = 0;
	srand((unsigned int)time(NULL));

	while (1)
	{
		in = 2;//若没有这个，第一次输入字母时数据不能被scanf接收从而按初始值0运行
		system("cls");
		menu();
		scanf_s("%d", &in);
		if (getchar() != '\n')
			in = 2;		//防止   1xxx   情况出现

		switch (in)
		{
		case 1:
			word[0] = RAND();
			word[1] = RAND();
			word[2] = RAND();
			word[3] = RAND();
			printf("%s\n", word);
			system("pause");
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("输入有误\n");
			while (getchar() != '\n');//清空缓存区
			system("pause");
		}
	}
	return 0;
}
