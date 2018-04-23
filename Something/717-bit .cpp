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
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/
class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		if (bits.size() > 1000 || bits.size() < 1)
		{
			return false;
		}

		for (int i=0; i<bits.size(); ++i)
		{
			if (i == bits.size() - 1 && bits[i] == 0)
			{
				return true;
			}

			if (bits[i] == 1)
			{
				++i;
				continue;
			}
			else
			{
				continue;
			}
		}

		return false;
	}
};


int main() 
{ 
	char* pBuf = "1234567";
	string str = pBuf;
	cout << str<< endl;

	system("pause");
	return 0; 
}