#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ctime>

using namespace std;

int main(){
	unsigned int start_time =  clock();
	unsigned int N, M, k;
	unsigned long long count = 0;
	int insert[3];
	int z = 0;

	cin >> N >> M >> k;
	
	int start = clock();

	vector <vector<int>> trains (k, vector<int>(3));
	multimap <int, int> pointC1;
	multimap <int, int> pointC2;
	vector <bool> samePoints(M, false);
	
	for (int i = 0; i < k; i++){
		for(int l = 0; l < 3; l++){
		cin >> insert[l];
		}
		pointC1.insert(pair< int, int >(insert[0], insert[1]));
		pointC2.insert(pair< int, int >(insert[0], insert[2]));
	}
	cout << endl;
	
	for (auto it1 = pointC1.begin(); it1 != pointC1.end(); ++it1){
	  trains[z][0] = it1 -> first;
	  trains[z][1] = it1 -> second;
	  z++;
  }
	cout << endl;

	z = 0;

	for (auto it2 = pointC2.begin(); it2 != pointC2.end(); ++it2){
	  trains[z][2] = it2 -> second;
	  z++;
  }
	cout << endl;

	/*for (int i = 0; i < k; i++){
		for(int j = 0; j < 3; j++){
			cout << trains[i][j] << " ";
		}
		cout << endl;
	}*/

	set <int> reserved;
	cout << reserved.max_size() << endl;
	cout << samePoints.max_size() << endl;

	/*for(int j = trains[0][1] - 1; j < trains[0][2]; j++)
			reserved.insert(j);
	
	if((k > 1)){
		for(int i = 1; i < k; i++){
			if (trains[i][0] == trains[i-1][0]){
				for(int j = trains[i][1] - 1; j < trains[i][2]; j++)
					reserved.insert(j);
				if(i == k - 1)
					count += reserved.size();
				}
				
			else {
				count += reserved.size();
				reserved.clear();
				for(int j = trains[i][1] - 1; j < trains[i][2]; j++){
					reserved.insert(j);
					}
				if(i == k - 1)
					count += reserved.size();
			}
		}		
	}
	else{
		count += reserved.size();
	}*/

	for(int j = trains[0][1] - 1; j < trains[0][2]; j++){
		samePoints[j] = true;
		++count;
	}

	if(k > 1){
		for(int i = 1; i < k; i++){
			if (trains[i][0] == trains[i-1][0]){
				for(int j = trains[i][1] - 1; j < trains[i][2]; j++){
					if (samePoints[j] != true){
						samePoints[j] = true;
							++count; 
					}
				}
			}
				
			else {
				for(int j = 0; j < M; j++){
					samePoints[j] = false;
				}
				for(int j = trains[i][1] - 1; j < trains[i][2]; j++){
					if (samePoints[j] != true){
						samePoints[j] = true;
						++count; 
					}
				}
			}		
		}
	}

	cout << endl;
	//cout << "N= " << N << endl;
	//cout << "M= " << M << endl;
	unsigned long long number = static_cast <unsigned long long> (N) * M - count;
	cout << "Number of free cells: " << number << endl;
	cout << endl;
	int finish = clock(); 
	float runtime = (float)(finish - start) / CLOCKS_PER_SEC;
	cout << "runtime = " << runtime << " sec" << endl;
	cout << "runtime = " << runtime / 60 << " min" << endl;
	
	return 0;
}