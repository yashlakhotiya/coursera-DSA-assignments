#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(char type, size_t position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    size_t position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    size_t count = 1;

    std::stack <Bracket> opening_brackets_stack;
    Bracket *init = new Bracket('#',0);
    opening_brackets_stack.push(*init);
    //size_t position;
    size_t pos;
    for (pos = 0; pos < text.length(); pos++) {
        char next = text[pos];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket *temp = new Bracket(next,count);
            opening_brackets_stack.push(*temp);
        }

        else if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.top().Matchc(next)) opening_brackets_stack.pop();
            else break;
        }
        count++;
    }

    // Printing answer, write your code here
    if(pos == text.size() && opening_brackets_stack.size() == 1){
    	cout<<"Success";
    }
    else if(pos == text.size() && opening_brackets_stack.size() != 1){
    	while(opening_brackets_stack.size() != 2){
    		opening_brackets_stack.pop();
    	}
    	cout<<opening_brackets_stack.top().position;
    }
    else if(pos != text.size() && opening_brackets_stack.size() == 1){
    	cout<<count;
    }
    else{
    	cout<<count;
    }
    return 0;
}
