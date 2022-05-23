#include <iostream>
using namespace std;

#include "cstring"
bool checksequenece(char large[] , char*small) {

    //s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
    //base case is
    if (strlen(small) == 0 && strlen(large) >= 0 ){
        return true;
    } else if (strlen(large) == 0) {
        return false;
    }

    if ( large[0] == small[0] ) {
        checksequenece(large+1,small+1);
    } else {
        checksequenece(large+1,small);
    }


}

int main() {
    char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";
}