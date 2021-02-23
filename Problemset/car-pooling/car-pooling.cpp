
// @Title: 拼车 (Car Pooling)
// @Author: rubychen0611
// @Date: 2021-02-17 16:36:30
// @Runtime: 8 ms
// @Memory: 8.8 MB

struct Trip
{
    int num_passengers, start_location, end_location;
    Trip(int n, int s, int e):num_passengers(n), start_location(s), end_location(e){}
    bool operator > (const Trip & t)    const
    {
        return end_location > t.end_location;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips.empty())
            return true;
        int n = trips.size();
        vector<Trip> trips_new;
        for(int i = 0; i < n; i++)
        {
            trips_new.push_back(Trip(trips[i][0], trips[i][1], trips[i][2]));
        }
        sort(trips_new.begin(), trips_new.end(), [](const Trip &t1, const Trip &t2) -> bool{
            return t1.start_location < t2.start_location;
        });
        int cur = 0;    // 目前人数
        priority_queue<Trip, vector<Trip>, greater<Trip>> min_heap;
        for(int i = 0; i < n; i++)
        {
            while(!min_heap.empty() && min_heap.top().end_location <= trips_new[i].start_location)
            {
                Trip t = min_heap.top();
                cur -= t.num_passengers;
                min_heap.pop();
            }
            if(cur + trips_new[i].num_passengers > capacity)
                return false;
            else
            {
                cur += trips_new[i].num_passengers;
                min_heap.push(trips_new[i]);
            }
        }
        return true;
    }
};
