#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Hàm BFS
void bfs(const unordered_map<char, vector<char>>& graph, char startVertex) {
    unordered_set<char> visited;
    queue<char> q;

    // Thêm d?nh b?t d?u vào hàng d?i
    visited.insert(startVertex);
    q.push(startVertex);

    cout << "BFS Traversal: ";

    // Duy?t BFS
    while (!q.empty()) {
        char vertex = q.front();
        q.pop();
        cout << vertex << " ";

        // Duy?t các d?nh k?
        for (char neighbor : graph.at(vertex)) { // Dùng at d? tránh l?i key không t?n t?i
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    // Ð? th? ví d?
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {}},
        {'F', {}}
    };

    // Th?c hi?n BFS
    bfs(graph, 'A');

    return 0;
}
