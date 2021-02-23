
// @Title: 排序数组 (Sort an Array)
// @Author: rubychen0611
// @Date: 2021-02-15 17:28:24
// @Runtime: 40 ms
// @Memory: 15.5 MB

class MaxHeap
{
private:
    vector<int> heap;
    int n;
    int getParent(int i)
    {
        return (i - 1) / 2;
    }
    int getLeftChild(int i)
    {
        return 2 * i + 1;
    }
    int getRightChild(int i)
    {
        return 2 * i + 2;
    }

public:
    MaxHeap(vector<int>& nums)
    {
        heap = vector<int>(nums);
        n = nums.size();
        BuildHeap();
    }
    void BuildHeap()
    {
        for(int i = getParent(n - 1); i >= 0; i--)
            Heapify(i);
    }
    void Heapify(int i)
    {
        int left = getLeftChild(i), right = getRightChild(i);
        int max = i;
        if(left < n && heap[max] < heap[left])
        {
            max = left;
        }
        if (right < n && heap[max] < heap[right])
        {
            max = right;
        }
        if(max != i)
        {
            swap(heap[max], heap[i]);
            Heapify(max);
        }
    }
    vector<int> HeapSort()
    {
        int i = n - 1;
        for(; i >= 1; i--)
        {
            swap(heap[0], heap[i]);
            n--;
            Heapify(0);
        }
        return heap;
    }

};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MaxHeap heap(nums);
        return heap.HeapSort();
    }
};
