#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
     long long n;
  vector<long long> data_;
  vector< pair<long long, long long> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (long long i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    cin >> n;
    data_.resize(n);
    for(long long i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void shiftDown(long long i){
  	long long minIndex = i;
  	  	//	cout<<minIndex<<"\n";

  	//if(i >= n) return;
  	long long l = 2*i+1;
  	if(l < n && data_[minIndex] > data_[l]) minIndex = l;
  	long long r = 2*i+2;
  	if(r < n && data_[minIndex] > data_[r]) minIndex = r;
  	if(i != minIndex){
  		pair<long long,long long> p = make_pair(i,minIndex);
  		swaps_.push_back(p);
  		long long temp = data_[i];
  		data_[i] = data_[minIndex];
  		data_[minIndex] = temp;
  		shiftDown(minIndex);
  	}
  }

  void GenerateSwaps() {
    swaps_.clear();
    for(long long i = (n-1)/2; i>=0;i--){
        shiftDown(i);
    }
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array long longo a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*for (long long i = 0; i < data_.size(); ++i)
      for (long long j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }*/
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
