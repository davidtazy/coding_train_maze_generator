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

#include <ctime>
int random(int max){
    static bool call_once = true;
    if(call_once){
        std::srand(std::time(nullptr));
        call_once = false;
    }
    return std::rand()/((RAND_MAX + 1u)/max);
}
