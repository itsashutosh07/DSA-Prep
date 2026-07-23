
#include <bits/stdc++.h>
#include "../dgb.hpp"

using namespace std;

struct ListNode;
struct TreeNode;

// Creation DATE: January 03, 2026
// Creation TIME: 07:40:21

/* Written  By: 
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄─▄█─▄─▄─█─▄▄▄██▀▄─██─▄▄▄█─██─█─██─█─▄─▄─█─▄▄─█─▄▄▄█─██─█▀▄▄▀█▄▄▄░█
██─████─███▄▄▄─██─▀─██▄▄▄─█─▄▄─█─██─███─███─██─█▄▄▄─█─▄▄─█─██─███░██
█▄▄▄██▄▄▄██▄▄▄▄█▄▄█▄▄█▄▄▄▄█▄██▄█▄▄▄▄██▄▄▄██▄▄▄▄█▄▄▄▄█▄██▄██▄▄███▄███
*/

// Question:- Dijkstra (Char Graph)

/*
DESCRIPTION :
    Find shortest distance from source vertex to all vertices
    Graph is represented using adjacency list with char vertices
*/


class Solution {
    public:
    unordered_map<char, int> dijkstra(char start, unordered_map<char, vector<pair<char, int>>>& graph) {
        /* Input:
            char start --> start node
            unordered_map<char, vector<pair<char, int>>>& graph --> {fromNode : <toNode, weight>}
        */
        unordered_map<char, int> dist;

        // Step 1: Initialise the distances to INF
        for (auto node : graph) {
            dist[node.first] = INT_MAX;
        }

        if (graph.find(start) == graph.end()) {
            return dist;
        }


        // pq <element type, container, comparator>
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(int i = 0; i < graph[node].size(); i++) {
                char neighbor = graph[node][i].first;
                int weight = graph[node][i].second;
                
                int neighborDist = currDist + weight;
                
                if (neighborDist < dist[neighbor]) {
                    dist[neighbor] = neighborDist;
                    pq.push({neighborDist, neighbor});
                }
            }
        }

        return dist;
    }
};


int main() {
    Solution sol;

    auto printResult = [&](const string& title, char start, unordered_map<char, vector<pair<char,int>>>& graph) {
        cout << "\n==============================\n";
        cout << title << "\n";
        cout << "Start Node: " << start << "\n";
        cout << "------------------------------\n";

        auto res = sol.dijkstra(start, graph);
        map<char,int> ordered(res.begin(), res.end()); // ordered output

        for (auto& [node, dist] : ordered) {
            if (dist == INT_MAX)
                cout << node << " -> INF\n";
            else
                cout << node << " -> " << dist << "\n";
        }
    };

    // =========================
    // DIRECTED GRAPH TESTS
    // =========================

    unordered_map<char, vector<pair<char,int>>> dg1 = {
        {'A', {{'B', 1}, {'C', 4}}},
        {'B', {{'C', 2}, {'D', 5}}},
        {'C', {{'D', 1}}},
        {'D', {}}
    };
    printResult("Directed Test 1: Simple DAG", 'A', dg1);

    unordered_map<char, vector<pair<char,int>>> dg2 = {
        {'A', {{'B', 2}}},
        {'B', {{'C', 2}}},
        {'C', {{'A', 2}, {'D', 1}}},
        {'D', {}}
    };
    printResult("Directed Test 2: Cycle", 'A', dg2);

    unordered_map<char, vector<pair<char,int>>> dg3 = {
        {'A', {{'B', 3}}},
        {'B', {}},
        {'C', {{'D', 1}}},
        {'D', {}}
    };
    printResult("Directed Test 3: Disconnected Graph", 'A', dg3);

    unordered_map<char, vector<pair<char,int>>> dg4 = {
        {'A', {{'B', 5}}},
        {'B', {}}
    };
    printResult("Directed Test 4: One-way Reachability", 'B', dg4);

    // =========================
    // UNDIRECTED GRAPH TESTS
    // =========================

    unordered_map<char, vector<pair<char,int>>> ug1 = {
        {'A', {{'B', 2}}},
        {'B', {{'A', 2}, {'C', 3}}},
        {'C', {{'B', 3}, {'D', 1}}},
        {'D', {{'C', 1}}}
    };
    printResult("Undirected Test 1: Simple Chain", 'A', ug1);

    unordered_map<char, vector<pair<char,int>>> ug2 = {
        {'A', {{'B', 10}, {'C', 3}}},
        {'B', {{'A', 10}, {'C', 1}, {'D', 2}}},
        {'C', {{'A', 3}, {'B', 1}, {'D', 8}}},
        {'D', {{'B', 2}, {'C', 8}}}
    };
    printResult("Undirected Test 2: Multiple Paths", 'A', ug2);

    unordered_map<char, vector<pair<char,int>>> ug3 = {
        {'A', {{'B', 1}, {'C', 4}}},
        {'B', {{'A', 1}, {'C', 2}}},
        {'C', {{'A', 4}, {'B', 2}}}
    };
    printResult("Undirected Test 3: Cycle", 'A', ug3);

    unordered_map<char, vector<pair<char,int>>> ug4 = {
        {'A', {}}
    };
    printResult("Undirected Test 4: Single Node", 'A', ug4);

    // =========================
    // EDGE / TRICK CASES
    // =========================

    unordered_map<char, vector<pair<char,int>>> eg1 = {
        {'A', {{'B', 1}}},
        {'B', {{'A', 1}}}
    };
    printResult("Edge Case 1: Start Node Missing", 'Z', eg1);

    unordered_map<char, vector<pair<char,int>>> eg2 = {
        {'A', {{'B', 0}}},
        {'B', {{'A', 0}, {'C', 2}}},
        {'C', {}}
    };
    printResult("Edge Case 2: Zero-weight Edges", 'A', eg2);

    return 0;
}
/*
SOLUTIONS:-

1. TC: O(V^2) | SC: O(V) | Without PQ
2. TC: O(E log V) | SC: O(V + E) | With PQ (USED)
*/