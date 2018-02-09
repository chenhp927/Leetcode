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
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if(nums.empty())
		{
			return;
		}

		for (int i=nums.size()-1; i>=1; --i)
		{
			bool bFind = false;
			if (nums[i-1] < nums[i])
			{
				bFind = true;
			}

			if (bFind)
			{
				int nBase = nums[i-1];
				int j=i;
				int nSwapIndex = j;
				for (; j<nums.size(); ++j)
				{
					if (nums.at(j) > nBase && nums.at(j) < nums[i])
					{
						nSwapIndex = j;
					}
				}

				swap(nums[i-1], nums[nSwapIndex]);
				sort(nums.begin()+i, nums.end());
				return;
			}
		}

		sort(nums.begin(), nums.end());
	}
};


int main() 
{ 
	Solution objS;
	vector<int> vecInput;
	vecInput.push_back(4);
	vecInput.push_back(2);
	vecInput.push_back(0);
	vecInput.push_back(2);
	vecInput.push_back(3);
	vecInput.push_back(2);
	vecInput.push_back(0);

	objS.nextPermutation(vecInput);
	for (int i=0; i<vecInput.size(); ++i)
	{
		cout << vecInput[i] << ",";
	}

	system("pause");
	return 0; 
}