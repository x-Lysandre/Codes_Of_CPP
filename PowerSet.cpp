#include<iostream>
#include<string>
#include<vector>
// Power set (all subset of a set {1,2,3})
using namespace std;

    void solution(string str,int i,string output,vector<string> &ans){

        //base case
        if(i>= str.length()){
            cout<<output<<endl;
            return;
        }

        //exclusion case
        solution(str,i+1,output,ans);

        //inclusion case
        char c = str[i];
        output.push_back(c);
        solution(str,i+1,output,ans);

    }


int main(){
    string str = "abc";
    int i =0;
    string output;
    vector<string> ans; 

    solution(str,i, output,ans);

    // for(int i=0;i<ans.size();i++)    {
    //     for(int j=0;j<ans[i].length;j++){

    //     }
    // }


}