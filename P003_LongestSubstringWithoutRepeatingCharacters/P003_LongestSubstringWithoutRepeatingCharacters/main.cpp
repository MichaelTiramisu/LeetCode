#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

#define TOTAL_LETTER_COUNT 128
// 改用二分之后
class Solution
{
public:
	int lengthOfLongestSubstring(string str)
	{
		int length = str.length();

		int low = 0;
		int high = length;
		int windowLength = (low + high) >> 1;
		while (low < high)
		{
			if (noRepeatingCharacters(str, windowLength))
			{
				low = windowLength + 1;
			}
			else
			{
				high = windowLength - 1;
			}
			windowLength = (low + high) >> 1;
		}

		if (noRepeatingCharacters(str, windowLength))
		{
			return windowLength;
		}
		else 
		{
			return windowLength - 1;
		}
	}

private:
	bool noRepeatingCharacters(const string& str, int windowLength)
	{
		int length = str.length();
		int nonZeroOrOneCount = 0;
		int letterCount[TOTAL_LETTER_COUNT];

		nonZeroOrOneCount = calculateLetterCount(str, letterCount, windowLength);
		// 第一个窗口
		if (noRepeatingCharacters(letterCount))
		{
			return true;
		}
		// 滑动窗口
		for (int i = windowLength; i < length; i++)
		{
			int ch = str[i - windowLength];
			letterCount[ch] -= 1;
			if (letterCount[ch] == -1)
			{
				nonZeroOrOneCount += 1;
			}
			if (letterCount[ch] == 1)
			{
				nonZeroOrOneCount -= 1;
			}

			ch = str[i];
			letterCount[ch] += 1;
			if (letterCount[ch] == 2)
			{
				nonZeroOrOneCount += 1;
			}
			if (letterCount[ch] == 0)
			{
				nonZeroOrOneCount -= 1;
			}

			if (nonZeroOrOneCount == 0)
			{
				return true;
			}
		}

		return false;
	}

	int calculateLetterCount(const string& str, int letterCount[], int windowLength)
	{
		int nonZeroOrOneCount = 0;
		for (int i = 0; i < TOTAL_LETTER_COUNT; i++)
		{
			letterCount[i] = 0;
		}
		for (int i = 0; i < windowLength; i++)
		{
			int ch = str[i];
			if (letterCount[ch] == 1)
			{
				nonZeroOrOneCount += 1;
			}
			letterCount[ch] += 1;
		}
		return nonZeroOrOneCount;
	}

	bool noRepeatingCharacters(int letterCount[])
	{
		for (int i = 0; i < TOTAL_LETTER_COUNT; i++)
		{
			if (letterCount[i] != 0 && letterCount[i] != 1)
				return false;
		}
		return true;
	}
};

int main(int argc, char* argv[])
{
	Solution solution;
	string str = "abcabcbb";
	cout << solution.lengthOfLongestSubstring(str) << endl;
}