#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> mergesort(std::vector<std::string> v);

int main(){

    std::vector<std::string> p = {"S", "E", "G"};
    mergesort(p);

    return 0;
}
// [38, 27, 43, 3, 9, 82, 10]
std::vector<std::string> mergesort(std::vector<std::string> v){
    //if even
    int mid = v.size() / 2;;
    

    std::cout << "mis is: " << mid << std::endl;
    std::vector<std::string> l (v.begin(), v.end() - mid-1);
    std::vector<std::string> r (v.begin() + mid, v.end());
    std::cout << "l is: " << std::endl;
    for(int i = 0; i < l.size(); i++){
        std::cout << l[i] << std::endl;
    }
    std::cout << "r is: " << std::endl;
    for(int i = 0; i < r.size(); i++){
        std::cout << r[i] << std::endl;
    }
    return v;
}