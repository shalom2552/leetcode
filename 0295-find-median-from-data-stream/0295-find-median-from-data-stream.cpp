/*
Motivation: we'll keep two priority queues, one for the bigger numbers 
    and one for the smaller numbers (from median).
    The bigger is a min-heap and the smaller are max-heap.
    in each addition call, we'll insert the new number to the corresponding
    queue according to median, and keep the queue sizes, about equal.
    when calling find median, well return the top number in the bigest.
    we modify the comparison of bigger to get min-heap, by using the negative value.
    queue size or the mean of the top in bot if thier equal.
Complexity: 
    addNum:
        Time - O(log(n)): heap insert 
        Space - O(1): no use extra space
    findMedian:
        Time - O(1): simple if checks
        Space - O(1): no use extra space
*/
class MedianFinder {
public:
    MedianFinder()
    {
    }
    
    void addNum(int num) {
        // compare to current median add to the right heap
        // if the small is empty than insert to small
        if (m_small.empty() || num <= m_small.top()) {
            m_small.push(num);
        } else {
            // we insert -num to get a max heap
            m_large.push( (-1) * num);
        }

        // fix heaps size to be diffrent by no more than one value 
        // not need to check for more than one since we keep it updated
        if (m_small.size() + 1 < m_large.size()) {
            // remove one from large and insert to small
            // negate the number since we inserted it as negative
            m_small.push((-1) * m_large.top());
            m_large.pop();
        } else if (m_small.size() > m_large.size() + 1) {
            // remove one from small and insert to large
            // negate the number to keep a max heap
            m_large.push((-1) * m_small.top());
            m_small.pop();
        }
    }
    
    double findMedian() {
        // compare the sizes of the queue
        // median is the top on the bigger size or mean of both
        if (m_small.size() > m_large.size()) {
            double m_median = m_small.top();
            return m_median;
        } else if (m_small.size() < m_large.size())  {
            // return negative large element since we inserted it as negative
            double m_median = (-1) * m_large.top();
            return m_median;
        } else {
            // we return the mean of both's top
            // we subtract the large element since we inserted it as negative
            double m_median = ((double)m_small.top() - (double)m_large.top()) / 2;
            return m_median;
        }
    }

private:
    std::priority_queue<int> m_large;
    std::priority_queue<int> m_small;
};

/**
 * MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */