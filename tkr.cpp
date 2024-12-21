#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// H�m BFS
void bfs(const unordered_map<char, vector<char>>& graph, char startVertex) {
    unordered_set<char> visited;
    queue<char> q;

    // Th�m d?nh b?t d?u v�o h�ng d?i
    visited.insert(startVertex);
    q.push(startVertex);

    cout << "BFS Traversal: ";

    // Duy?t BFS
    while (!q.empty()) {
        char vertex = q.front();
        q.pop();
        cout << vertex << " ";

        // Duy?t c�c d?nh k?
        for (char neighbor : graph.at(vertex)) { // D�ng at d? tr�nh l?i key kh�ng t?n t?i
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    // �? th? v� d?
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
