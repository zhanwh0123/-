#include<stdio.h> 
#include<stdlib.h>
#include<iostream>
#include <algorithm>
using namespace std;
//城市信息
struct city
{
	string name;
	string pro;
	string year;
	int T[7];
	int temup[7];
};
struct node
{
	city data;
	struct node* next;
};
bool cmp(city& c1, city& c2)
{
	return c1.name < c2.name;
}

//排序
void sort_(node* head)
{
	int cnt = 0, i = 0;
	node* p = head->next;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	city* arr = new city[cnt];
	p = head->next;
	while (p)
	{
		arr[i++] = p->data;
		p = p->next;
	}
	sort(arr, arr + cnt, cmp);
	p = head->next;
	i = 0;
	while (p)
	{
		p->data = arr[i++];
		p = p->next;
	}
}
//计算温度升高情况
void count(int temup[], int T[])
{
	for (int i = 0;i < 6;i++)
	{
		int flag = 0;
		for (int j = i + 1;j < 7;j++)
		{
			if (T[i] < T[j])
			{
				flag = j;
				break;
			}
		}
		if (flag == 0)
			temup[i] = 0;
		else
			temup[i] = flag - i;
	}
	temup[6] = 0;
}
void read()
{
	system("cls");
	FILE* fp = fopen("C:\\Users\\DELL\\Desktop\\text.txt.txt", "r");
	char str[200];
	while (fgets(str, 200, fp))
	{
		printf("%s", str);
	}
	fclose(fp);
}
//显示已录入城市信息
void print(node* head)
{
	system("cls");
	if (head->next == NULL)
	{
		cout << "无\n";
		return;
	}
	node* pre = head->next;
	node* p = pre;
	while (pre)
	{
		count(pre->data.temup, pre->data.T);
		pre = pre->next;
	}
	sort_(head);
	cout << "城市名称          省份            年月          七日温度统计情况(℃)        温度升高情况" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	while (p)
	{
		cout << p->data.name << "          " << p->data.pro << "        " << p->data.year << "          ";
		for (int i = 0;i < 7;i++)
		{
			cout << p->data.T[i] << " ";
		}
		cout << "           ";
		for (int i = 0;i < 7;i++)
		{
			cout << p->data.temup[i] << " ";
		}
		p = p->next;
		cout << endl;
	}
}
//添加城市信息
void create(node* head)
{
	system("cls");
	int flag = 1;
	node* pre = head;
	while (pre->next)
	{
		pre = pre->next;
	}
	while (flag)
	{
		node* p = new node;
		cout << "输入城市名称，省份，年月及七日温度情况(年月间用'.'隔开)：";
		cin >> p->data.name >> p->data.pro >> p->data.year;
		for (int i = 0;i < 7;i++)
		{
			cin >> p->data.T[i];
		}
		p->next = NULL;
		pre->next = p;
		pre = p;
		cout << "添加成功！是否继续添加？(是1否0)：";
		cin >> flag;
	}
}
//删除城市信息
void Delete(node* head)
{
	system("cls");
	int flag = 0;
	if (head->next == NULL)
	{
		cout << "请先添加城市!\n";
		return;
	}
	node* p = head->next;
	string m_name;
	cout << "请输入想要删除的城市：";
	cin >> m_name;
	while (p)
	{
		if (p->data.name == m_name)
		{
			flag++;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		cout << "未查到该城市，查找失败！\n";
		return;
	}
	p = head;
	while (p->next)
	{
		node* q = p->next;
		q->next = NULL;
		if (q->data.name == m_name)
		{
			p->next = q->next;
			delete q;
			cout << "删除成功！";
			break;
		}
		p = p->next;
	}
}
//修改城市信息
void modify(node* head)
{
	system("cls");
	if (head->next == NULL)
	{
		cout << "请先添加城市!\n";
		return;
	}
	node* p = head->next;
	int flag = 0;
	cout << "输入待修改的城市名称：";
	string m_name;
	cin >> m_name;
	while (p)
	{
		if (p->data.name == m_name)
		{
			flag++;
			break;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		cout << "未查到该城市，修改失败！\n";
		return;
	}
	cout << "1   修改城市名称" << endl;
	cout << "2   修改城市省份" << endl;
	cout << "3   修改城市年月" << endl;
	cout << "4   修改城市7日温度" << endl;
	int n;
	cin >> n;
	while (n < 1 || n>4)
	{
		cout << "输入有误，请重新输入【1-4】：";
		cin >> n;
	}
	if (n == 1)
	{
		string name1;
		cout << "请输入新的名称：";
		cin >> name1;
		p->data.name = name1;
	}
	if (n == 2)
	{
		string name1;
		cout << "请输入新的省份：";
		cin >> name1;
		p->data.pro = name1;
	}
	if (n == 3)
	{
		string name1;
		cout << "请输入新的年月：";
		cin >> name1;
		p->data.year = name1;
	}
	if (n == 4)
	{
		int T1[7];
		cout << "请输入新的7日温度：";
		for (int i = 0;i < 7;i++)
		{
			cin >> T1[i];
		}
		for (int i = 0;i < 7;i++)
		{
			p->data.T[i] = T1[i];
		}
		count(p->data.temup, p->data.T);
	}
}
//查找城市信息
void find(node* head)
{
	system("cls");
	if (head->next == NULL)
	{
		cout << "请先添加城市!\n";
		return;
	}
	node* p = head->next;
	string name1;
	int flag = 0;
	cout << "输入待查找的城市名称：";
	cin >> name1;
	while (p)
	{
		if (p->data.name == name1)
		{
			flag++;
		}
		p = p->next;
	}
	p = head->next;
	if (flag == 0)
	{
		cout << "未查到该城市，查找失败！\n";
		return;
	}
	else
	{
		cout << "城市名称          省份            年月          七日温度统计情况(℃)        温度升高情况" << endl;
		cout << "-------------------------------------------------------------------------------------------" << endl;
		while (p)
		{
			if (p->data.name == name1)
			{
				cout << p->data.name << "          " << p->data.pro << "        " << p->data.year << "        ";
				for (int i = 0;i < 7;i++)
				{
					cout << p->data.T[i] << " ";
				}
				cout << "        ";
				for (int i = 0;i < 7;i++)
				{
					cout << p->data.temup[i] << " ";
				}
			}
			p = p->next;
			cout << endl;
		}
	}
}
//主菜单函数
void menu(node* head)
{
	while (1)
	{
		cout << "**************欢迎来到城市信息管理系统***************" << endl;
		cout << "你可以进行以下操作：" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              1   显示文件中城市信息               |" << endl;
		cout << "|              2   显示已录入城市信息               |" << endl;
		cout << "|              3   增加城市信息                     |" << endl;
		cout << "|              4   删除城市信息                     |" << endl;
		cout << "|              5   修改城市信息                     |" << endl;
		cout << "|              6   查找城市信息                     |" << endl;
		cout << "|              7   退出                             | " << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "请选择【1-7】：";
		int n;
		cin >> n;
		while (n < 1 || n>7)
		{
			cout << "输入错误，请重新选择【1-7】";
			cin >> n;
		}
		switch (n)
		{
		case 1:
		{
			read();
			break;
		}
		case 2:
		{
			print(head);
			break;
		}
		case 3:
		{
			create(head);
			break;
		}
		case 4:
		{
			Delete(head);
			break;
		}
		case 5:
		{
			modify(head);
			break;
		}
		case 6:
		{
			find(head);
			break;
		}
		case 7:
		{
			exit(0);
		}
		}
	}
}
int main()
{
	node* head = new node;
	head->next = NULL;
	menu(head);
	return 0;
}