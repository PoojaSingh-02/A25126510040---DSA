class Solution {
public:
    int reverse(int x) {
        int r=0;
        while(x!=0) {
            int d=x%10;
            x=x/10;
            if (r>INT_MAX/10 || r<INT_MIN/10)
                return 0;
                r=r*10+d;
        }
        return r;
    }
};


<img width="461" height="142" alt="image" src="https://github.com/user-attachments/assets/97762604-aa8c-4a8d-b00e-45cf83cf0f85" />

