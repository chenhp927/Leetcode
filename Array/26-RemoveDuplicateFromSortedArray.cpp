// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <time.h>
#include <Windows.h>

using namespace std;

/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}

		int nSlowIndex = 0;
		int nFastIndex = 0;
		while (nFastIndex < nums.size())
		{
			if (nFastIndex >= 1 && nums[nFastIndex] == nums[nFastIndex-1])
			{
				++nFastIndex;
				continue;
			}
			else if (nFastIndex >= 1 && nums[nFastIndex] != nums[nFastIndex-1])
			{
				nums[nSlowIndex++] = nums[nFastIndex++];
			}
			else
			{
				++nFastIndex;
				++nSlowIndex;
			}
		}

		return nSlowIndex;
	}
};


int main() 
{ 
	Solution objS;
	vector<int> vecInput;
	vecInput.push_back(1);
	//vecInput.push_back(2);

	int nRet = objS.removeDuplicates(vecInput);
	for (int i=0; i<vecInput.size(); ++i)
	{
		cout << vecInput[i] << ",";
	}

	system("pause");
	return 0; 
}