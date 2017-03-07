//
//  main.cpp
//  P001_TwoSum
//
//  Created by Siyang Liu on 17/2/28.
//  Copyright © 2017年 Siyang Liu. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;


class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
        
        return result;
    }
};



int main(int argc, const char * argv[])
{
    int numberCount = 0;
    vector<int> numbers;
    cin >> numberCount;
    int target = 0;
    cin >> target;
    for (int i = 0; i < numberCount; i++)
    {
        int temp = 0;
        cin >> temp;
        numbers.push_back(temp);
    }
    if (numbers.size() >= 2)
    {
        Solution solution;
        vector<int> result = solution.twoSum(numbers, target);
        cout << result[0] << " " << result[1];
    }
    
    return 0;
}
