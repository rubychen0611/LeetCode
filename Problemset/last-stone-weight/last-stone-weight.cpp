
// @Title: 最后一块石头的重量 (Last Stone Weight)
// @Author: rubychen0611
// @Date: 2021-01-05 21:28:23
// @Runtime: 0 ms
// @Memory: 6.3 MB

class MaxHeap {
private:
    vector<int> heap;
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
    MaxHeap(vector<int> array)
    {
        heap = array;
        buildMaxHeap();
    }
    void heapify(int i)
    {
        int left_child = getLeftChild(i), right_child = getRightChild(i);
        int max = i;
        if(left_child < heap.size() && heap[left_child] > heap[i])
            max = left_child;
        if(right_child < heap.size() && heap[right_child] > heap[max])
            max = right_child;
        if (max != i)
        {
            int tmp = heap[i];
            heap[i] = heap[max];
            heap[max] = tmp;
            heapify(max);
        }

    }
    void buildMaxHeap()
    {
        int i = getParent(heap.size()-1);//最后一个非叶节点；
        for(; i >= 0; i--)
        {
            heapify(i);
        }
    }
    int extractMax()
    {
        int max = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return max;
    }
    int getMax()
    {
        return heap[0];
    }

    void remove(int i)
    {
        heap[i] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(i);
        return;
    }
    void increase(int i, int k)
    {
        heap[i] = k;
        if (i == 0)
            return;

        int parent = getParent(i);
        while(heap[parent] < heap[i])
        {
            int tmp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = tmp;
            if(parent == 0)
                break;
            i = parent;
            parent = getParent(i);
        }
    }
    void insert(int k)
    {
        heap.push_back(-0xFFFFFFF);
        increase(heap.size()-1, k);
    }
    int getSize()
    {
        return heap.size();
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        MaxHeap maxHeap(stones);
        int s1, s2;
        while(maxHeap.getSize() >= 2)
        {
            s1 = maxHeap.extractMax();
            s2 = maxHeap.extractMax();
            if(s1 != s2)
                maxHeap.insert(abs(s1-s2));
        }
        if (maxHeap.getSize() == 1)
            return maxHeap.getMax();
        else return 0;
    }
};

