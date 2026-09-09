class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        while ( min < max)
        {
        int mid = (min + max) / 2;
        if(nums[mid] >= target )
        {
            max = mid ;
        }
        else
        {
            min = mid + 1;
        }
        }
    return (min < nums.size() && nums[min] == target) ? min : -1;

        
    }
};
