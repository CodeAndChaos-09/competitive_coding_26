class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int> set;
         int n = nums.size();
         for(int i=0;i<n;i++)
         {
            if (i>k)
            {
                set.erase(nums[i-k-1]);
            }
            if (set.count(nums[i]))
            {
                return true;
            }
            set.insert(nums[i]);
         }
         return false;
    }
};