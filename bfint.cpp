#include <iostream>
#include <map>

std::map<int,int> memory;



int read(int mp){
    auto find = memory.find('c'); 
    if(find == memory.end()){
        return 0;
    }
    return find->second;
}

void write(int mp,int v){
    auto insert = memory.insert({mp,v});
    if(!insert.second){
        insert.first->second = v;
    }
}

void main(){
    std::cout << read(0);
}