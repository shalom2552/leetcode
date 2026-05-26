/*
Motivation: BFS.
    Start from room 0 and add its keys to a queue.
    For each key in the queue, visit the room and add its keys.
    Skip already visited rooms. If all rooms are visited, return true.
Complexity: 
    Time - O(n + k): Visit each room once and process all keys.
    Space - O(n): Visited array and queue.
Where n is the number of rooms and k is the total number of keys.
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        std::vector<bool> visited(rooms.size(), false);
        std::queue<int> q;
        
        // visit room 0
        push_vec(q, rooms[0], visited);
        visited[0] = true;
        
        while (!q.empty()) {
            int key = q.front(); q.pop();
            
            // visit each room once
            if (visited[key]) {
                continue;
            }
            
            push_vec(q, rooms[key], visited);
            visited[key] = true;
        }
        
        return std::all_of(visited.begin(), visited.end(), [](bool visit) { return visit; });
    }

private:
    void push_vec(std::queue<int>& q, vector<int> const& vec, std::vector<bool> visited)
    {
        for (int key : vec) {
            if (!visited[key]) {
                q.push(key);
            }
        }
    }
};