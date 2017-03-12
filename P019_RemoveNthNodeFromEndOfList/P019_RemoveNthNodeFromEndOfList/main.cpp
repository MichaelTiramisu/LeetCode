#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// Convert all the numbers in the liked list to a vector
		vector<int> numberArray = listNodeToArray(head);
		// Reverse the vector
		reverseNumbers(numberArray);
		// Delete the n-th number in the reversed vector
		// The index of it should be n - 1
		numberArray.erase(numberArray.begin() + n - 1);
		// Reversr the vector again
		reverseNumbers(numberArray);
		// Convert the vector back to a liked list, then we get the result
		return arrayToListNode(numberArray);
	}

	// Supporting function to convert all the digits in a linked list to int vector
	vector<int> listNodeToArray(ListNode *node)
	{
		vector<int> result;
		// Loop through the linked list and put all the numbers in a int vector
		// Do NOT use (node->next != NULL)
		while (node != NULL)
		{
			result.push_back(node->val);
			node = node->next;
		}

		return result;
	}

	// Supporting function to reverse the numbers in the vector
	void reverseNumbers(vector<int> &numbers)
	{
		reverse(numbers.begin(), numbers.end());
	}

	// Supporting function to convert all the digits in the vector to a linked list
	ListNode* arrayToListNode(vector<int> &numbers)
	{
		// Chechk if the numbers count is greater than 1
		if (numbers.size() <= 0)
			return NULL;

		// preprocess the head node
		ListNode *head = new ListNode(numbers[0]);
		// Define a previous node for loop
		ListNode *previous = head;
		for (int i = 1; i < numbers.size(); i++)
		{
			ListNode *tempNode = new ListNode(numbers[i]);
			previous->next = tempNode;
			previous = previous->next;
		}
		return head;
	}
};

int main(int argc, char* argv[])
{
	// Define to lined list
	ListNode *head1 = &ListNode(1);
	head1->next = &ListNode(2);
	head1->next->next = &ListNode(3);
	head1->next->next->next = &ListNode(4);
	head1->next->next->next->next = &ListNode(5);

	// Calculate the result
	Solution sulution;
	ListNode *result = sulution.removeNthFromEnd(head1, 2);

	return 0;
}