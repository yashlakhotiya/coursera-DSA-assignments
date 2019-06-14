#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value_mine(long capacity, vector<long> weights, vector<long> values) {
  double value = 0.0;
  long w = capacity;
  vector<double> vpw(weights.size());
  for(int i = 0; i < weights.size();i++){
    vpw[i] = (double)values[i]/weights[i];
  }
    auto it2 = vpw.begin();
  while(w!=0 && vpw.size() != 0){
    auto it1 = max_element(vpw.begin(),vpw.end());
    int index = it1-it2;
    if(weights[index] <= w){
        //std::cout<<"\nweight before erase "<<w;
        w = w-weights[index];
        //std::cout<<"\nweight after erase "<<w<<"\n";
        value += values[index];
    }
    else{
        value += vpw[index] * (w);
        w = 0;
    }
    //std::cout<<"\nsizde before erase "<<vpw.size();
    vpw.erase(vpw.begin()+index);
    weights.erase(weights.begin()+index);
    values.erase(values.begin()+index);
    //std::cout<<"\nsizde after erase "<<vpw.size()<<"\n";
  }

  return value;
}

int main() {
       /* vector<long> values;
        vector<long> weights;
    vector<double> vpw;
    std::cout.precision(10);
    while(true){
            for(int i = 0; i < weights.size();i++){
                vpw[i] = (double)values[i]/weights[i];
                std::cout<<"vpw: "<<vpw[i];
            }
            std::cout<<"\n";
        int n = (rand() % 1000)+1;
        long capacity = rand() % 1000000;
        std::cout<<"\ncapacity: "<<capacity<<"\n";
        std::cout<<n<<"\n";
        for (int i = 0; i < n; i++) {
            values.push_back(rand()%1000000);
            weights.push_back(rand()%1000000+1);
        }
        std::cout<<"\n";
        std::cout<<"values: \n";
        for (int i = 0; i < n; i++) {
            std::cout<<values[i]<<"\t";
        }
        std::cout<<"\n";
        std::cout<<"weights: \n";
        for (int i = 0; i < n; i++) {
            std::cout<<weights[i]<<"\t";
        }
        std::cout<<"\n";
        double res_mine = get_optimal_value_mine(capacity,weights,values);
        double res_stress = get_optimal_value_stress(capacity,weights,values);
        std::cout<<"\nres mine: "<<res_mine;
        std::cout<<"\nres stress: "<<res_stress;
        if(res_mine != res_stress){
            std::cout<<"\nwrong answer\n";
            break;
        }
        else std::cout<<"\nOK\n";
    }*/
  int n;
  long capacity;
  std::cin >> n >> capacity;
  vector<long> values(n);
  vector<long> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
std::cout.precision(10);
  double optimal_value = get_optimal_value_mine(capacity, weights, values);

  std::cout << optimal_value << std::endl;
  return 0;
}
