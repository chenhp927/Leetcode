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
����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������

����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]

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