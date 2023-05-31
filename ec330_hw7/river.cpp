#include "river.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // you are allowed to use std::sort from this library


using namespace std;

//reverse dfs 
void dfs(river graph, set<int> &visited, int curr_node, vector<int> &nodes_before){
    
    visited.insert(curr_node);
    nodes_before.push_back(curr_node);

    for(int i = 0; i < graph.size(); i++){
        
        if(graph[i][curr_node] && visited.find(i) == visited.end()){ //not yet visited, check if 1, then there is an edge from i to j
        
            dfs(graph, visited, i, nodes_before);
            
        }
    }
    return;
   
}

// part (a)
std::vector<int> start(river const&r, int t) {

	set<int> visited = {};
    vector<int> nodes_before = {};

    vector<int> in_degree (r.size(), 0);
	vector<int> result = {};

	//find all nodes that come the target node
    dfs(r, visited, t, nodes_before);
    sort(nodes_before.begin(), nodes_before.end());

	//find topological ordering 
	for(int i = 0; i < r.size(); i++){
		for(int j = 0; j < r[0].size(); j++){
			if(r[i][j]){
				in_degree[j]++;
			}
		}
	
	}
	//of the nodes that come before the target, check its "in degree"
	for(int i = 0; i < nodes_before.size(); i++){
		if(!in_degree[nodes_before[i]]){
			result.push_back(nodes_before[i]);
		}
	}

	return result; 
}

// part (b)
std::vector<int> meet(river const&r, int ryan, int mira) {

	// your implementation here

	return {}; // don't forget to change this
}