#include <bits/stdc++.h>
using namespace std;


void beam(unordered_map<char,int>&vis,unordered_map<char,int>hu,unordered_map<char,unordered_map<char,int>>u,char st,char go,int bw)
{
  priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
  pq.push({hu[st],st});
  int maxe=INT_MIN;

  vis[st]=1;
  while(!pq.empty())
  {
    vector<pair<int,char>>next;
    while(!pq.empty())
    {
    char next1=pq.top().second;
    int hu1=pq.top().first;
    cout<<"processing node "<<next1<<" "<<"with huer "<<hu1<<endl;

    pq.pop();
    cout<<"pq size "<<pq.size()<<endl;
    
    cout<<"Available options for "<<next1<<":"<<endl;
    
    for(auto i:u[next1])
    {
      if(vis[i.first]==0)
      {
      
      cout<<i.first<<hu[i.first]<<endl;
      next.push_back({hu[i.first],i.first});
      if(i.first==go)
      {
        cout<<" GOAL REACHED"<<endl;
        return;
      }
      vis[i.first]=1;
      }
    }
    }
    sort(next.begin(),next.end());
    // cout<<"next"<<next[0].first;
    int x=pq.size();
    cout<<"Pushing best "<<bw<<" nodes"<<endl;
    for(int i=0;i<min(bw-x,(int)next.size()-x);i++)
    {
      pq.push(next[i]);
      cout<<"pushing node "<<next[i].second<<next[i].first<<" pq.size "<<pq.size()<<endl;
      if(pq.size()==bw)
      {
        cout<<"pq full"<<endl;
      }
    }
    cout<<endl;
  }
}
int main() 
{
    unordered_map<char,unordered_map<char,int>>u={
      {'A',{{'D',7},{'B',11},{'C',14}}},
      {'B',{{'A',11},{'E',15}}},
      {'C',{{'A',14},{'D',18},{'F',10},{'E',8}}},
      {'D',{{'A',7},{'C',18},{'F',25}}},
      {'E',{{'B',15},{'C',8},{'H',9}}},
      {'F',{{'C',10},{'D',25},{'G',20}}},
      {'G',{{'F',20},{'H',10}}},
      {'H',{{'E',9},{'G',10}}}

    };
    
    unordered_map<char,int>hu={
      {'A',40},
      {'B',32},
      {'C',25},
      {'D',35},
      {'E',19},
      {'F',17},
      {'H',10},
      {'G',0}
    };
    
    unordered_map<char,int>vis;
    beam(vis,hu,u,'A','G',1);
    return 0;
}
