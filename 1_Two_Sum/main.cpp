class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result_vector;
        vector<int> temp = nums;
        
        sort(temp.begin(), temp.end());
        size_t i = 0;
        size_t j = nums.size() - 1;  // 2 <= nums.length <= 10^4
        
        while (i < j) {
            if (temp[i] + temp[j] < target)
                ++i;
            else if (temp[i] + temp[j] > target)
                --j;
            else {  // find target
                for (size_t index = 0; index < nums.size(); ++index) {
                    if (nums[index] == temp[i])
                        result_vector.push_back(index);
                    else if (nums[index] == temp[j])
                        result_vector.push_back(index);
                }
                break;
            }
        }
        return result_vector;
    }
};
