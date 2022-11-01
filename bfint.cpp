#include <iostream>
#include <vector>
#include <map>

std::map<int,int> memory;
//change to vector array



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
    while(stack.size() > 0 && i != string.size()){
        //std::cout << i << "\n";
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
    while(stack.size() > 0 && i >= 0){
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
    if(i == string.size() ){
        return memory;
    }
    //  for(auto it = memory.begin();
    //     it != memory.end(); ++it)
    // {
    // std::cout << it->first << " " << it->second << " " << "\n";
    // }
    //std::cout << "mp: " << mp << " " << "i: " << i << std::endl;
    switch (string[i])
    {
    case '>':
        ++mp;
        break;
    case '<':
        --mp;
        break;
    case '.':
        printf("%c", read(mp));
        //std::cout <<  ;
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
        //std::cout << read(mp) << "\n";
        if(read(mp) == 0){
            i = findClosingBracket(string,i)-1;
        }
        break;
    case ']':
        i = findOpeningBracket(string,i);
        //std::cout << i << std::endl;
        break;
    }
    bfmain(string,++i,mp);
    return memory;
}



std::vector<char> stringToVec(std::string str){
    std::vector<char> vec(str.begin(), str.end());
    return vec;
}

void run(std::string str){
    bfmain(stringToVec(str),0,0);
}

int main(){
    

    //std::cout << "Ans: " << findOpeningBracket(vec, 7)  << "\n";
    //auto insert = memory.insert({0,42});
    //run("""++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.""");
    //run("+++++[->++++++++++<]>--<+++[->>++++++++++<<]>>++<<----------[+>.>.<+<]");
    run("++++[>+++++<-]>[<+++++>-]+<+[>[>+>+<<-]++>>[<<+>>-]>>>[-]++>[-]+>>>+[[-]++++++>>>]<<<[[<++++++++<++>>-]+<.<[>----<-]<]<<[>>>>>[>>>[-]+++++++++<[>-<-]+++++++++>[-[<->-]+[<<<]]<[>+<-]>]<<-]<<-]");

    // for(auto it = memory.begin();
    //     it != memory.end(); ++it)
    // {
    // std::cout << it->first << " " << it->second << " " << "\n";
    // }
    return 0;
}