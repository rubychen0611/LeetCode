
// @Title: 最小K个数 (Smallest K LCCI)
// @Author: rubychen0611
// @Date: 2021-01-05 20:58:45
// @Runtime: 96 ms
// @Memory: 19.3 MB


class MinHeap {
private:
    vector<int> heap;
    int cur_size;
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
    MinHeap(vector<int> array)
    {
        heap = array;
        cur_size = heap.size();
        buildMinHeap();
    }
    void heapify(int i)
    {
        int left_child = getLeftChild(i), right_child = getRightChild(i);
        int min = i;
        if(left_child < cur_size && heap[left_child] < heap[i])
            min = left_child;
        if(right_child < cur_size && heap[right_child] < heap[min])
            min = right_child;
        if (min != i)
        {
            int tmp = heap[i];
            heap[i] = heap[min];
            heap[min] = tmp;
            heapify(min);
        }

    }
    void buildMinHeap()
    {
        int i = getParent(cur_size-1);//最后一个非叶节点；
        for(; i >= 0; i--)
        {
            heapify(i);
        }
    }
    int extractMin()
    {
        if(cur_size > 0)
        {
            int min = heap[0];
            heap[0] = heap[cur_size - 1];
            cur_size --;
            heapify(0);
            return min;
        }
        else
            return 0xFFFFFFF;
    }
};

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        MinHeap minHeap(arr);
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(minHeap.extractMin());
        }
        return ans;

    }
};

