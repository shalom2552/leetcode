
/*
Motivation: w'ell use a min heap to store all element,
     then we'll extract them to get the sorted list.
     we'll use the priority queue with modified comperator.
Complexity: 
     Time - O(n*log(n)): n times poping from heap, log(n) each.
     Space - O(n): the min_heap and result list.
Where n is the number of elements in all lists combined.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    // min heap to store all values initially
    std::priority_queue<int> min_heap;
    
    // push all values into the min heap
    for (ListNode*& list : lists) {
            
        // list is empty
        if (list == nullptr) {
            continue;
        }

        // travers all elements in the list
        while (list != nullptr) {

            // push the negative value for min order
            min_heap.push( (-1) * list->val );
            list = list->next;
        }
    }

    // use a dummy node to keep pointer to root
    ListNode dummy;
    ListNode* cur = &dummy;

    // insert all elements from heap to the list
    while (! min_heap.empty() ) {

        // we stored the values as negative
        int val = (-1) * min_heap.top();
        cur->next = new ListNode(val);
        cur = cur->next;
        min_heap.pop();
    }
  
    // results is a dummy node
    // if no elements where found, dummy.next is nullptr
    return dummy.next;        
}

};