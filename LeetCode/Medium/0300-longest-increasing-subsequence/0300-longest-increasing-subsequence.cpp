/*
Motivation: Segment Tree.
      First find the rank of every number by sorting and removing duplicates so we can use them as indices.
      Make a segment tree to store the max LIS for each rank.
      Loop over the ranks. In each step, query the tree for the max LIS of all numbers smaller than the current rank.
      Add 1 to it and update the tree with this new LIS.
      Keep track of the max LIS we find.
Complexity: 
    Time - O(n log n): Sorting takes n log n, and for every number we query and update the tree which is log n.
    Space - O(n): We save the unique values and the segment tree which takes 4 * n space.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.empty()) {
            return 0;
        }

        // build the segment tree
        SegmentTree st;
        vector<int> ranks = st.build(nums);

        int lis = 0;
        // loop over nums and update the segment tree otf
        for (size_t i = 0; i < ranks.size(); ++i) {

            // find lis of prev value
            int max_prev = 0;
            if (ranks[i] > 0) {
                // left 0 right rank - 1
                max_prev = st.query(0, ranks[i] - 1);
            }
            int curr_lis = max_prev + 1;

            // update rank with current lis
            st.update(ranks[i], curr_lis);

            // track max lis
            lis = max(lis, curr_lis);
        }

        return lis;
    }

    /* Segment Tree Class */
    class SegmentTree {
    public:
        SegmentTree() : m_n(0) {}
        
        /* build a segmentation tree from nums */
        vector<int> build(vector<int>& nums) {
            // represent nums as index from the soretd nums array
            vector<int> unique_vals = nums;
            sort(unique_vals.begin(), unique_vals.end());
            
            // remove duplicates
            unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
            size_t tree_size = unique_vals.size();

            // get the rank for each value
            vector<int> ranks(nums.size());
            for (int i = 0; i < nums.size(); ++i) {
                ranks[i] = lower_bound(unique_vals.begin(), unique_vals.end(), nums[i]) - unique_vals.begin();
            }

            m_n = unique_vals.size();
            m_st.assign(4 * m_n, 0);

            return ranks;
        }

        /* wrapper to update */
        void update(int idx, int val) {
            update(1, 0, m_n - 1, idx, val);
        }

        /* wrapper to query */
        int query(int l, int r) {
            return query(1, 0, m_n - 1, l, r);
        }

    
    private:
        /* update a number in the tree */
        void update(int node, int l, int r, int idx, int val) {
            // if its a leaf
            if (l == r) {
                m_st[node] = max(m_st[node], val);
            } else {
                int mid = l + (r - l) / 2;

                // update the corresponding child
                if (idx <= mid) {
                    update(2 * node, l, mid, idx, val);
                } else {
                    update(2 * node + 1, mid + 1, r, idx, val);
                }

                m_st[node] = max(m_st[2 * node], m_st[2 * node + 1]);
            }
        }

        /* tl, tr the current left and right, l,r the required */
        int query(int node, int tl, int tr, int l, int r) {
            // out of range
            if (r < tl || l > tr) {
                return 0;
            }
            
            // node contains the query
            if (l <= tl && r >= tr) {
                return m_st[node];
            }

            int tm = tl + (tr - tl) / 2;
            return max(query(2 * node, tl, tm, l, r), query(2 * node + 1, tm + 1, tr, l, r));
        }

    private:
        vector<int> m_st;
        int m_n;
    };
};
