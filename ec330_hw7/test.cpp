#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<vector<bool>> &graph, set<int> &visited, int curr_node, vector<int> &nodes_before){
    
    visited.insert(curr_node);
    nodes_before.push_back(curr_node);

    for(int i = 0; i < graph.size(); i++){
        
        if(graph[i][curr_node] && visited.find(i) == visited.end()){ //not yet visited
        
            dfs(graph, visited, i, nodes_before);
            
        }
    }
    return;
   
}

int main()
{
  vector<vector<bool>> graph = {{0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0}};
        
        set<int> visited = {};
        vector<int> nodes_before = {};
        vector<int> in_degree (graph.size(), 0);
        dfs(graph, visited, 8, nodes_before);

        for(auto &a: nodes_before){
            cout << a << " ";
        }
        cout << endl;

        sort(nodes_before.begin(), nodes_before.end());

         //find topological ordering 
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[0].size(); j++){
                if(graph[i][j]){
                    in_degree[j]++;
                }
            }
        
        }

         for(auto &p: in_degree){
            cout << p << " ";
        }
        cout << endl;

        vector<int> result = {};

        for(int i = 0; i < nodes_before.size(); i++){
            if(!in_degree[nodes_before[i]]){
                result.push_back(nodes_before[i]);
            }
        }

        for(auto &d: result){
            cout << d << " ";
        }
        cout << endl;

       return 0;


}