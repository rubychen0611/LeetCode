
// @Title: 天际线问题 (The Skyline Problem)
// @Author: rubychen0611
// @Date: 2021-01-22 11:22:28
// @Runtime: 44 ms
// @Memory: 16.6 MB

enum PointType {LEFT, RIGHT};
struct Building
{
    int left, right, height;
    Building(int l, int r, int h): left(l), right(r), height(h){}
    bool operator < (const Building& b) const
    {
        return height < b.height;
    }
};
struct Point
{
    int x, y;
    Building building;
    PointType type;
    Point(int x, int y, Building b, PointType t): building(b), type(t)
    {
        this->x = x;
        this->y = y;
    }
    bool operator < (const Point& p) const
    {
        return x < p.x;
    }

};
//bool cmpPoint(Point a, Point b){
//    return (a.x < b.x);
//}
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<vector<int>> ans;
        if (buildings.empty())
            return ans;
        vector<Point> points;
        vector<Building> my_buildings;
        for (vector<int> b: buildings)
        {
            Building new_building(b[0], b[1], b[2]);
            my_buildings.push_back(new_building);
            Point point1 = Point(b[0], b[2], new_building, PointType(LEFT));
            Point point2 = Point(b[1], b[2], new_building, PointType(RIGHT));

            points.push_back(point1);
            points.push_back(point2);
        }
        sort(points.begin(), points.end());

        int cur_height = 0;
        multiset<Building> s; // 最大堆
        for (int i = 0; i < points.size(); i ++) {
            if (points[i].type == LEFT) {
                s.insert(points[i].building);
            } else // RIGHT
            {
                multiset<Building>::iterator it = s.find(points[i].building);
                if (it != s.end()) {
                    //cout << p.building.left << " " << p.building.right << " " << p.building.height << endl;
                    s.erase(it);
                }
            }
            if (i == points.size()-1 || points[i + 1].x > points[i].x) //跳过相同横坐标的点
            {
                multiset<Building>::reverse_iterator max = s.rbegin();
                if (max != s.rend()) {
                    if (max->height != cur_height) {
                        ans.push_back(vector<int>{points[i].x, max->height});
                        cur_height = max->height;
                    }
                } else    // 此时优先队列为空
                {
                    if (cur_height != 0) {
                        ans.push_back(vector<int>{points[i].x, 0});
                        cur_height = 0;
                    }
                }
            }

        }
        return ans;
    }
};

