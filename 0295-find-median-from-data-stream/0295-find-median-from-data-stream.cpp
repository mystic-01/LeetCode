class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    };
    
    void addNum(int num) {
        minHeap.push(num);        
        maxHeap.push(minHeap.top());
        minHeap.pop();        
        if (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());    
            maxHeap.pop();
        };
    };
    
    double findMedian() {
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();            
        };
        return (minHeap.top() + maxHeap.top()) / 2.0;
    };
};