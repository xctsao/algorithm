#include<iostream>

using namespace std;

void printResult();
void search(int );
bool check(int ,int );

int pos[8] = {0};
int count = 1;

int main(){
    search(0);

	return 0;
}

void search(int row){
    if(row == 8){
        cout << "No. " << count << endl;
        printResult();
        count++;
        return;
    }

    for(int i=0; i<8; i++){
        if(check(row, i)){
            search(row+1);
        }
    }
}

bool check(int row, int col){
    for(int i=0; i<row; i++){
        if(pos[i] == col || row-i == col-pos[i] || row-i == pos[i]-col)
        return false;
    }
    
    pos[row] = col;
    return true;
}

void printResult(){
    int result[8][8] = {0};

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(j != pos[i]){
                result[j][i] = 0;
                //cout << 0 << ' ';
            }
            else
                result[j][i] = 1;
                //cout << 1 << ' ';
        }

        //cout << endl;
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
