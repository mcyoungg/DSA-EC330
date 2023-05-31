
/*#algorithm (first implementation)
#find where array not sorted s1|s2 in ascending order

#in s2 check whether it is in ascending order 
    #if it is, insert the next smallest closest elemment of the element at the index right before the divider
    #sort the sub array in descending order 

#if subarray s2 in descending order, swap last two  


#how to find next closest smallest element 
    #traverse the subarray and where the next element is too great, then the i-1 elemment is the one i want 

if neither, check is n-1 < n, if so take n and insert after the divider

use is_sorted to check if sorted in ascending order
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> priorPerm(std::vector<int> P){
    //check where to place asc divider
    vector<int> res;
    res.assign(P.begin(), P.end());
    int div = 0;
    for (int i = 0; i < res.size()-1; i++) {
        if (res[i] > res[i + 1]) {
            div = i;
            break; 
        }
    }

    int descdiv = 0;
    for (int i = 0; i < res.size()-1; i++) {
        if (res[i] < res[i + 1]) {
            descdiv = i;
            break; 
        }
    }

    cout << "div is: " << div << endl;
    cout << "div2 is: " << descdiv << endl;
    
    auto const max_elem = max_element(P.begin(), P.end());
    auto const max = *max_elem;

    //is ascending after div?
    //cout <<"hey famm " << endl;
    bool is_ascend = true;
    for (int i = div+1; i < res.size()-1; i++) {
        if (res[i] > res[i + 1]) {
            is_ascend = false;
            break; 
        }
    }
    //cout <<"hey famm2 " << endl;
    //cout << "is_ascend: " << is_ascend << endl;
    //is descending after div?
    bool is_descend = true;
    for (int i = div+1; i < res.size()-1; i++) {
        if (res[i] < res[i + 1]) {
            is_descend = false;
            break;
        }
    }
    
    int ins = 0;
    int ins2 = 0;
    int ind = 0;
    //cout << "is_descend: " << is_descend << endl;
    //ascending order,
    
    if(is_ascend){
        if(res[div] == max){
            ins = res.size()-1;
        }
        else{
            for (int i = div+1; i < res.size(); i++) {
                if(res[i] > res[div]){
                    ins = i-1;
                    //cout << "ins is: " << ins << endl;
                    break;
                }
            }
        }
        res.insert(res.begin() + div, res[ins]);
        res.erase(res.begin() + (1 + ins));
        sort(res.begin() + (1 + div), res.end(), greater<int>());
    }
    //descending order, swap last two, n - 2 is always greater than n - 1
    else if(is_descend){
        swap(res[res.size()-2], res[res.size()-1]);
    }
    else{
        cout << "baby boy "<< endl;
        if(res[res.size()-2] > res[res.size()-2]){
            swap(res[res.size()-2], res[res.size()-1]);
        }
        else{
            sort(res.begin() + (1 + descdiv), res.end());
            for (int i = descdiv+1; i < res.size(); i++) {
                if(res[i] < res[div]){
                    ins2 = i-1;
                    cout << "ins2 is: " << ins2 << endl;
                    break;
                }
            }

        }
        res.insert(res.begin() + (1+ descdiv), res[ins2]);
        res.erase(res.begin() + (1 + ins2));
        sort(res.begin() + (1 + descdiv), res.end(), greater<int>());
    }
    return res;

}
int main(){
    
    vector<int> v = {4,3,1,2,5};
    //sort(v.begin() + 2, v.end(), greater<int>());
    //swap(v[v.size()-1], v[v.size()-2]);
    vector<int> res = priorPerm(v);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}




