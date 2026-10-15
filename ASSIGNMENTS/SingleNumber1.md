class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int val : nums) {
        ans=ans^val;
    }
    return ans;
 }
};



<img width="387" height="136" alt="Screenshot 2026-10-15 165148" src="https://github.com/user-attachments/assets/d54460e4-0198-4a47-a792-528cabd6dd8f" />

