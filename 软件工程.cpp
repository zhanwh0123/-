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
	cout << " ******** ��ӭʹ��ѧ����ѧ�����������! ******** " << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " * *" << endl;
	cout << " ������ѧ�������� " << endl;
	cin >> name;
	cout << " ������ѵ�������� " << endl;
	cin >> number;
}
void Student::get2()
{
	cout << " ��ѡ��ѵ���ȼ�(��Ϊ 1��2��3���� " << endl;
	cin >> level;
	cout << " ��ѡ����������λ��(��������λ����: " << endl;
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
				num2 = rand() % 10;//����һλ�������
			}
			if (size == 2)
			{
				num1 = 10 + rand() % 90;
				num2 = 10 + rand() % 90;//������λ�����
			}
			if (size == 3)
			{
				num1 = 100 + rand() % 900;
				num2 = 100 + rand() % 900;//������λ�����
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
			cout << "������ʱ(s):" << (double)(endl - start1) / CLOCKS_PER_SEC << endl;
			t[x] = (double)(endl - start1) / CLOCKS_PER_SEC;
			x++;
		}
		if (flag == 1)
		{
			cout << "ѵ��ʧ��" << endl;
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
					num2 = rand() % 10;//����һλ�������
				}
				if (size == 2)
				{
					num1 = 10 + rand() % 90;
					num2 = 10 + rand() % 90;//������λ�����
				}
				if (size == 3)
				{
					num1 = 100 + rand() % 900;
					num2 = 100 + rand() % 900;//������λ�����
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
						printf("����Ϊ��");
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
						cout << "�������" << endl;
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
			cout << "������ʱ(s):" << (double)(endl - start1) / CLOCKS_PER_SEC << endl;
			t[x] = (double)(endl - start1) / CLOCKS_PER_SEC;
			x++;
		}
		if (flag == 1)
		{
			cout << "ѵ��ʧ��" << endl;
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
				num2 = rand() % 10;//����һλ�������
			}
			if (size == 2)
			{
					num1 = 10 + rand() % 90;
				num2 = 10 + rand() % 90;//������λ�����
			}
			if (size == 3)
			{
				num1 = 100 + rand() % 900;
				num2 = 100 + rand() % 900;//������λ�����
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
					printf("����Ϊ��");
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
					cout << "�������" << endl;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}if (flag == 0)
		{
			clock_t endl = clock();
			cout << "������ʱ(s):" << (double)(endl - start1) / CLOCKS_PER_SEC << endl;
			t[x] = (double)(endl - start1) / CLOCKS_PER_SEC;
			x++;
		}
		if (flag == 1)
		{
				cout << "ѵ��ʧ��" << endl;
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
			cout << "������������������" << endl;
		}
	}
	if (p.sign == 0)
	{
		stack<int> s2;
		s2 = asdSort(s);
		cout << "������Ϊ(�Ӵ�С����" << endl;
		while (!s2.empty())
		{
			cout << s2.top() << endl;
			a[i] = s2.top();
			i++;
			s2.pop();
		}
		FILE* fp;
		if ((fp = fopen("C://Users//Administrator//Desktop//ѧ����Ϣ.txt", "w")) == NULL)
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
		cout << "���Ѿ���������Ϣ�ɹ����浽�� ѧ����Ϣ.txt �ļ��У�\n ";
	}
	system("pause");
}//1.1 ��������
//��Сѧ��������ѧ�����ѵ����ѵ���ֳ������ȼ�������Ϊ�Ӽ����㣬�м�
//Ϊ�˳����㣬�߼�Ϊ�Ӽ��˳����㣬ÿ��ѵ��������� 20 ����Ŀ���������һ��
//��ѵ��ʧ�ܣ����ɹ����������Ŀ���¼ѵ��ʱ�䣬����ѵ��ʱ���������
//1.1.1 ���ⱳ��
//������Ŀ��Ҫ��Ϊ����ǿСѧ��������ѧ������������������һ��ϵͳ��
//1.1.2 ��Ҫ����
//������Ҫ����ѧ�����Ϊ�����ȼ�������Ϊ�Ӽ����㣬�м�Ϊ�˳����㣬��
//��Ϊ�Ӽ��˳����㣬ÿ����Ҫ������� 20 ����Ŀ���������һ����ѵ��ʧ�ܣ���
//�ɹ����������Ŀ���¼ѵ��ʱ�䣬����ѵ��ʱ���������
