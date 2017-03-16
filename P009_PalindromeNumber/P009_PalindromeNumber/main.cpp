#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Solution
{
public:
	bool isPalindrome(int number)
	{
		// It could be some problem, if the number is negative, just return false
		if (number < 0)
			return false;
		// Copy the number in another variable
		int temp = number;
		// Decompose the temp number, and compose it
		int result = 0;
		while (temp != 0)
		{
			// Get the last digit
			int lastDigit = temp % 10;
			result = result * 10 + lastDigit;
			// Get the last digit out of temp number
			temp /= 10;
		}
		// Check to see if the two numbers are same
		// If they are same, then the number is PALINDROME
		if (result == number)
			return true;
		else
			return false;
	}
};

int main(int argc, char* argv[])
{
	Solution solution;
	int number = 10;
	cout << solution.isPalindrome(number);

	return 0;
}