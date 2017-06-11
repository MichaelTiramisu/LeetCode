//
//  main.cpp
//  P005_LongestPalindromicSubstring
//
//  Created by Siyang Liu on 17/5/31.
//  Copyright © 2017年 Siyang Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define MIN(x, y) (x < y) ? x : y

class Solution
{
public:
    string longestPalindrome(string s)
    {
        return centerExpandFindLongestPalindrome(s);
    }
    
    // Use the violent search to find the longest palindrome substring
    string violentFindLongestPalindrome(const string &str)
    {
        // The start of the Longest Palindrome
        size_t length = str.size();
        size_t maxLenth = 0;
        string result;
        // Look at each substring
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                string subString = str.substr(i, j - i + 1);
                if (isPalindromic(subString))
                {
                    // Compare the length to current length
                    if (subString.length() > maxLenth)
                    {
                        result = subString;
                        maxLenth = subString.length();
                    }
                }
            }
        }
        
        return result;
    }
    
    // Use dynamic programming to find longest palindrome substring
    string dpFindLongestPalindrome(const string &str)
    {
        const size_t length = str.length();
        size_t maxLength = 0;
        int start = 0;
        // Array to store if i..j is palindrome
        vector<vector<bool>> isPalindrome;
        for (int i = 0; i < length; i++)
        {
            vector<bool> temp(length);
            isPalindrome.push_back(temp);
        }
        
        // Initialilze the string with length 1 and 2
        for (int i = 0; i < length; i++)
        {
            isPalindrome[i][i] = true;
            if (i < length - 1 && str[i] == str[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        // Loop each length of the substring, from 3 to length
        for (int len = 3; len <= length; len++)
        {
            for (int i = 0; i <= length - len; i++)
            {
                // Substring start index is i
                // Substring end index is start + len - 1;
                int endIndex = i + len - 1;
                if (isPalindrome[i + 1][endIndex - 1] && str[i] == str[endIndex])
                {
                    isPalindrome[i][endIndex] = true;
                    maxLength = len;
                    start = i;
                }
            }
        }
        
        if (maxLength >= 2)
            return str.substr(start, maxLength);
        
        return NULL;
    }
    
    // Use Center Expand to find longest palindrome substring
    string centerExpandFindLongestPalindrome(const string &str)
    {
        const size_t length = str.length();
        int maxLength = 0;
        int start = 0;
        
        // For odd number
        for (int i = 0; i < length; i++)
        {
            int startIndex = i - 1;
            int endIndex = i + 1;
            while (startIndex >= 0 && endIndex < length - 1 && str[startIndex] == str[endIndex])
            {
                if (endIndex - startIndex + 1 > maxLength)
                {
                    maxLength = endIndex - startIndex + 1;
                    start = startIndex;
                }
                startIndex -= 1;
                endIndex += 1;
            }
        }
        
        // For even number
        for (int i = 0; i < length; i++)
        {
            int startIndex = i;
            int endIndex = i + 1;
            while (startIndex >= 0 && endIndex < length - 1 && str[startIndex] == str[endIndex])
            {
                if (endIndex - startIndex + 1 > maxLength)
                {
                    maxLength = endIndex - startIndex + 1;
                    start = startIndex;
                }
                startIndex -= 1;
                endIndex += 1;
            }
        }
        if (maxLength > 0)
            return str.substr(start, maxLength);
    
        return NULL;
    }
    
    // Use Manacher Algorithm to find longest palindrome substring
    // http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html
    string manacherFindLongestPalindrome(const string &str)
    {
        // Insert start with &, and # for each seperation
        string adjustedString = "$#";
        for (int i = 0; i < str.length(); i++)
        {
            adjustedString += str[i];
            adjustedString += "#";
        }
        // Store the values of palindromic radius
        vector<int> radiuses(adjustedString.size());
        int max = 0;
        int symmetryAxis = 0;
        for (int i = 1; i < adjustedString.length(); i++)
        {
            if (max > i)
                radiuses[i] = MIN(radiuses[2 * symmetryAxis - i], max - i);
            else
                radiuses[i] = 1;
            
            while (adjustedString[i - radiuses[i]] == adjustedString[i + radiuses[i]])
                radiuses[i] += 1;
            
            if (i + radiuses[i] > max)
            {
                symmetryAxis = i;
                max = i + radiuses[i];
            }
        }
        
        int maxRadius = 0;
        int maxCenter = 0;
        for (int i = 1; i < adjustedString.length(); i++)
        {
            if (radiuses[i] > maxRadius)
            {
                maxCenter = i;
                maxRadius = radiuses[i];
            }
        }
        int startIndex = maxCenter - maxRadius + 1;
        int endIndex = maxCenter + maxRadius - 1;
        
        string result;
        for (int i = startIndex; i <= endIndex; i++)
        {
            if (adjustedString[i] != '#')
                result += adjustedString[i];
        }
        
        return result;
    }
    
    // Suppport function to judge if a string is palindromic
    bool isPalindromic(const string &str)
    {
        // If the string is empty
        if (str.length() == 0)
            return true;
        // Look at the first i-th and last i-th, to see ifthey are the same
        for (size_t start = 0, end = str.length() - 1; start < end; start++, end--)
            if (str[start] != str[end])
                return false;
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    cout << solution.longestPalindrome("a") << endl;
    
    return 0;
}
