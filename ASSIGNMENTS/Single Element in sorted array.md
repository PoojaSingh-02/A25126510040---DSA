class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1)
                mid--;
            if (nums[mid] == nums[mid + 1])
                left = mid + 2;
            else
                right = mid;
        }
        return nums[left];
    }
};


<img width="501" height="122" alt="image" src="https://github.com/user-attachments/assets/040f6812-6598-473b-bd0f-b862d9bb207e" />

