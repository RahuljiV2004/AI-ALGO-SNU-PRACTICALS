#include <bits/stdc++.h>
using namespace std;

void Astr(unordered_map<char,int>&vis,unordered_map<char,unordered_map<char,int>>u,char st,char go,unordered_map<char,int>huer)
{
  priority_queue<pair<int,vector<char>>,vector<pair<int,vector<char>>>,greater<pair<int,vector<char>>>>pq;
  pq.push({huer[st],{st}});
  vis[st]=1;
  int oracle=INT_MAX;
  while(!pq.empty())
  {
    vector<char>current=pq.top().second;
    int h=pq.top().first;
    pq.pop();
    char curr=current.back();
    cout<<"Current path :";
    for(char i:current)
    {
      cout<<i<<" ";
    }
    cout<<endl;
    
    if(h>oracle)
    {
      cout<<"Current cost greater than Oracle pruned node "<<curr<<"with cost "<<h<<endl;
      
    }    
    else
    cout<<"Processing "<<curr<<" with cost "<<h<<endl;
    for(auto i:u[curr])
    {
      vector<char>new1=current;
      new1.push_back(i.first);
      
      if(vis[i.first]==0)
      {
      int ec=i.second;
      int tot=h+ec;
      vis[i.first]=1;
      if(i.first==go)
      {
        cout<<"GOAL REACHED with cost "<<tot<<endl;
        oracle=min(oracle,tot);
        // return;
      }
      pq.push({tot,new1});
     }
    }
  }
}

int main() 
{
   unordered_map<char,unordered_map<char,int>>u={
     {'S',{{'A',3},{'B',5}}},
     {'A',{{'B',4},{'D',3}}},
     {'B',{{'A',4},{'C',4}}},
     {'C',{{'B',4},{'E',6}}},
     {'D',{{'A',3},{'G',5}}},
     {'E',{{'C',6}}},
     {'G',{{'D',5}}}
   };
   
   unordered_map<char,int>huer;
   
   huer['S']=0;
   huer['A']=8;
   huer['B']=6;
   huer['C']=7;
   huer['D']=5;
   huer['E']=1000;
   huer['G']=0;
   
   unordered_map<char,int>vis;
   Astr(vis,u,'S','G',huer);
}
