class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for(int p : piles){
            right = max(right, p);
        }

        int result = right;
        while(left <= right){
            int mid = left + (right - left)/2; //guessed speed

            long long hours = 0;
            for(int p : piles){
                hours += ceil((double)p/mid);
            }
            if(hours <= h){
                result = mid;
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        return result;
    }
};
