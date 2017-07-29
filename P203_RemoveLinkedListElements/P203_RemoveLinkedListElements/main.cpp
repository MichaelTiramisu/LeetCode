#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution
//{
//public:
//	ListNode* removeElements(ListNode* head, int val)
//	{
//		ListNode* current = head;
//		ListNode* previous = NULL;
//		while (current != NULL)
//		{
//			if (current->val == val)
//			{
//				// �ж���������������, һֱ�ҵ����һ����ֵ��
//				ListNode* lastSameValueNode = current;
//				do
//				{
//					// ��סҪ�ͷ���Դ
//					ListNode* temp = current;
//					current = current->next;
//					//delete temp;
//				} while (current != NULL && current->val == val);
//				// �������������ָ��, ע���ڿ�ͷ�����
//				if (previous == NULL)
//				{
//					head = current;
//				}
//				else
//				{
//					previous->next = current;
//				}
//			}
//
//			if (current == NULL)
//			{
//				break;
//			}
//			else
//			{
//				previous = current;
//				current = current->next;
//			}
//		}
//
//		return head;
//	}
//};

class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode* current = head;
		ListNode* previous = NULL;

		while (current != NULL)
		{
			if (current->val == val)
			{
				ListNode* temp = current;
				current = current->next;
				if (previous != NULL)
				{
					previous->next = current;
				}
				else
				{
					head = current;
				}
				//delete temp;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}

		return head;
	}
};


int main(int argc, char* argv[])
{
	Solution solution;

	ListNode* head = &ListNode(1);
	head->next = &ListNode(2);
	head->next->next = &ListNode(6);
	head->next->next->next = &ListNode(3);
	head->next->next->next->next = &ListNode(4);
	head->next->next->next->next->next = &ListNode(5);
	head->next->next->next->next->next->next = &ListNode(6);

	int val = 6;
	head = solution.removeElements(head, 6);


	return 0;
}