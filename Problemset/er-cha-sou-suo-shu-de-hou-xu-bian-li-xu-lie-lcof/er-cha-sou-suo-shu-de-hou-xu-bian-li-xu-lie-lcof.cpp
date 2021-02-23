
// @Title: 二叉搜索树的后序遍历序列 (二叉搜索树的后序遍历序列 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 21:02:06
// @Runtime: 0 ms
// @Memory: 14.3 MB

class Solution {
private:
    int isPartitioned(vector<int>& arr, int root)
    {
        int idx = -1;        
        int i = 0;
        while(i < arr.size() && arr[i] < root)
        {
            i++;
        }
        idx = i;
        if(i == arr.size())
            return idx;
        while(i < arr.size() && arr[i] > root)
        {
            i++;
        }
        if (i != arr.size())
            return -1;
        return idx;
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() <= 1)
            return true;
        int root = postorder.back();
        postorder.pop_back();
        int idx = isPartitioned(postorder, root);
        if(idx == -1)
            return false;
        if(idx == 0 || idx == postorder.size())
            return verifyPostorder(postorder);
        vector<int> v1, v2;
        for(int i = 0; i < idx; i++)
            v1.push_back(postorder[i]);
        for(int i = idx; i < postorder.size(); i++)
            v2.push_back(postorder[i]);
        return verifyPostorder(v1) && verifyPostorder(v2);
    }
};
