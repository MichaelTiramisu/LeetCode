#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::reverse;

/**
* Definition for singly-linked list.
*/
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode *node1, ListNode *node2) 
	{
		// Get the array representation of the liked list
		vector<int> numbers1 = listNodeToArray(node1);
		vector<int> numbers2 = listNodeToArray(node2);
		// Calculate the result for number vector
		vector<int> result = addTwoNumberArray(numbers1, numbers2);
		//// Reverst the result
		//reverseNumbers(result);
		// Convert the vector to linked list
		return arrayToListNode(result);
	}

	vector<int> addTwoNumberArray(vector<int> &numbers1, vector<int> &numbers2)
	{
		vector<int> result;
		// Judge the length of the array, and make the first one that the length is greater
		vector<int> longerNumber;
		vector<int> shorterNumber;
		if (numbers1.size() >= numbers2.size())
		{
			longerNumber = numbers1;
			shorterNumber = numbers2;
		}
		else
		{
			longerNumber = numbers2;
			shorterNumber = numbers1;
		}
		// Get the string length
		int longerNumberLength = longerNumber.size();
		int shorterNumberLength = shorterNumber.size();
		// Add the bits with index from 0 to shorterNumberLength - 1
		bool shouldCarryBit = false;
		for (int i = 0; i < shorterNumberLength; i++)
		{
			result.push_back(longerNumber[i] + shorterNumber[i]);
			// Loop up if we need add 1 from last bit's carry
			if (shouldCarryBit)
			{
				shouldCarryBit = false;
				result[i] += 1;
			}
			// Loop uo if we need to carry bit
			if (result[i] >= 10)
			{ 
				shouldCarryBit = true;
				result[i] -= 10;
			}
		}
		// Add the bit with index from shorterNumberLength to longerNumberLength - 1
		for (int i = shorterNumberLength; i < longerNumberLength; i++)
		{
			result.push_back(longerNumber[i]);
			// Loop up if we need add 1 from last bit's carry
			if (shouldCarryBit)
			{
				shouldCarryBit = false;
				result[i] += 1;
			}
			// Loop uo if we need to carry bit
			if (result[i] >= 10)
			{
				shouldCarryBit = true;
				result[i] -= 10;
			}
		}
		// check for the last bit
		if (shouldCarryBit)
		{
			shouldCarryBit = false;
			result.push_back(1);
		}
		return result;
	}

	// Supporting function to reverse the numbers in the vector
	void reverseNumbers(vector<int> &numbers)
	{
		reverse(numbers.begin(), numbers.end());
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
	ListNode *head1 = &ListNode(2);
	head1->next = &ListNode(4);
	head1->next->next = &ListNode(3);

	ListNode *head2 = &ListNode(5);
	head2->next = &ListNode(6);
	head2->next->next = &ListNode(4);
	//head2->next->next->next = &ListNode(2);

	// Calculate the result
	Solution sulution;
	ListNode *result = sulution.addTwoNumbers(head1, head2);
	return 0;
}