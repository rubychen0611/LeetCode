
// @Title: 区域和检索 - 数组可修改 (Range Sum Query - Mutable)
// @Author: rubychen0611
// @Date: 2021-02-12 18:02:37
// @Runtime: 500 ms
// @Memory: 148.7 MB

class NumArray {
private:
    vector<int> tree;   // 线段树
    int n;
    void buildTree(vector<int>& nums, int cur, int start, int end)       // 建树
    {
        if(start == end)
            tree[cur] = nums[start];
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * cur + 1, rightChild = 2 * cur + 2;
            buildTree(nums, leftChild, start, mid);
            buildTree(nums, rightChild, mid + 1, end);
            tree[cur] = tree[leftChild] + tree[rightChild];
        }
    }
    int query(int cur, int start, int end, int i, int j)    // 查询区间[i, j]的和
    {
        // [start, end] 为当前节点包含的区间（建树时已经固定）
        if(i > end || j < start)
            return 0;
        if(i <= start && end <= j)  // 当前区间为询问区间的子集时直接返回当前区间的和
            return tree[cur];
        int mid = (start + end) / 2;
        int leftChild = 2 * cur + 1, rightChild = 2 * cur + 2;
        int left_sum = query(leftChild, start, mid, i, j); // 左子结点包含的区间：[start, mid]
        int right_sum = query(rightChild, mid + 1, end, i, j); // 右子节点包含的区间[mid+1, end]
        return left_sum + right_sum;
    }
    void update_tree(int cur, int start, int end, int i, int val) // 更新第i个结点值为val
    {
        if(start == end)
            tree[cur] = val;
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * cur + 1, rightChild = 2 * cur + 2;
            if(i >= start && i <= mid) // i在左子树中
                update_tree(leftChild, start, mid, i, val);
            else  // i在右子树中
                update_tree(rightChild, mid+1, end, i, val);
            tree[cur] = tree[leftChild] +tree[rightChild];
        }
    }
public:
    NumArray(vector<int>& nums) {
        if(nums.empty())
            return;
        n = nums.size();
        tree.resize(4 * n + 1);
        buildTree(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        update_tree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

