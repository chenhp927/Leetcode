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
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> vecRet;
		if (nums.empty())
		{
			return vecRet;
		}

		sort(nums.begin(), nums.end());
		set<vector<int>> setValid;
		for (int i=0; i<nums.size(); ++i)
		{
			if (i >= 1 && nums[i] == nums[i-1])
			{
				continue;
			}

			MySum(setValid, i, -nums[i], nums);
		}

		set<vector<int>>::iterator iter  = setValid.begin();
		for (; iter!=setValid.end(); ++iter)
		{
			vecRet.push_back((*iter));
		}

		return vecRet;
	}

	void MySum(set<vector<int>>& setValid, int nIndex, int nParaValue, vector<int>& nums)
	{
		int nLeft = nIndex + 1;
		int nRight = nums.size() -1;
		
		while (nLeft < nRight)
		{
			if (nRight + 1 < nums.size() && nums[nRight] == nums[nRight+1])
			{
				--nRight;
				continue;
			}

			if (nums[nLeft] + nums[nRight] == nParaValue)
			{
				vector<int> vecValid;
				vecValid.push_back(nums[nIndex]);
				vecValid.push_back(nums[nLeft]);
				vecValid.push_back(nums[nRight]);
				sort(vecValid.begin(), vecValid.end());
				setValid.insert(vecValid);
				++nLeft;
				--nRight;
			}
			else if (nums[nLeft] + nums[nRight] > nParaValue)
			{
				--nRight;
			}
			else
			{
				++nLeft;
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