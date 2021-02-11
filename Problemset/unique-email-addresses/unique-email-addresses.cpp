
// @Title: 独特的电子邮件地址 (Unique Email Addresses)
// @Author: rubychen0611
// @Date: 2021-02-11 12:25:43
// @Runtime: 28 ms
// @Memory: 14 MB

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> count;
        for(const string &email: emails)
        {
            int idx = email.find("@");
            string front = email.substr(0, idx);
            string back = email.substr(idx);
            int plus_pos = front.find("+");
            if(plus_pos != front.npos)
                front = front.substr(0, plus_pos);
            int point_pos = front.find(".");
            while(point_pos != front.npos)
            {
                front.erase(point_pos, 1);
                point_pos = front.find(".");
            }
            string processed = front + back;
            if(count.find(processed) == count.end())
                count[processed] = 1;
            else
                count[processed] ++;
        }
        return count.size();
    }
};
