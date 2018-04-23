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
给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。

求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。

例如 :
输入: 
A = [2, 1, 4, 3]
L = 2
R = 3
输出: 3
解释: 满足条件的子数组: [2], [2, 1], [3].
注意:

L, R  和 A[i] 都是整数，范围在 [0, 10^9]。
数组 A 的长度范围在[1, 50000]。

*/
class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		vector<vector<int> > setSubArray;
		vector<int> vecTmp;
		
		for (int i=0; i<A.size(); ++i)
		{
			vecTmp.clear();
			if (A[i] > R)
			{
				continue;
			}

			vecTmp.push_back(A[i]);
			if(A[i] >= L && A[i] <= R)
			{
				setSubArray.push_back(vecTmp);
			}

			int nMaxTmp = A[i];
			for (int j= i+1; j<A.size(); ++j)
			{
				nMaxTmp = max(nMaxTmp, A[j]);
				if (nMaxTmp > R)
				{
					break;
				}

				vecTmp.push_back(A[j]);
				if (nMaxTmp >= L && nMaxTmp <= R)
				{
					setSubArray.push_back(vecTmp);
				}
			}
		}

		return setSubArray.size();
	}
};


int main() 
{ 
	Solution objS;
	vector<int> vecTest;
/*
	vecTest.push_back(341);
	vecTest.push_back(668);
	vecTest.push_back(598);
	vecTest.push_back(98);
	vecTest.push_back(241);
*/
/*
[876,880,482,260,132,421,732,703,795,420,
 871,445,400,291,358,589,617,202,755,810,
 227,813,549,791,418,528,835,401,526,584,
 873,662,13,314,988,101,299,816,833,224,
 160,852,179,769,646,558,661,808,651,982,
 878,918,406,551,467,87,139,387,16,531,
 307,389,939,551,613,36,528,460,404,314,
 66,111,458,531,944,461,951,419,82,896,
 467,353,704,905,705,760,61,422,395,298,
 127,516,153,299,801,341,668,598,98,241]


658
719
*/

/*
703
662 13, 314,  4
646, 558, 661 8
467, 353, 704 11
705 12
341, 668, 598, 98, 241
*/

	int nNew[] = {876,880,482,260,132,421,732,703,795,420,871,445,400,291,358,589,617,202,755,810,227,
		813,549,791,418,528,835,401,526,584,873,662,13,314,988,101,299,816,833,224,160,852,179,
		769,646,558,661,808,651,982,878,918,406,551,467,87,139,387,16,531,307,389,939,551,613,36,
		528,460,404,314,66,111,458,531,944,461,951,419,82,896,467,353,704,905,705,760,61,422,395,298,
		127,516,153,299,801,341,668,598,98,241};

	int nLen = sizeof(nNew) / sizeof(int);
	for (int i=0; i<nLen; ++i)
	{
		vecTest.push_back(nNew[i]);
	}

	int nRet = objS.numSubarrayBoundedMax(vecTest, 658, 719);
	cout << nRet << endl;

	system("pause");
	return 0; 
}