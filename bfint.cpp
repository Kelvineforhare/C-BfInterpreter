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

std::map<int,int> bfmain(std::vector<char> string,int i,int mp){
    if(mp == string.size() ){
        return memory;
    }
    switch (string[i])
    {
    case '>':
        ++mp;
        break;
    case '<':
        --mp;
        break;
    case '.':
        std::cout << read(mp);
        break;
    case ',':
        int x;
        std::cin >> x;
        write(mp,x);
        break;
    case '+':
        write(mp,read(mp)+1);
        break;
    case '-':
        write(mp,read(mp)-1);
        break;
    case '[':
        if(read(mp) == 0){
            //goes out of loop
        }
        break;
    case ']':
        //goes back to open bracket 
        break;

    bfmain(string,++i,mp);
    }
}

int main(){
    write(0,5);
    write(1,8);
    std::cout << "Ans: " <<read(1) << "\n";
    return 0;
}