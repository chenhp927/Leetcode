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
Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.
*/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())
		{
			return 0;
		}

		int nFastIndex = 0;
		int nSlowIndex = 0;
		while (nFastIndex < nums.size())
		{
			if (nums[nFastIndex] != val)
			{
				nums[nSlowIndex++] = nums[nFastIndex++];
			}
			else
			{
				nFastIndex++;
			}
		}

		return nSlowIndex;
	}
};


int main() 
{ 
	Solution objS;
	vector<int> vecInput;
	vecInput.push_back(3);
	vecInput.push_back(2);
	vecInput.push_back(2);
	vecInput.push_back(3);
	//vecInput.push_back(2);

	int nRet = objS.removeElement(vecInput, 3);
	for (int i=0; i<vecInput.size(); ++i)
	{
		cout << vecInput[i] << ",";
	}

	system("pause");
	return 0; 
}