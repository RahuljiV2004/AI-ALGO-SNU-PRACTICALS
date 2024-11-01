#include <bits/stdc++.h>
using namespace std;

void bms(map<char,map<char,int>>u,char start,char goal)
{
  queue<vector<char>>q;
  q.push({start});
  vector<vector<char>>goals;
  while(!q.empty())
  {
    vector<char>current=q.front();
    q.pop();
     for(char i:current)
    {
      cout<<i<<" ";
    }
    cout<<endl;
    char curr=current.back();
    for(auto i:u[curr])
    {
      if(find(current.begin(),current.end(),i.first)!=current.end())
      {
        continue;
      }
      vector<char>new1=current;
      new1.push_back(i.first);   
      if(i.first=='G'){
        goals.push_back(new1);
      }
      q.push(new1);
    }
  }
  cout<<"Goals reached path: "<<endl;
  for(auto i:goals)
  {
    for(char j:i)
    {
      cout<<j<<" ";
    }
    cout<<endl;
  }
}

void bfs(map<char,map<char,int>>u,char start,char goal, unordered_map<char,int>&vis)
{
  queue<vector<char>>q;
  q.push({start});
  vis[start]=1;
  vector<vector<char>>goals;
  while(!q.empty())
  {
   
    vector<char>current=q.front();
     char curr=current.back();
    cout<<"node processing: "<<curr<<endl;
    cout<<"current path:";
    for(char i:current)
    {
      cout<<i<<" ";
    }
    cout<<endl;
    q.pop();
    
    for(auto i:u[curr])
    {
      if(vis[i.first]==0)
      {
        vis[i.first]=1;
        
        vector<char>new1=current;
        
        new1.push_back(i.first);
        if(i.first==goal)
        {
          cout<<"Goal path: "<<endl;
          for(char i:new1){
            cout<<i<<" ";
          }
          return;
        }
        q.push(new1);
      }
    }
  }
}
 

void dfs(map<char,map<char,int>>u,char start,char goal, unordered_map<char,int>&vis)
{
  stack<vector<char>>st;
  //
  st.push({start});
  
  vis[start]=1;
  while(!st.empty())
  {
    vector<char>current=st.top();
    char curr=current.back();
    st.pop();
    cout<<"node processing: "<<curr<<endl;
    cout<<"current path:";
    for(char i:current)
    {
      cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:u[curr])
    {
      if(vis[i.first]==0)
      {
        vis[i.first]=1;
        vector<char>new1=current;
        new1.push_back(i.first);
        if(i.first==goal)
        {
          cout<<"Goal path: "<<endl;
          for(char j:new1)
          {
            cout<<j<<" ";
          }
          return;
        }
        st.push(new1);
        
      }
    }
  }
}

void hillclimb(map<char,map<char,int>>u,char start,char goal, unordered_map<char,int>&vis)
{
  int best=1000;
  char curr=start;
  char next;
  vis[curr]=1;
  while(true)
  {
    bool modified=false;
  for(auto i:u[curr])
  {
    
    if((vis[i.first]!=1)&&(best>i.second))
    {
      best=i.second;
      next=i.first;
      vis[i.first]=1;
      modified=true;
    }
    
  }
  if(modified)
  {
  cout<<"Traversing node "<<next<<"with heuristics "<<best<<endl; 
  curr=next;
  }
  else
  {
  cout<<"Stopped on reaching a local minima"<<endl;
  return;
  }
  }

}

int main() 
{
  map<char,map<char,int>>u={
    {'S',{{'A',3},{'B',5}}},
    {'A',{{'S',3},{'B',4},{'D',3}}},
    {'B',{{'S',5},{'A',4},{'C',4}}},
    {'C',{{'B',4},{'E',6}}},
    {'D',{{'A',3},{'G',5}}},
    {'E',{{'C',6}}},
    {'G',{{'D',5}}}
  };
//   S':{'A':7.38,'B':6}, 
// 'A':{'S':np.inf,'B':6,'D':5}, 
// 'B':{'S':np.inf,'A':7.38,'C':7.58}, 
// 'C':{'B':6,'E':np.inf}, 
// 'E':{'C':7.58}, 
// 'D':{'A':7.38,'G':0}, 
// 'G':{'D':5} 
  map<char,map<char,int>>hu={
    {'S',{{'A',5},{'B',6}}},
    {'A',{{'S',INT_MAX},{'B',6},{'D',4}}},
    {'B',{{'S',INT_MAX},{'A',5},{'C',8}}},
    {'C',{{'B',6},{'E',INT_MAX}}},
    {'D',{{'A',5},{'G',0}}},
    {'E',{{'C',8}}},
    {'G',{{'D',4}}}
  };
  
 
  cout<<"BMS SEARCH: "<<endl;
  bms(u,'S','G');
  cout<<"BFS SEARCH: "<<endl;
   unordered_map<char,int>vis;
   
  bfs(u,'S','G',vis);
  vis.clear();
  cout<<endl;
  cout<<"DFS SEARCH: "<<endl;
  dfs(u,'S','G',vis);
  cout<<endl;
  vis.clear();
  hillclimb(hu,'S','G',vis);
}
  
