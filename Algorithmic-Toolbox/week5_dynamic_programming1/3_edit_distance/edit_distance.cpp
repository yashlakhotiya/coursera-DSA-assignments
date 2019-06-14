
#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
    int m = str1.length()+1;
    //std::cout<<m<<std::endl;
    int n = str2.length()+1;
    //std::cout<<n<<std::endl;
    int a[n][m];
    for(int i = 0; i < m;i++){
    	//std::cout<<"\ni: "<<i<<"\n";
        a[0][i] = i;
        //std::cout<<"a[0][" << i <<"] = "<<a[0][i]<<"\t";
    }
    
    /*std::cout<<"\n";
    std::cout<<"a[0][2] = "<<a[0][2]<<"\t";
    std::cout<<"\n";*/
    
    //std::cout<<"\n";
    for(int i = 0; i < n;i++){
        a[i][0] = i;
        /*std::cout<<"\n";
    std::cout<<"a[0][2] = "<<a[0][2]<<"\t";
    std::cout<<"\n";
        std::cout<<"a["<< i << "][0] = "<<a[i][0]<<"\t";*/
    }
    /*std::cout<<"\n";
    std::cout<<"a[0][2] = "<<a[0][2]<<"\t";
    std::cout<<"\n";*/
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout<<"a["<< i << "][" << j <<"] = "<<a[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"\n";*/
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(str2[i-1] == str1[j-1]){
            	a[i][j] = a[i-1][j-1];
            	//std::cout<<"a["<< i <<"][" << j <<"] = "<<a[i][j]<<"\t";
            	//std::cout<<"\n equal\n";
            }
            else{
                int temp = std::min(a[i-1][j-1],a[i][j-1]);
                a[i][j] = std::min(temp,a[i-1][j])+1;
                //std::cout<<"a["<< i << "][" << j <<"] = "<<a[i][j]<<"\t";
                //std::cout<<"\nnot equal\n";
            }
        }
    }
    //std::cout<<std::endl;
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout<<a[i][j]<<"\t";
        }
        std::cout<<"\n";
    }*/

    return a[n-1][m-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

