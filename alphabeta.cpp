#include <bits/stdc++.h>
using namespace std;


int alpb(int h,int d,int alp,int bet,int ind,vector<int>&values,bool maxi)
{
  if(d==h)
  {
    return values[ind];
  }
  if(maxi)
  {
    int best=INT_MIN;
    for(int i=0;i<2;i++)
    {
      int val=alpb(h,d+1,alp,bet,2*ind+i,values,false);
      best=max(best,val);
      alp=max(best,alp);
      if(bet<=alp)break;
    }
    return best;
  }
  else
  {
    int best=INT_MAX;
    for(int i=0;i<2;i++)
    {
      int val=alpb(h,d+1,alp,bet,2*ind+i,values,true);
      best=min(best,val);
      bet=min(best,alp);
      if(bet<=alp)break;
    }
    return best;
  }
}
int main() 
{
  vector<int>values={ 3, 5, 6, 9, 1, 2, 0, -1 };
   cout<<alpb(3,0,INT_MIN,INT_MAX,0,values,true);
}
