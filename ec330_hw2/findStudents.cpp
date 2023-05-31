#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

std::vector<int> findStudents(std::vector<int> id){
    map<int,int> mod;
    vector<int> res = {0, 0};
    vector<int> res2 = {0, 0};

    for(int i = 0; i < id.size(); i++){
        mod[id[i] % 330] = id[i];
    }

    auto l = mod.begin();
    auto r = mod.rbegin();
    int min = INT_MAX, sum = 0;
    
    while(distance(l, r.base()) > 1){    
        sum = (l -> first + r -> first);
        
        if(sum > 330){
            if(min > abs(330 - sum) ){
                min = abs(330 - sum);
                res[0] = l -> second;
                res[1] = r -> second;
            }
            r++;
        }
        else if(sum < 330){
            l++;
        }
        else{
            res[0] = l -> second;
            res[1] = r -> second;
            return res;
        }     
    }
    auto it2 = mod.begin();

    res2[0] = it2 -> second;
    res2[1] = (++it2) -> second;
    int smallsum = res2[0] + res2[1];
    
    if((res[0]+res[1]) % 330 < (smallsum) % 330){
        return res;
    }
    return res2;
}

// int main(){
//     vector<int> v1 = {1804, 9086, 5940, 4625};
//     vector<int> vout = findStudents(v1);
//     sort(v1.begin(), v1.end());
//     cout << endl;
//     for(int i = 0; i < vout.size(); i++){
//         cout << vout[i] << endl;
//     }
//     return 0;
// }
