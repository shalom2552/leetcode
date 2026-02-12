/*
 * Motivation: Two pointers, read and write.
 *      w'ell use two pointers to iterate over the list from left to right,
 *      in each iteration we we write to the left pointer and
 *      read from the right, if we see the val, we dont write.
 * Complexity: 
 *      Time - O(n): Iterating over the list once.
 *      Space - O(1): no use of extra space.
 * Where n is the number of elements in the list.
*/
int removeElement(int* nums, int numsSize, int val) {

    // initialize the pointers to the start
    int* write = nums;
    int* read = nums;

    // iterate over the list once
    while (read < nums + numsSize) {
        // if the current value is not the target
        if (*read != val) {
            // move the current value to the write index
            *write = *read;
            write++;
        }
        // keep read anyway
        read++;
    }

    // retuurn pointer to the start of the list
    return write - nums;
}