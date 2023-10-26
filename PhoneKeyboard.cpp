#include "std_lib_facilities.h"
using namespace std;
void solution(string digits,int i,string output){

    string mapping[10] = {"", "","abc","def","ghi","klm","nop","qrs","tuv","wxyz"};

    //base case
    if(i>=digits.length()){
        cout<<output<<" ";
        return;
    }

    //converting the digits which is in string to int
    int number = digits[i] -'0';
    string value = mapping[number];

    //recursive 
    for(int j=0;j<value.length();j++){
        output.push_back(value[j]);
        solution(digits,i+1,output);
        output.pop_back();
    }
}

int main(){

    string digits;
    cin>>digits;

    string output;


    solution(digits,0,output);
    return 0;
}