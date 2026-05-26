"""
Motivation: DFS.
    Start from room 0 and visit all rooms recursively by keys.
    Skip already visted rooms.
Complexity: 
    Time - O(n + k): Visit each room and key once.
    Space - O(n): Visited array and recursion stack.
"""
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set()
        self.dfs(rooms, visited, 0)
        return len(visited) == len(rooms)

    def dfs(self, rooms, visited, idx):
        visited.add(idx)
        for key in rooms[idx]:
            if key not in visited:
                self.dfs(rooms, visited, key)
