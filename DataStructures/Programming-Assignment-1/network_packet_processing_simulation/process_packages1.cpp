#include <iostream>
#include <queue>
#include <vector>



/*struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};*/

/*class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    Response Process(const Request &request) {
        // write your code here
    }
private:
    int size_;
    std::queue <int> finish_time_;
};*/

/*std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}*/

/*void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}*/

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}


int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();
	int t = 0;
    int t_curr = 0;
    int i = 0;
    std::vector<int> start_time(requests.size());
    std::queue<Request> buffer;
    while(i < requests.size()){
	    if(!buffer.empty()){
	    	if(t_curr == (*(requests.begin())).process_time){
	    		t_curr = 0;
	    		start_time[(buffer.front()).arrival_time] = t;
	    		buffer.pop();
	    	}
	    }

	    while(t == requests[i].arrival_time){
	    	if(buffer.size() < size){
	    		buffer.push(Request(i,requests[i].process_time));
	    		i++;
	    	}
	    	else{
	    		start_time[i] = -1;
	    		i++;
	    	}
	    }
	    t++;
	    if(t_curr < (*(requests.begin())).process_time){
	    	t_curr++;
	    }
	}
    
	for(int j = 0;j < start_time.size(); j++){
		std::cout<<start_time[i]<<"\n";
	}
    //PrintResponses(responses);
    return 0;
}
