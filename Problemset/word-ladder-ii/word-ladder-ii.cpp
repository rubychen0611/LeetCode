
// @Title: 单词接龙 II (Word Ladder II)
// @Author: rubychen0611
// @Date: 2021-02-08 14:30:28
// @Runtime: 1564 ms
// @Memory: 17.7 MB

class Solution
{
private:
    vector<vector<int>> graph;
    int n;
    int len;
    int min_dis;
    unordered_set<string> words_set;
    vector<vector<string>> ans;
    vector<vector<int>> parent;
    bool distance_one(string a, string b)
    {
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            if (a[i] != b[i])
                count++;
            if (count == 2)
                return false;
        }
        return count == 1;
    }
    void backPrint(vector<string> &wordList, vector<string>& path, int pos, int idx)
    {
        //cout << "******";
        path[pos] = wordList[idx];
        if (pos == 0)
        {
            ans.push_back(path);
            return;
        }

        for(int parent: parent[idx])
        {
            backPrint(wordList, path, pos-1, parent);
        }

    }
    void bfs_search(vector<string> &wordList, int beginIdx, int endIdx)
    {
        bool found = false;
        vector<bool> used_begin(n, false);
        vector<int> level(n, -1);
        level[beginIdx] = 0;
        queue<int> Q_begin;
        used_begin[beginIdx] = true;
        Q_begin.push(beginIdx);
        parent[beginIdx].push_back(-1);
        int dis = 0;
        int Q_size;
        while (!Q_begin.empty())
        {
            dis++;
           // cout << dis << endl;
            Q_size = Q_begin.size();
            for (int j = 0; j < Q_size; j++)
            {
                int w = Q_begin.front();
                Q_begin.pop();
                //cout << w << endl;
                for (int neighbor: graph[w])
                {
                    if (!used_begin[neighbor]) //新节点
                    {
                        level[neighbor] = dis;
                        parent[neighbor].push_back(w);
                        used_begin[neighbor] = true;
                        if (neighbor == endIdx)
                            found = true;
                        else
                            Q_begin.push(neighbor);
                    }
                    else if (parent[neighbor][0] != -1 && level[parent[neighbor][0]] == dis - 1) // 这一层已被找到一次
                    {
                        parent[neighbor].push_back(w);
                    }
                }
            }

            if(found)   // 在这层找到了endWord
            {
//                for(int i = 0; i < n; i++)
//                {
//                    cout << wordList[i] << level[i] << ":";
//                    for(int p: parent[i])
//                    {
//                        if(p != -1)
//                            cout << wordList[p] << " ";
//                    }
//                    cout << endl;
//                }
                vector<string> path(dis + 1);
                backPrint(wordList, path, dis, endIdx);
                return;
            }
        }
        return;
    }

    void backtrace(vector<string> &wordList, vector<string> &path, vector<bool> & vis, int curIdx, int endIdx, int i)
    {
        if (i == min_dis - 1)
        {
            if (curIdx == endIdx)
                ans.push_back(path);
            return;
        }
        for (int neighbor: graph[curIdx])
        {
            if(!vis[neighbor])
            {
                path.push_back(wordList[neighbor]);
                vis[neighbor] = true;
                backtrace(wordList, path, vis, neighbor, endIdx, i + 1);
                path.pop_back();
                vis[neighbor] = false;
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int beginIdx = -1, endIdx = -1;
        for (int i = 0; i < wordList.size(); i++)
        {
            words_set.insert(wordList[i]);
            if (wordList[i] == beginWord)
                beginIdx = i;
            if (wordList[i] == endWord)
                endIdx = i;
        }
        if (endIdx == -1)
            return ans;
        if (beginIdx == -1)
        {
            wordList.push_back(beginWord);
            beginIdx = wordList.size() - 1;
        }

        n = wordList.size();
        graph = vector<vector<int>>(n, vector<int>());
        len = beginWord.length();
        // 建图
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (distance_one(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        parent = vector<vector<int>>(n, vector<int>());
        bfs_search(wordList, beginIdx, endIdx);
        return ans;
    }
};

