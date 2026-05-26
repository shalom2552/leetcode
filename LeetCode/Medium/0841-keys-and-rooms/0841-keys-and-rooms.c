/*
Motivation: DFS.
    Start from room 0 and visit all rooms recursively by keys.
    Skip already visted rooms.
Complexity: 
    Time - O(n + k): Visit each room and key once.
    Space - O(n): Visited array and recursion stack.
*/
void dfs(int** rooms, int roomsSize, int* roomsColSize, bool* visited, int idx)
{
    visited[idx] = true;

    // visit all rooms
    for (int j = 0; j < roomsColSize[idx]; ++j) {
        int key = rooms[idx][j];

        // skip visited
        if (!visited[key]) {
            dfs(rooms, roomsSize, roomsColSize, visited, key);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    dfs(rooms, roomsSize, roomsColSize, visited, 0);
    
    // check if all rooms visited
    bool all_visited = true;
    for (int i = 0; i < roomsSize; ++i) {

        if (!visited[i]) {
            all_visited = false;
            break;
        }

    }

    free(visited);
    return all_visited;
}
