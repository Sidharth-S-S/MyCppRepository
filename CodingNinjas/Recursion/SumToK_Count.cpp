# include "iostream"
# include "cstring"

using namespace std;

int IsSubsetSUM_K(int input[], int size,int startIdx, int TargetSum,int count) {
    // Base Case
    if (startIdx == size){
        if ( TargetSum == 0 ){
            count++ ;
        }
        return count ;
    }

    // We have the option to either include the element or not include it 
    count = IsSubsetSUM_K ( input, size, startIdx+1, TargetSum, count) ; // Not include the element at input[startIdx]
    count = IsSubsetSUM_K ( input, size, startIdx+1 , TargetSum - input[startIdx], count) ;
    return count ;
}

// DRIVE MAIN FUNCTION
int main(){
    int input[20],length, TargetSum;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];

    cin >> TargetSum;

    // To print the output of counting the number of subsets
    cout << "Total number of subsets having sum "<< TargetSum << " = "<<IsSubsetSUM_K(input, length, 0, TargetSum, 0);
    return 0;
}