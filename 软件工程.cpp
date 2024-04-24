#include<iostream>
#include<stdio.h>
#include<ctime>
#include<time.h>
#include<stdlib.h>
#include <exception>
#include <stack>
#include<fstream>
using namespace std;
#define CLOCKS_PER_SEC ((clock_t)1000)
clock_t start, end;
class Student
{
public:
	char name[100];
	unsigned int level;
	unsigned int size;
	double time;
	unsigned int number;
	int sign = 0;
	void display(int i, int t[]);
	void get1();
	void get2();
};
void Student::get1()
{
	cout << " ******** 欢迎使用学生数学运算自我软件! ******** " << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " 请输入学生姓名： " << endl;
	cin >> name;
	cout << " 请输入训练次数： " << endl;
	cin >> number;
}
void Student::get2()
{
	cout << " 请选择训练等级(分为 1、2、3）： " << endl;
	cin >> level;
	cout << " 请选择运算数字位数(不超过三位数）: " << endl;
	cin >> size;
}
void Student::display(int x, int t[])
{
	int num1, num2, num3;
	int num4;
	x = 0;
	int flag = 0;
	int time[10];
	if (level == 1)
	{
		clock_t start1 = clock();
		for (unsigned int i = 0; i < 20; i++)
		{
			if (size == 1)
			{
				num1 = rand() % 10;
				num2 = rand() % 10;//产生一位的随机数
			}
			if (size == 2)
			{
				num1 = 10 + rand() % 90;
				num2 = 10 + rand() % 90;//产生两位随机数
			}
			if (size == 3)
			{
				num1 = 100 + rand() % 900;
				num2 = 100 + rand() % 900;//产生三位随机数
			}
			int op = rand() % 2;
			switch (op)
			{
			case 0:printf("%d+%d=", num1, num2);
				scanf("%d", &num3);
				if (num1 + num2 == num3)
				{
					continue;
						flag = 0;
					sign = 0;
				}
				else
				{
					flag = 1;
					sign = 1;
					break;
				}
			case 1:printf("%d-%d=", num1, num2);
				scanf("%d", &num3);
				if (num1 - num2 == num3)
				{
					continue;
					flag = 0;
				}
				else
				{
					flag = 1;
					sign = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 0)
		{
			clock_t endl = clock();
			cout << "本题用时(s):" << (double)(endl - start1) / CLOCKS_PER_SEC << endl;
			t[x] = (double)(endl - start1) / CLOCKS_PER_SEC;
			x++;
		}
		if (flag == 1)
		{
			cout << "训练失败" << endl;
		}
	}
	if (level == 2)
	{
		clock_t start1 = clock();
			for (unsigned int i = 0; i < 20; i++)
			{
				if (size == 1)
				{
					num1 = rand() % 10;
					num2 = rand() % 10;//产生一位的随机数
				}
				if (size == 2)
				{
					num1 = 10 + rand() % 90;
					num2 = 10 + rand() % 90;//产生两位随机数
				}
				if (size == 3)
				{
					num1 = 100 + rand() % 900;
					num2 = 100 + rand() % 900;//产生三位随机数
				}
				int op = rand() % 2;
				switch (op)
				{
				case 0:printf("%d*%d=", num1, num2);
					scanf("%d", &num3);
					if (num1 * num2 == num3)
					{
						continue;
						flag = 0;
					}
					else
					{
						flag = 1;
						sign = 1;
						break;
					}
				case 1:printf("%d/%d=", num1, num2);
					if (num2 != 0)
					{
						scanf("%d", &num4);
						printf("余数为：");
						scanf("%d", &num3);
						if (num1 / num2 == num4 && num1 % num2 == num3)
						{
							continue;
							flag = 0;
						}
						else
						{
							flag = 1;
							sign = 1;
							break;
						}
					}
					else
					{
						cout << endl;
						cout << "本题错误" << endl;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
		if (flag == 0)
		{
			clock_t endl = clock();
			cout << "本题用时(s):" << (double)(endl - start1) / CLOCKS_PER_SEC << endl;
			t[x] = (double)(endl - start1) / CLOCKS_PER_SEC;
			x++;
		}
		if (flag == 1)
		{
			cout << "训练失败" << endl;
		}
	}
	if (level == 3)
	{
		clock_t start1 = clock();
		for (unsigned int i = 0; i < 20; i++)
		{
			if (size == 1)
			{
				num1 = rand() % 10;
				num2 = rand() % 10;//产生一位的随机数
			}
			if (size == 2)
			{
					num1 = 10 + rand() % 90;
				num2 = 10 + rand() % 90;//产生两位随机数
			}
			if (size == 3)
			{
				num1 = 100 + rand() % 900;
				num2 = 100 + rand() % 900;//产生三位随机数
			}
			int op = rand() % 4;
			switch (op)
			{
			case 0:printf("%d+%d=", num1, num2);
				scanf("%d", &num3);
				if (num1 + num2 == num3)
				{
					continue;
					flag = 0;
				}
				else
				{
					flag = 1;
					sign = 1;
					break;
				}
			case 1:printf("%d-%d=", num1, num2);
				scanf("%d", &num3);
				if (num1 - num2 == num3)
				{
					continue;
					flag = 0;
				}
				else
				{
					flag = 1;
					break;
				}
			case 2:printf("%d*%d=", num1, num2);
				scanf("%d", &num3);
				if (num1 * num2 == num3)
				{
					continue;
					flag = 0;
				}
				else
				{
					flag = 1;
					sign = 1;
					break;
				}
			case 3:printf("%d/%d=", num1, num2);
				if (num2 != 0)
				{
					scanf("%d", &num4);
					printf("余数为：");
					scanf("%d", &num3);
					if (num1 / num2 == num4 && num1 % num2 == num3)
					{
						continue;
						flag = 0;
					}
					else
					{
						flag = 1;
						sign = 1;
						break;
					}
				}
				else
				{
					cout << endl;
					cout << "本题错误" << endl;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}if (flag == 0)
		{
			clock_t endl = clock();
			cout << "本题用时(s):" << (double)(endl - start1) / CLOCKS_PER_SEC << endl;
			t[x] = (double)(endl - start1) / CLOCKS_PER_SEC;
			x++;
		}
		if (flag == 1)
		{
				cout << "训练失败" << endl;
		}
	}
}
stack<int> asdSort(stack<int> s)
{
	stack<int> s1;
	while (!s.empty())
	{
		int t = s.top();
		s.pop();
		while (!s1.empty() && t < s1.top())
		{
			s.push(s1.top());
			s1.pop();
		}
		s1.push(t);
	}
	return s1;
}
void main()
{
	int x = 0;
	int i = 0;
	int t[10];
	int a[100] = { 0 };
	stack<int> s;
	srand((unsigned)time(NULL));
	Student p;
	p.get1();
	for (int i = 0; i < p.number; i++)
	{
		p.get2();
		if (p.level < 4 && p.size < 4)
		{
			start = clock();
			p.display(x, t);
			cout << endl;
			s.push(t[x]);
		}
		else
		{
			cout << "参数错误，请重新输入" << endl;
		}
	}
	if (p.sign == 0)
	{
		stack<int> s2;
		s2 = asdSort(s);
		cout << "排序结果为(从大到小）：" << endl;
		while (!s2.empty())
		{
			cout << s2.top() << endl;
			a[i] = s2.top();
			i++;
			s2.pop();
		}
		FILE* fp;
		if ((fp = fopen("C://Users//Administrator//Desktop//学生信息.txt", "w")) == NULL)
		{
			printf("Can not open the file,press any key exit!");
			exit(0);
		}
		i = 0;
		fprintf(fp, "%s\n", p.name);
		while (a[i] != 0)
		{
			fprintf(fp, "%d\n", a[i]);
			i++;
		}
		fclose(fp);
		cout << "您已经将考生信息成功保存到了 学生信息.txt 文件中！\n ";
	}
	system("pause");
}//1.1 问题描述
//对小学生进行数学运算的训练，训练分成三个等级，初级为加减运算，中级
//为乘除运算，高级为加减乘除运算，每次训练随机生成 20 道题目，答错任意一题
//则训练失败，若成功答对所有题目则记录训练时间，最后对训练时间进行排序。
//1.1.1 问题背景
//本次题目主要是为了增强小学生对于数学的运算能力而发明的一个系统。
//1.1.2 主要任务
//本题需要对数学运算分为三个等级，初级为加减运算，中级为乘除运算，高
//级为加减乘除运算，每次需要随机生成 20 道题目，答错任意一题则训练失败，若
//成功答对所有题目则记录训练时间，最后对训练时间进行排序。
