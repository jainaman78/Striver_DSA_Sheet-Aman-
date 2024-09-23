#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        //if(s[j]>=g[i])

        int c=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                c++;
                i++;
                j++;
            }
            else if(g[i]>s[i]){
                j++;
            }
        }
        return c;
    }
