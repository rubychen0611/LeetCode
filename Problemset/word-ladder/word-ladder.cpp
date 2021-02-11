
// @Title: 单词接龙 (Word Ladder)
// @Author: rubychen0611
// @Date: 2021-02-08 01:21:49
// @Runtime: 1848 ms
// @Memory: 19.3 MB

class Solution {
private:
    vector<list<int>> graph;
    int n;
    int len;
    unordered_set<string> words_set;
    bool distance_one(string a, string b)
    {
        int count = 0;
        for(int i = 0; i < len; i++)
        {
            if (a[i] != b[i])
                count++;
            if(count == 2)
                return false;
        }
        return count == 1;
    }
    int bfs_search(vector<string>& wordList, int beginIdx, int endIdx)
    {
        vector<bool> used_begin(n, false), used_end(n, false);
        queue<int> Q_begin, Q_end;
        used_begin[beginIdx] = true;
        Q_begin.push(beginIdx);
        used_end[endIdx] = true;
        Q_end.push(endIdx);
        int dis = 0;
        int Q_size;
        queue<int> * Q_cur;
        vector<bool> * used_cur, *used_another;
        while(!Q_begin.empty() && !Q_end.empty())
        {
            dis++;
            if(Q_begin.size() <= Q_end.size())
            {
                Q_size = Q_begin.size();
                Q_cur = &Q_begin;
                used_cur = &used_begin;
                used_another = &used_end;
            }
            else
            {
                Q_size = Q_end.size();
                Q_cur = &Q_end;
                used_cur = &used_end;
                used_another = &used_begin;
            }
            for(int j = 0; j < Q_size; j++)
            {
                int w = Q_cur -> front();
                Q_cur -> pop();
                //cout << w << endl;
                for(int neighbor: graph[w])
                {
                    if(!(*used_cur)[neighbor])
                    {
                        if((*used_another)[neighbor])
                            return dis + 1;
                        else
                        {
                            Q_cur -> push(neighbor);
                            (*used_cur)[neighbor] = true;
                        }
                    }
                }
            }
        }
        return INT_MAX;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int beginIdx = -1, endIdx = -1;
        for(int i = 0; i < wordList.size(); i++)
        {
            words_set.insert(wordList[i]);
            if(wordList[i] == beginWord)
                beginIdx = i;
            if(wordList[i] == endWord)
                endIdx = i;
        }
        if(endIdx == -1)
            return 0;
        if(beginIdx == -1)
        {
            wordList.push_back(beginWord);
            beginIdx = wordList.size() - 1;
        }

        n = wordList.size();
        graph = vector<list<int>>(n, list<int>());
        len = beginWord.length();
        // 建图
        for(int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(distance_one(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int dis = bfs_search(wordList, beginIdx, endIdx);

        if(dis == INT_MAX)
            return 0;
        return dis;



    }
};

