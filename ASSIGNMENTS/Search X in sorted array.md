class Solution {
public:
    int search(vector<int>& nums, int target) {
       int low = 0;
        int high = nums.size() - 1;
        int found = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (target == nums[mid]) {
                found = mid;
                break;
            }
            else if (target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return found;
    }
};


<img width="435" height="121" alt="image" src="https://github.com/user-attachments/assets/cdf032c0-86cb-4577-b3c2-9e2f7cd54b92" />

