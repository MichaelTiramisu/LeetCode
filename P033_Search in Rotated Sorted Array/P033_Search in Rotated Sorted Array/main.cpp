#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		int length = nums.size();
		// �ж������Ƿ�Ϊ��
		if (length == 0)
		{
			return -1;
		}
		int low = 0;
		int high = length - 1;
		int minimumIndex = -1;
		while (low < high)
		{
			if (nums[low] < nums[high])
			{
				minimumIndex = low;
				break;
			}
			int mid = (low + high) / 2;
			if (nums[mid] >= nums[low])
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
		// �ж���Сֵ��index�Ƿ�ı��
		if (minimumIndex == -1)
		{
			minimumIndex = low;
		}
		int maximumIndex = minimumIndex == 0 ? length - 1 : minimumIndex - 1;
		int minimumValue = nums[minimumIndex];
		int maximumValue = nums[maximumIndex];

		if (target < minimumValue || target > maximumValue)
		{
			return -1;
		}

		if (target >= nums[0])
		{
			low = 0;
			high = maximumIndex;
		}
		else
		{
			low = minimumIndex;
			high = length - 1;
		}

		// ���ж��ֲ���
		while (low <= high) {
			int mid = (low + high) / 2;
			if (target == nums[mid])
			{
				return mid;
			}
			if (target < nums[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		return -1;
	}
};


int main(int argc, char* argv[])
{
	Solution solution;
	vector<int> numbers = { 1, 3 };
	int target = 3;
	cout << solution.search(numbers, target) << endl;
	return 0;
}