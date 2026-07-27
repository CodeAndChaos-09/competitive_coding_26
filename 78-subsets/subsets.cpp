class Solution {
public:
  // Recursive function to generate all subsets
   void subset(vector<int>& arr, int i,vector<vector<int>>& ans,vector<int>& nums)
     // arr is current subset that is being built
     // i  is index i.e current position in given nums
     // ans this stores all subsets
     // nums is given iput array
        {
            if(i==nums.size()) // we will check for every element 
                 {
                    ans.push_back(arr); // Store the current subset
                    return;             // Stop this recursion 
                 }
              

              arr.push_back(nums[i]);
              subset(arr,i+1,ans,nums);
              arr.pop_back(); //backtrak undo the previous choice the element we added we will exclude it therefore we get array before pushing element
              subset(arr, i+1, ans, nums); // exxclude the cuurent element 
        }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>arr;
        subset(arr, 0, ans, nums);
        return ans;
    }
};