#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::stack;
using std::queue;


class MyStack
{
private:
	queue<int> q1;
	queue<int> q2;

public:
	/** Initialize your data structure here. */
	MyStack()
	{

	}

	/** Push element x onto stack. */
	void push(int x)
	{
		if (!q1.empty())
		{
			q1.push(x);
		}
		else
		{
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		if (!q1.empty())
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			int result = q1.front();
			q1.pop();
			return result;
		}
		else
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			int result = q2.front();
			q2.pop();
			return result;
		}
	}

	/** Get the top element. */
	int top()
	{
		int result = pop();
		push(result);
		return result;
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return q1.empty() && q2.empty();
	}
};

int main(int argc, char* argv[])
{
	MyStack s;
	s.push(1);
	s.push(2);
	cout << s.top() << endl;;
	cout << s.top() << endl;

	return 0;
}