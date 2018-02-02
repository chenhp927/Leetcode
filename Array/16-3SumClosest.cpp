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
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int nClosetRet = INT_MAX;
		if (nums.size() < 3)
		{
			return nClosetRet;
		}

		sort(nums.begin(), nums.end());
		int nAbsCompare = INT_MAX;
		for (int i=0; i<nums.size(); ++i)
		{
			if (i>=1 && nums[i] == nums[i-1])
			{
				continue;
			}

			int nLeft = i+1;
			int nRight = nums.size()-1;
			while (nLeft < nRight)
			{
				if (nums[nLeft] + nums[nRight] + nums[i] == target)
				{
					return target;
				}
				else if (nums[nLeft]+nums[nRight]+nums[i]-target > 0)
				{
					if(abs(nums[nLeft]+nums[nRight]+nums[i]-target) < nAbsCompare)
					{
						nAbsCompare = abs(nums[nLeft]+nums[nRight]+nums[i]-target);
						nClosetRet = nums[nLeft]+nums[nRight]+nums[i];
					}
					--nRight;
				}
				else
				{
					if (abs(nums[nLeft]+nums[nRight]+nums[i]-target) < nAbsCompare)
					{
						nAbsCompare = abs(nums[nLeft]+nums[nRight]+nums[i]-target);
						nClosetRet = nums[nLeft]+nums[nRight]+nums[i];
					}
					++nLeft;
				}
			}
		}

		return nClosetRet;
	}
};


int main() 
{ 
	Solution objS;
	vector<int> vecInput;
	vecInput.push_back(-2);
	vecInput.push_back(0);
	vecInput.push_back(0);
	vecInput.push_back(2);
	vecInput.push_back(2);

	vector<vector<int>> vecRet = objS.threeSum(vecInput);
	for (int i=0; i<vecRet.size(); ++i)
	{
		for (int j=0; j<vecRet[i].size(); ++j)
		{
			cout << vecRet[i][j] << ",";
		}
		cout << endl;
	}

	system("pause");
	return 0; 
}