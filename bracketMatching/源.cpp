#include <iostream>
#include <stack>
#pragma warning(disable : 4996)

using namespace std;

bool matching()
{
	stack<char> left;
	char temp;
	while (cin>>temp)
	{
		if (temp == '`')
		{
			break;
		}

		if (temp == '{' || temp == '[' || temp == '(' || temp == '<')//����������ţ������ŵ�ջ��
		{
			left.push(temp);
		}
		else if(temp == '}' || temp == ']' || temp == ')' || temp == '>')//����Ļ�
		{
			if (left.empty())
			{
				return false;
			}
			switch (temp) //�����ȡ�������ţ����ջ��ǰ������ź����Ƿ�ƥ��
			{
				case '}':
					if ((left.top()) == '{')
						{
						left.pop();
						continue;
						}
					break;
				case ']':
					if ((left.top()) == '[')
					{
						left.pop();
						continue;
					}
					break;
				case ')':
					if ((left.top()) == '(')
					{
						left.pop();
						continue;
					}
					break;
				case '>':
					if ((left.top()) == '<')
					{
						left.pop();
						continue;
					}
					break;
				default://����������ַ����Թ�
					break;
			}
		}

	}
	if (left.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cout << matching();
}