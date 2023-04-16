
#include<iostream>
#include<string>
using namespace std;
class question{
	public:
		int LRS(string str){
		    int m = str.length(); // find string length
		    int t[1001][1001];  // to store the calculated values
		    
		    for(int i=0;i<m+1;i++)
		    for(int j=0;j<m+1;j++)
		     if(i==0 || j==0) // if length of string is 0 then lrs should be 0 too
		     t[i][j]=0;
		     
		    for(int i=1;i<m+1;i++)
		    for(int j=1;j<m+1;j++)
		    if(str[i-1] == str[j-1] && i!=j)  // lcs problem modified with condition
		    // if two subsequences should not have the same index then i cannot be equal to j
		    t[i][j] = 1+ t[i-1][j-1];
		    else
		    t[i][j] = max(t[i-1][j],t[i][j-1]);
		    
		    return t[m][m];
		}

    int main(){
        string str;
        cout<<"Enter string :";
        cin>>str;
        cout<<"Length of longest subsequence is "<<LRS(str);
    }
};