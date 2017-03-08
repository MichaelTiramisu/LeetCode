//
//  main.cpp
//  P007_ReverseInteger
//
//  Created by Michael Liu on 2017/3/8.
//  Copyright © 2017年 Michael Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

class Solution {
public:
    // Record if the number is negative
    bool isNegative = false;
    
    int reverse(int number) {
        // Decompose all the numbers
        vector<int> numberBits = decomposeNumber(number);
        int result = composeNumber(numberBits);
        // Check to see if the number is overflow
        // Get all the bits of the result
        vector<int> resultBits = decomposeNumber(result);
        // Look up how many 0s at the end of the initial number
        // And add the number of 0s to the result bits array
        // This is needed for the judgement
        for (int i = 0; i < numberBits.size(); i++)
        {
            if (numberBits[i] != 0)
                break;
            // Add 0 to the result bits
            resultBits.push_back(0);
        }
        // reverse the result
        std::reverse(resultBits.begin(), resultBits.end());
        
        
        // Judge if they are same
        // Look at the length first
        if (numberBits.size() != resultBits.size())
            return 0;
        // Look at each bit
        for (int i = 0; i < numberBits.size(); i++)
            if (numberBits[i] != resultBits[i])
                return 0;
        // Pass all the judgement
        return result;
    }
    
    // Support function to decompose the each bit of an integer number to an array of digits
    vector<int> decomposeNumber(int number)
    {
        vector<int> result;
        // Judge if the nuber is gegative
        // we cannot just make it positive, because
        // INT_MAX = 2147483647
        // INT_MIN = -2147483648
        if (number < 0)
            isNegative = true;
        // Div by 10 each time, until it gets 0
        while (number != 0)
        {
            int currentBit = number % 10;
            result.push_back(abs(currentBit));
            number /= 10;
        }
        return result;
    }
    
    // Support function de compose an array of digits into an integer number
    int composeNumber(vector<int> digits)
    {
        int result = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            result *= 10;
            result += digits[i];
        }
        // Check for the negative sign mark
        if (isNegative)
            result = -result;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    int number = 2147483647;
    auto newNumber = solution.reverse(number);
    
    return 0;
}
