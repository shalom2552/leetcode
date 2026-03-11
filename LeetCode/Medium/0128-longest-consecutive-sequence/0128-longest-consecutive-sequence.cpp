/*
Motivation: Union Find.
      Make a custom UnionFind class that tracks the max size of a set.
      Loop over the array and make a set for every number.
      Loop over the array again, and if num + 1 exists, unite them.
      The result is the max size saved in the UnionFind class.
Complexity: 
    Time - O(n): Looping over the array twice and union find is almost O(1)
    Space - O(n): We save every number in the maps for parents and sizes
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty()) {
            return 0;
        }

        // use our implemented union find class
        UnionFind uf;

        // loop trough nums and make a set for every num
        for (int num : nums) {
            uf.make_set(num);
        }

        // loop trough nums again and unite every consecutive nums
        for (int num : nums) {
            // add the consecutive number
            if(uf.exist(num + 1)) {
                uf.unite(num, num + 1);
            }
        }
        
        return uf.get_max();
    }


    /* union find class */
    class UnionFind {
    public:
        UnionFind() = default;

        // make a set from element
        void make_set(int x) {
            // add x if it is not exist
            if (m_parent.find(x) == m_parent.end()) {
                m_parent[x] = x;
                m_size[x] = 1;
                m_max_size = max(m_max_size, 1);
            }
        }

        // find the root of x
        int find(int x) {
            // if x is not root
            if (m_parent[x] != x) {
                m_parent[x] = find(m_parent[x]);
            }
            return m_parent[x];
        }

        // unite the sets of x and y
        void unite(int x_, int y_) {
            int x = find(x_);
            int y = find(y_);

            // skip same set
            if (x == y) {
                return;
            }
            
            // add the smaller size set to the bigger set
            if (m_size[x] < m_size[y]) {
                m_size[y] += m_size[x];
                m_parent[x] = m_parent[y];
                m_max_size = max(m_max_size, m_size[y]);
            } else {
                m_size[x] += m_size[y];
                m_parent[y] = m_parent[x];
                m_max_size = max(m_max_size, m_size[x]);
            }
        }

        // return true if x is exist
        bool exist(int x) {
            return m_parent.find(x) != m_parent.end();
        }

        // return the max set
        int get_max() {
            return m_max_size;
        }

    private:
        unordered_map<int, int> m_parent;
        unordered_map<int, int> m_size;
        int m_max_size = 1;

    };
};