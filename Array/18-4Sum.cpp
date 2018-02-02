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
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> vecRet;
		if (nums.size() < 4)
		{
			return vecRet;
		}

		sort(nums.begin(), nums.end());
		set<vector<int>> setRet;
		for (int i=0; i<nums.size(); ++i)
		{
			if (i >=1 && nums[i] == nums[i-1])
			{
				continue;
			}

			threeSum(i, setRet, nums, target);
		}

		set<vector<int>>::iterator iter = setRet.begin();
		for (; iter!=setRet.end(); ++iter)
		{
			vecRet.push_back((*iter));
		}

		return vecRet;
	}

	void threeSum(int nFirstIndex, set<vector<int>>& setRet, vector<int>& nums, int target)
	{
		int nFirstBase = nums[nFirstIndex];
		for (int i=nFirstIndex+1; i<nums.size(); ++i)
		{
			int nSecondBase = nums[i];
			int nLeft = i+1;
			int nRight = nums.size()-1;
			int nTmpTarget = target - nFirstBase - nSecondBase;
			while (nLeft < nRight)
			{
				if (nRight+1 < nums.size() && nums[nRight] == nums[nRight+1])
				{
					--nRight;
					continue;
				}

				if (nums[nLeft] + nums[nRight] == nTmpTarget)
				{
					vector<int> vecTmp;
					vecTmp.push_back(nFirstBase);
					vecTmp.push_back(nSecondBase);
					vecTmp.push_back(nums[nLeft]);
					vecTmp.push_back(nums[nRight]);
					sort(vecTmp.begin(), vecTmp.end());
					setRet.insert(vecTmp);
					++nLeft;
					--nRight;
				}
				else if (nums[nLeft] + nums[nRight] > nTmpTarget)
				{
					--nRight;
				}
				else
				{
					++nLeft;
				}
			}
		}
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