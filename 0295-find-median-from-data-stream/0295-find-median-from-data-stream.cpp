class MedianFinder {
private:
    multiset<int> ms;
    multiset<int> ::iterator mid = ms.begin();
public:
    MedianFinder() {

    };
    
    void addNum(int num) {
        if (ms.size() == 0) {
            ms.insert(num);
            mid = ms.begin();
        } else if (num >= *mid) {
            ms.insert(num);
            if (ms.size() % 2 == 0) {
                ++mid;    
            }; 
        } else {
            ms.insert(num);
            if (ms.size() % 2) {
                --mid;    
            };            
        };
    };
    
    double findMedian() {
        return ms.size() % 2 ? *mid : (*mid + *prev(mid, 1)) / 2.0;        
    };
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */