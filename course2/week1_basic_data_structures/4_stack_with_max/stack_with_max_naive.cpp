#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<size_t> stack_main;
    vector<size_t> stack_aux;
    size_t max;

  public:

    void Push(size_t value) {
    	if(stack_main.empty()){
    		max = value;
        	stack_main.push_back(value);
        	stack_aux.push_back(value);
    	}
    	else{
    		if(max < value) max = value;
    		stack_main.push_back(value);
    		stack_aux.push_back(max);
    	}
    }

    void Pop() {
        //assert(stack_main.size());
        stack_main.pop_back();
        stack_aux.pop_back();
    }

    size_t Max(){
        //assert(stack_main.size());
        return *(stack_aux.end()-1);
    }
};

int main() {
    size_t num_queries = 0;
    cin >> num_queries;

    string query;
    size_t value;

    StackWithMax stack;
    StackWithMax aux;
    for (size_t i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(value);
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}