/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int nMaxArea = 0;
		if (height.empty())
		{
			return nMaxArea;
		}

		int nRight = height.size()-1;
		int nLeft = 0;
		while (nLeft < nRight)
		{
			int nLen = nRight - nLeft;
			nMaxArea = max(nMaxArea, nLen*min(height[nLeft], height[nRight]));
			if (height[nLeft] <= height[nRight])
			{
				++nLeft;
			}
			else
			{
				--nRight;
			}
		}

		return nMaxArea;
	}
};