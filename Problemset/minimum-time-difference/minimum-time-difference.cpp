
// @Title: 最小时间差 (Minimum Time Difference)
// @Author: rubychen0611
// @Date: 2021-10-10 22:48:59
// @Runtime: 12 ms
// @Memory: 13.4 MB

class Solution {
private:
    int stringToMinute(string& timePoint) {
        int hour = (timePoint[0] - '0') * 10 + (timePoint[1] - '0');
        int minute = (timePoint[3] - '0') * 10 + (timePoint[4] - '0');
        return hour * 60 + minute;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(string& timePoint: timePoints) {
            int minute = stringToMinute(timePoint);
            minutes.push_back(minute);
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = minutes.back() - minutes.front();
        for(int i = 0; i < minutes.size() - 1; i++) {
            int diff = minutes[i+1] - minutes[i];
            if(diff < minDiff) {
                minDiff = diff;
            }
        }
        int diff = minutes.front() + 60*24 - minutes.back();
        if(diff < minDiff) {
            minDiff = diff;
        }
        return minDiff;
    }
};
