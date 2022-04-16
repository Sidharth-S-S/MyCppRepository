#include <iostream>
using namespace std;
#include <climits>

void findLargest(int input[][100], int nRows, int mCols)
{
    int RowSum = INT_MIN , RowNum = 0 ,ColSum = INT_MIN , ColNum = 0;

    // Row Wise take the sum and then store
    for(int i = 0; i < nRows; i++){
        int tempsum = 0 ; 
        for(int j = 0; j < mCols ; j++){
            tempsum += input[i][j] ;
        }
        if ( tempsum > RowSum ) {
            RowSum = tempsum ;
            RowNum = i ;
        }
    }

    // Column Wise take the sum and then store
    for(int j = 0; j < mCols; j++){
        int tempsum = 0 ; 
        for(int i = 0; i < nRows ; i++){
            tempsum += input[i][j] ;
        }
        if ( tempsum > ColSum ) {
            ColSum = tempsum ;
            ColNum = j ;
        }
    }

    RowSum >= ColSum ? cout << "row " << RowNum << " " << RowSum << endl : cout << "column " << ColNum << " " << ColSum << endl ;

}

int main(){
    int myArray[100][100] , row , column , T;
    cin >> T ;

    while(T--){
        cin >> row >> column;

        for(int i = 0; i < row ; i++){
            for(int j = 0; j < column ; j++){
                cin >> myArray[i][j] ;
            }
        }
        findLargest(myArray, row , column ) ;
    }
}