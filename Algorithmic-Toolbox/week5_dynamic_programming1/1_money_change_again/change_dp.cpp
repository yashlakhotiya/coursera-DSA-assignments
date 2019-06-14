#include <iostream>
#include <algorithm>

long long get_change(long long m) {
	long long den[3][m+1] = {0};
	long long coin[4] = {1,3,4};
	for(long long i = 0;i <= m;i++){
		den[0][i] = i;
	}
	for(long long i = 1;i <=2;i++){
		for(long long j = 0;j <= m;j++){
			if(j < coin[i]){
				den[i][j] = den[i-1][j];
			}
			else{
				den[i][j] = std::min(den[i-1][j],den[i][j-coin[i]]+1);
			}
		}
	}
 	/*for(long long i = 0;i <4;i++){
 		for(long long j = 0;j <=m;j++){
 			std::cout<<den[i][j]<<"\t";
 		}
 		std::cout<<std::endl;
 	}*/
 	return den[2][m];
}

int main() {
	long long m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
	return 0;
}
