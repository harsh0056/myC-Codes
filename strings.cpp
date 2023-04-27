#include<bits/stdc++.h>
using namespace std;


bool checkIfSubs(string s1,string s2){
    int n=s1.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(s1[i]==s2[j])j++;
    }
    return j==s2.size();
}

//"aaabc" "cabaa" are anagrams
bool checkIfAnagram(string s1,string s2){
    vector<int> ch(257,0);
    if(s1.size()!=s2.size()) return false;
    for(int i=0;i<s1.size();i++){
        ch[s1[i]]++;
        ch[s2[i]]--;
    }
    for(int i=0;i<257;i++){
        // cout<<ch[i]<<" ";
        if(ch[i]!=0) return false;

    }
    cout<<endl;
    return true;
}

int main(){

cout<<checkIfAnagram("aaabc","cabaa")<<endl;


}