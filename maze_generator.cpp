#include "maze_generator.h"
#include <algorithm>
std::vector<int> range(int begin, int end){
    if(end <0){
        end = begin;
        begin = 0;
    }
    std::vector<int> ret(end-begin);
    int cpt=0;
    std::generate(ret.begin(),std::end(ret),[&cpt](){
        return cpt++;
    });
    return ret;
}

