#include<stdio.h> 
#include<stdlib.h>
#include<iostream>
#include <algorithm>
using namespace std;
//������Ϣ
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

//����
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
//�����¶��������
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
//��ʾ��¼�������Ϣ
void print(node* head)
{
	system("cls");
	if (head->next == NULL)
	{
		cout << "��\n";
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
	cout << "��������          ʡ��            ����          �����¶�ͳ�����(��)        �¶��������" << endl;
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
//��ӳ�����Ϣ
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
		cout << "����������ƣ�ʡ�ݣ����¼������¶����(���¼���'.'����)��";
		cin >> p->data.name >> p->data.pro >> p->data.year;
		for (int i = 0;i < 7;i++)
		{
			cin >> p->data.T[i];
		}
		p->next = NULL;
		pre->next = p;
		pre = p;
		cout << "��ӳɹ����Ƿ������ӣ�(��1��0)��";
		cin >> flag;
	}
}
//ɾ��������Ϣ
void Delete(node* head)
{
	system("cls");
	int flag = 0;
	if (head->next == NULL)
	{
		cout << "������ӳ���!\n";
		return;
	}
	node* p = head->next;
	string m_name;
	cout << "��������Ҫɾ���ĳ��У�";
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
		cout << "δ�鵽�ó��У�����ʧ�ܣ�\n";
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
			cout << "ɾ���ɹ���";
			break;
		}
		p = p->next;
	}
}
//�޸ĳ�����Ϣ
void modify(node* head)
{
	system("cls");
	if (head->next == NULL)
	{
		cout << "������ӳ���!\n";
		return;
	}
	node* p = head->next;
	int flag = 0;
	cout << "������޸ĵĳ������ƣ�";
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
		cout << "δ�鵽�ó��У��޸�ʧ�ܣ�\n";
		return;
	}
	cout << "1   �޸ĳ�������" << endl;
	cout << "2   �޸ĳ���ʡ��" << endl;
	cout << "3   �޸ĳ�������" << endl;
	cout << "4   �޸ĳ���7���¶�" << endl;
	int n;
	cin >> n;
	while (n < 1 || n>4)
	{
		cout << "�����������������롾1-4����";
		cin >> n;
	}
	if (n == 1)
	{
		string name1;
		cout << "�������µ����ƣ�";
		cin >> name1;
		p->data.name = name1;
	}
	if (n == 2)
	{
		string name1;
		cout << "�������µ�ʡ�ݣ�";
		cin >> name1;
		p->data.pro = name1;
	}
	if (n == 3)
	{
		string name1;
		cout << "�������µ����£�";
		cin >> name1;
		p->data.year = name1;
	}
	if (n == 4)
	{
		int T1[7];
		cout << "�������µ�7���¶ȣ�";
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
//���ҳ�����Ϣ
void find(node* head)
{
	system("cls");
	if (head->next == NULL)
	{
		cout << "������ӳ���!\n";
		return;
	}
	node* p = head->next;
	string name1;
	int flag = 0;
	cout << "��������ҵĳ������ƣ�";
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
		cout << "δ�鵽�ó��У�����ʧ�ܣ�\n";
		return;
	}
	else
	{
		cout << "��������          ʡ��            ����          �����¶�ͳ�����(��)        �¶��������" << endl;
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
//���˵�����
void menu(node* head)
{
	while (1)
	{
		cout << "**************��ӭ����������Ϣ����ϵͳ***************" << endl;
		cout << "����Խ������²�����" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              1   ��ʾ�ļ��г�����Ϣ               |" << endl;
		cout << "|              2   ��ʾ��¼�������Ϣ               |" << endl;
		cout << "|              3   ���ӳ�����Ϣ                     |" << endl;
		cout << "|              4   ɾ��������Ϣ                     |" << endl;
		cout << "|              5   �޸ĳ�����Ϣ                     |" << endl;
		cout << "|              6   ���ҳ�����Ϣ                     |" << endl;
		cout << "|              7   �˳�                             | " << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "��ѡ��1-7����";
		int n;
		cin >> n;
		while (n < 1 || n>7)
		{
			cout << "�������������ѡ��1-7��";
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