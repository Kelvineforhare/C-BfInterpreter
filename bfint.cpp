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

int findClosingBracket(std::vector<char> string,int i){
    std::vector<char> stack;
    stack.push_back(string[i]);
    ++i;
    while(stack.size() > 0){
        switch (string[i])
        {
            case '[':
                stack.push_back(string[i]);
                break;
            case ']':
                stack.pop_back();
                break;
        }
        ++i;
    } 
    return i;
}

int findOpeningBracket(std::vector<char> string,int i){
    std::vector<char> stack;
    stack.push_back(string[i]);
    --i;
    while(stack.size() > 0){
        switch (string[i])
        {
            case '[':
                stack.pop_back();
                break;
            case ']':
                stack.push_back(string[i]);
                break;
        }
        --i;
    } 
    return i;
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
            i = findClosingBracket(string,i)-1;
        }
        break;
    case ']':
        i = findOpeningBracket(string,i)+1;
        break;

    bfmain(string,++i,mp);
    }
}

int main(){
    // write(0,5);
    // write(1,8);
    std::vector<char> bracket{'[','[',']',']'};
    //findClosingBracket("--[..+>--],>,++",2) ; 
    std::cout << "Ans: " << findOpeningBracket(bracket,3) << "\n";
    return 0;
}