class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vecRet;
		if (nums.empty())
		{
			return vecRet;
		}

		map<int, int> mapTmp;
		for (int i=0; i<nums.size(); ++i)
		{
			int nTmp = target - nums[i];
			map<int, int>::iterator iter = mapTmp.find(nTmp);
			if (iter== mapTmp.end())
			{
				mapTmp.insert(make_pair(nums[i], i));
			}
			else
			{
				vecRet.push_back((*iter).second);
				vecRet.push_back(i);				
				break;
			}
		}

		return vecRet;
    }
};