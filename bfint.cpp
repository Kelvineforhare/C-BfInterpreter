#include <iostream>
#include <vector>
#include <map>

std::map<int,int> memory;



int read(int mp){
    auto find = memory.find(mp); 
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

std::map<int,int> bfmain(std::vector<char> string){
    if(string.size() == 0){
        return memory;
    }
    switch (string[0])
    {
    case '+':
        
        break;
    
    default:
        break;
    }
    //switch()
}

int main(){
    write(0,5);
    write(1,8);
    std::cout << "Ans: " <<read(1) << "\n";
    return 0;
}