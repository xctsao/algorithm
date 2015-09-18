#include<iostream>

using namespace std;

void printResult();

int pos[8] = {0};
int count = 1;

int main(){



	cout << "No. " << count << endl;
	printResult();

	return 0;
}

//void search(int row){
//	if(row == 8){}
//}

void printResult(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(j != pos[i]){
				cout << 0 << ' ';
			}
			else
				cout << 1 << ' ';
		}

		cout << endl;
	}
}
