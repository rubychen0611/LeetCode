
// @Title: 爱吃香蕉的珂珂 (Koko Eating Bananas)
// @Author: rubychen0611
// @Date: 2021-10-13 20:22:26
// @Runtime: 36 ms
// @Memory: 18.3 MB

class Solution {
private:
    int calCostHours(vector<int>& piles, int speed) {
        int cost = 0;
        for(int pile: piles) {
            cost += (pile / speed);
            if(pile % speed > 0) {
                cost ++;
            }
        }
        return cost;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int max = 0;
        for(int pile: piles) {
            max = pile > max ? pile: max;
        }
        int right = max;
        while(left <= right) {
            int mid = (left + right) / 2;
            int costHours = calCostHours(piles, mid);
            if(costHours <= h) {
                if(mid == 1 || calCostHours(piles, mid - 1) > h) {
                    return mid;
                }
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
