#include "fun.h"

#include <iostream>
#include <tuple>
#include <map>
using namespace std;

unsigned int calcfun(unsigned int x, unsigned int y, map<tuple<int, int>, int> &t);

unsigned int fun(unsigned int x, unsigned int y) {
	map<tuple<int, int>, int> t;
    t[tuple<int, int>(0,0)] = 1;

    calcfun(x,y,t);
    return t[tuple<int, int>(x,y)];
}

unsigned int calcfun(unsigned int x, unsigned int y, map<tuple<int, int>, int> &t) {
    if(x == 0 and y == 0){
        return 1; //base case
    }

    //checking if we already computed subproblem
    tuple<int, int> p(x, y);
    if (!(t.find(p) == t.end())) {
        return t[p];
    }

    int result;
    if(x == 0 and y!= 0){
        result = calcfun(1, y - 1, t);
    } 
    else if(x!= 0 and y == 0){
        result = x + 1;
    }
    else{
        result = calcfun(x - 1, calcfun(x-1, y - 1, t), t);
    }
    t[p] = result;
    return result;
}

int main(){

    cout << "hi" << endl;
    return 0;
}
/* your helper function here if you have any */

