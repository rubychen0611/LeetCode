
// @Title: 婴儿名字 (Baby Names LCCI)
// @Author: rubychen0611
// @Date: 2021-02-09 13:00:04
// @Runtime: 404 ms
// @Memory: 79.9 MB

class UFSet
{
private:
    int n;
    vector<int> parent;
public:
    UFSet(int n)
    {
        this-> n = n;
        parent.resize(n, -1);

    }
    int find(int i)
    {
        while(parent[i] >= 0)
            i = parent[i];
        return i;
    }
    int collapsing_find(int i)  // 路径压缩
    {
        // 搜索根root
        int root = i;
        while(parent[root] >= 0)
            root = parent[root];
        while(i != root)
        {
            int tmp = parent[i];
            parent[i] = root;
            i = tmp;
        }
        return root;
    }
    void set_union(int i, int j)
    {
        int root1 = find(i), root2 = find(j);
        if(root1 != root2)
        {
            int tmp = parent[root1] + parent[root2];
            if(parent[root1] < parent[root2])
            {
                parent[root1] = root2;
                parent[root2] = tmp;
            }
            else
            {
                parent[root2] = root1;
                parent[root1] = tmp;
            }
        }
    }
    void union_root(int root1, int root2)
    {
        if(root1 != root2)
        {
            int tmp = parent[root1] + parent[root2];
            if(parent[root1] < parent[root2])
            {
                parent[root1] = root2;
                parent[root2] = tmp;
            }
            else
            {
                parent[root2] = root1;
                parent[root1] = tmp;
            }
        }
    }
};

class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        int n = names.size();
        vector<string> name(n);
        vector<int> freq(n);
        unordered_map<string, int> name_map;
        for(int i = 0; i < n; i++)
        {
            char s[40];
            int f;
            sscanf(names[i].c_str(), "%[a-zA-Z](%d)", s, &f);
            //sscanf("John(15)", "%[a-zA-Z](%d)", s, &f);
            //cout << s << " "<< f <<endl;
            name[i] = s;
            name_map[name[i]] = i;
            freq[i] = f;
        }
        UFSet ufset(n);
        for(const string & synonym: synonyms)
        {
            char s1[40], s2[40];
            sscanf(synonym.c_str(), "(%[a-zA-Z],%[a-zA-Z])", s1, s2);
            int idx1 = name_map[s1], idx2 = name_map[s2];
            ufset.set_union(idx1, idx2);
        }

        vector<vector<int>> name_sets(n);
        vector<string> ans;
        for(int i = 0; i < n; i++)
        {
            name_sets[ufset.collapsing_find(i)].push_back(i);
        }
        for(int i = 0; i < n; i++)
        {

            if(!name_sets[i].empty())
            {
                //cout<< i<< ":";
                string min_name = name[i];
                int sum = 0;
                for(int j = 0; j < name_sets[i].size(); j++)
                {
                    //cout << j <<" ";
                    if(name[name_sets[i][j]] < min_name)
                        min_name = name[name_sets[i][j]];
                    sum += freq[name_sets[i][j]];
                }
                ans.push_back(min_name + "(" + to_string(sum) + ")");
                //cout << ans.back() << endl;
            }
        }
        return ans;
    }
};

