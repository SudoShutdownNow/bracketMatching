#include <iostream>
#include <stack>
#pragma warning(disable : 4996)

using namespace std;

bool matching()
{
	stack<char> left;
	char temp;
	while (temp = getchar())
	{
		if (temp == '`')
		{
			break;
		}

		if (temp == '{' || temp == '[' || temp == '(')//如果是左大中小括号
		{
			left.push(temp);
		}
		else
		{
			switch (temp) 
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
				default:
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