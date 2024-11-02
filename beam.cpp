#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

// Function to perform beam search
void beamSearch(map<char, map<char, int>> graph, char start, char goal, int beamWidth, map<char, int>& heuristics) {
    // Priority queue to hold paths with cumulative cost and their respective nodes
    priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>, greater<pair<int, vector<char>>>> currentLevel;
    currentLevel.push({heuristics[start], {start}});  // Start path with heuristic value
    
    while (!currentLevel.empty()) {
        // Use a temporary container to hold all paths at the current level
        vector<pair<int, vector<char>>> nextLevel;
        
        // Process each path in the current level
        while (!currentLevel.empty()) {
            int currentCost = currentLevel.top().first;
            vector<char> currentPath = currentLevel.top().second;
            currentLevel.pop();
            
            // Get the current node (last node in the path)
            char currentNode = currentPath.back();
            cout << "Current path: ";
            for (char node : currentPath) cout << node << " ";
            cout << "| Cost: " << currentCost << endl;

            // Check if goal is reached
            if (currentNode == goal) {
                cout << "Path found: ";
                for (char node : currentPath) cout << node << " ";
                cout << "| Cost: " << currentCost << endl;
                return;
            }

            // Explore neighbors of the current node
            cout << "Processing node: " << currentNode << endl;
            for (auto neighbor : graph[currentNode]) {
                char nextNode = neighbor.first;
                int edgeCost = neighbor.second;

                // Avoid revisiting nodes in the current path
                if (find(currentPath.begin(), currentPath.end(), nextNode) == currentPath.end()) {
                    // Create a new path and calculate its cost
                    vector<char> newPath = currentPath;
                    newPath.push_back(nextNode);
                    int newCost = currentCost + edgeCost + heuristics[nextNode];

                    // Add the new path to the next level
                    nextLevel.push_back({newCost, newPath});
                    cout << "Adding path to next level: ";
                    for (char node : newPath) cout << node << " ";
                    cout << "| New Cost: " << newCost << endl;
                }
            }
        }

        // Sort all paths at this level by cost and keep only the best `beamWidth` paths
        sort(nextLevel.begin(), nextLevel.end());
        
        currentLevel = priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>, greater<pair<int, vector<char>>>>();

        for (int i = 0; i < min(beamWidth, (int)nextLevel.size()); i++) {
          cout<<"Pushing into queue"<<nextLevel[i].first<<endl;
            currentLevel.push(nextLevel[i]);
        }
    }

    // If no path to the goal was found
    cout << "No path found to the goal." << endl;
}

int main() {
    // Define the graph as adjacency lists with edge costs
     map<char, map<char, int>> graph = {
        {'S', {{'A', 3}, {'B', 5}}},
        {'A', {{'S', 3}, {'B', 4}, {'D', 3}}},
        {'B', {{'S', 5}, {'A', 4}, {'C', 4}}},
        {'C', {{'B', 4}, {'E', 6}}},
        {'D', {{'A', 3}, {'G', 5}}},
        {'E', {{'C', 6}}},
        {'G', {{'D', 5}}}
    };
    // Define heuristic values for each node to the goal 'G'
    map<char, int> heuristics;
    heuristics['S'] = 10;
    heuristics['A'] = 90;
    heuristics['B'] = 8;
    heuristics['C'] = 7;
    heuristics['D'] = 6;
    heuristics['E'] = 5;
    heuristics['G'] = 0;

    // Beam search with a beam width of 2
    beamSearch(graph, 'S', 'G', 1, heuristics);

    return 0;  
}
