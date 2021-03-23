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

		if (temp == '{' || temp == '[' || temp == '(' || temp == '<')//如果是左括号，把它放到栈里
		{
			left.push(temp);
		}
		else if(temp == '}' || temp == ']' || temp == ')' || temp == '>')//否则的话
		{
			if (left.empty())
			{
				return false;
			}
			switch (temp) //如果读取到右括号，检查栈最前面的括号和他是否匹配
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
				default://如果是其他字符，略过
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