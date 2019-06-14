#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <utility>

using std::vector;
using std::endl;
using std::set;
using std::pair;

struct Segment {
  int start, end;
};

vector<int> optimal_points(set<pair<int,int>> &segments) {
  vector<int> points;
  //write your code here


  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].first);
    points.push_back(segments[i].second);
  }
  return points;
}

/*vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  return points;
}*/

int main() {
    int n;
    std::cin >> n;
    set<pair<int,int>> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].first >> segments[i].second;
    }vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  return points;
}
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
  /*int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }*/
}
