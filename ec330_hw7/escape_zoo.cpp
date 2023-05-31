#include "escape_zoo.h"
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>


using namespace std;

// void print_matrix(const vector<vector<bool>>& matrix, vector<pair<int, int>> s, int x, int y) {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     // for (const auto& p : s)
//     // {
//     // std::cout << p.first << ", " << p.second << std::endl;
//     // // or std::cout << std::get<0>(p) << ", " << std::get<1>(p) << std::endl;
//     // }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if(find(s.begin(), s.end(), pair<int, int> {i, j}) != s.end()){
//               if(i == 10 && j == 10){
//                     cout << "~" << " ";
//                 }
//                 else if( i == x && j == y){
//                     cout << "h" << " ";
//                 }
//                 else{
//                     cout << "*" << " ";
//                 }
               
//             }
//             else{
//                  cout << matrix[i][j] << " ";
//             }
            
           
//         }
//         cout << endl;
//     }
// }

motion_plan escape_route(grid const &M, coordinate init_coordinate, Heading init_heading) {
    
    map<Heading, vector<pair<pair<int, int>, Action>>> locations;

    locations[North].push_back({{-1, 0}, go_straight});
    locations[North].push_back({{0, -1}, go_left});
    
    locations[South].push_back({{1, 0}, go_straight});
    locations[South].push_back({{0, 1}, go_left});

    locations[East].push_back({{0, 1}, go_straight});
    locations[East].push_back({{-1, 0} , go_left});
    
    locations[West].push_back({{0, -1}, go_straight});
    locations[West].push_back({{1, 0} , go_left});
    

    map<pair<int, int>, Heading> mapping;

    mapping[{-1, 0}] = North;
    mapping[{1, 0}] = South;
    mapping[{0, 1}] = East;
    mapping[{0, -1}] = West;

    Heading curr_heading = init_heading;
    Heading next_heading;

    queue<pair<pair<pair<pair<int, int>, motion_plan>, Heading > , vector<pair<int, int>>>> q;

    vector<pair<int, int>> debug = {{init_coordinate.first, init_coordinate.second}};

    motion_plan plan = {};
    q.push({{{{init_coordinate.first, init_coordinate.second}, plan}, curr_heading}, debug});

    pair<int, int> coord = {};
    pair<int, int> w = {};

    int x_coord = 0;
    int y_coord = 0;

    int next_cell_x = 0;
    int next_cell_y = 0;

    set<pair<pair<int, int>, Heading>> visited = {{{init_coordinate.first, init_coordinate.second}, curr_heading}};


    while(!q.empty()){

        coord = q.front().first.first.first;
        x_coord = coord.first; //get current x coordinate 
        y_coord = coord.second; //get current y coordiante 

        plan = q.front().first.first.second;

        curr_heading = q.front().first.second; //get current heading direction 
        
        //std::cout << curr_heading << endl;

        debug = q.front().second;

        q.pop();

        for(auto &neighbor: locations[curr_heading]){
           
            w = neighbor.first; //get the locations of both going striaght and going left 

            next_cell_x = w.first + x_coord; 
            next_cell_y = w.second + y_coord;
            
            next_heading = mapping[{w.first, w.second}]; //get next heading for processing

            if(next_cell_x >= 0 && next_cell_y >= 0 && next_cell_x < M.size() && next_cell_y < M[0].size() &&
               M[next_cell_x][next_cell_y] == 0 && (visited.find({{next_cell_x, next_cell_y}, next_heading}) == visited.end())){


                //std::cout << "(" << w.first << ", " << w.second<< ")" << std::endl; //printing direction

                motion_plan temp = plan;
                temp.push_back(neighbor.second);

                vector<pair<int, int>> dd = debug;
                dd.push_back({next_cell_x, next_cell_y});
                
                q.push({{{{next_cell_x, next_cell_y}, temp}, next_heading}, dd});
                
                //cout << "size: " << temp.size() << endl;

                //  for(auto & pp: temp){
                //     cout << pp << " ";
                // }

                //std::cout << "(" << next_cell_x << ", " << next_cell_y<< ")" << " " << next_heading << " " << neighbor.second << std::endl;
                visited.insert({{next_cell_x, next_cell_y}, next_heading});
                //std::cout<<endl;
                //print_matrix(M, dd, next_cell_x, next_cell_y);
                //std::cout<<endl;

                if(next_cell_x == 0 || next_cell_y == 0 || next_cell_x == M.size() - 1 || next_cell_y == M[0].size() - 1){
            
                    return temp;
                }

            
            }

            

        }
    
    }
    return {};
}
// int main(){

//     //grid input = {{1,1,1,1,},{0,0,0,0,},{1,0,0,1,},{1,1,0,1,}};
//     grid input = {{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,},{1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,},{1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},{1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,},{1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},{1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,},{1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,},{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,},{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,}};
//     Heading h = South;
//     coordinate c = {10,10};
//     //coordinate c = {2,2};



//     motion_plan p = escape_route(input, c, h);

//     // for(auto & pp: p){
//     //     cout << pp << " ";
//     // }
//     // cout << endl;

//     return 0;
// }