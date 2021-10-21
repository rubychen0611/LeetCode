
// @Title: 向下的路径节点之和 (向下的路径节点之和)
// @Author: rubychen0611
// @Date: 2021-10-18 23:23:27
// @Runtime: 8 ms
// @Memory: 18.4 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int target;
    int ans;
    void pathSumInternal(TreeNode* root, vector<int>& prefixSum, unordered_map<int, int> &hashMap) {
        if(!root) {
            return;
        }
        int newPrefixSum = root ->val;
        if (prefixSum.size() > 0) {
            newPrefixSum += prefixSum.back();
        }
        if(hashMap.find(newPrefixSum - target) != hashMap.end()) {
            ans += hashMap[newPrefixSum - target];
        }
        prefixSum.push_back(newPrefixSum);
        if(hashMap.find(newPrefixSum) == hashMap.end()) {
            hashMap.insert(pair<int,int>(newPrefixSum, 1));
        } else {
            hashMap[newPrefixSum] ++;
        }
        pathSumInternal(root -> left, prefixSum, hashMap);
        pathSumInternal(root -> right, prefixSum, hashMap);
        hashMap[newPrefixSum] --;
        prefixSum.pop_back();

    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        ans = 0;
        vector<int> prefixSum;
        unordered_map<int, int> hashMap;
        hashMap.insert(pair<int,int>(0, 1));
        pathSumInternal(root, prefixSum, hashMap);
        return ans;
    }
};
