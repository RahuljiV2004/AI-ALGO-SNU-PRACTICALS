#include <bits/stdc++.h>
using namespace std;

int minimax(int h,int d,int ind,vector<int>val,bool x)
{
  if(d==h)
  {
    return val[ind];
  }
  if(x)
  {
    return max(minimax(h,d+1,2*ind,val,false),minimax(h,d+1,2*ind+1,val,false));
  }
  else
  {
    return min(minimax(h,d+1,2*ind,val,true),minimax(h,d+1,2*ind+1,val,true));
  }
}

int main() 
{
    vector<int>val={3, 5, 2, 9, 12, 5, 23, 23};
    cout<<minimax(3,0,0,val,true);
}
