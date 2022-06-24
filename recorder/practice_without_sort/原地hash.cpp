class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] == 1)return 2;
            else return 1;
        }
        for (int i = 0; i < n; ++i) {
            // if (nums[i] < 1 || nums[i] > n)
            //     idx--;
                //将数据从 1~n 映射到 数组下标0~n-1 
                // 由鸽巢原理 大小为n的数组 最小未出现正整数不超过n+1
                //nums[i]-1 != i && nums[nums[i]-1]!=i  && nums[i]!=nums[nums[i]-1] 原地hash
                //数据合法
                 while (nums[i] > 0 && nums[i] <= n  && nums[i]!=nums[nums[i]-1]) { 
                    swap(nums[i], nums[nums[i] - 1]); 
                    }
            // }
        }
            for (int i = 1; i <= n; ++i) {
                if (nums[i - 1] != i)return i;
            }
        
        return nums.size()+1;
    }
};