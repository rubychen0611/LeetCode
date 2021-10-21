
// @Title: 前 K 个高频元素 (Top K Frequent Elements)
// @Author: rubychen0611
// @Date: 2021-10-12 17:22:28
// @Runtime: 24 ms
// @Memory: 13.4 MB

struct Info {
    int num;
    int count;
    Info(int _num, int _count) {
        num = _num;
        count = _count;
    }
    bool operator < (const Info& info) const {
        return count < info.count;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> numToCount;
        for(int num: nums) {
            if(numToCount.find(num) != numToCount.end()) {
                numToCount[num] ++;
            }
            else {
                numToCount.insert(pair<int,int>(num, 1));
            }
        }
        priority_queue<Info, vector<Info>, less<Info>> maxHeap;
        for(map<int,int>::iterator it = numToCount.begin(); it != numToCount.end(); it++) {
            maxHeap.push(Info(it->first, it->second));
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(maxHeap.top().num);
            maxHeap.pop();
        }
        return ans;
    }
};
