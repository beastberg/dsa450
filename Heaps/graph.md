
```cpp
include <iostream>
using namespace std;

// class Graph{
//     public:
//     unordered_map<int,list<int>>adjList;
//     void addEdge(int u,int v,bool direction){
//         if(direction==1){
//             adjList[u].push_back(v);
//         }else{
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }
//     }

//     void printAdjList(){
//         for(auto i:adjList){
//             cout<<i.first<< "-> {";
//             for(auto j:i.second){
//                 cout<<j<<", "
//             }
//             cout<<"}"<<endl;
//         }
//     }
// }

template <typename T>
class Graph{
    public:
    unordered_map<T,list<pair<T,int>>>adjList;
    void addEdge(T u,T v,int wt,bool direction){
        if(direction ==1){
            //uni directed graph
            adjList[u].push_back({v,wt}); //use make pair function adList[u].push_back(make_pair(v,wt))
        }else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList(){
        for(auto i:adjList){
            cout<<i.first <<":{";
            for(pair<T,T>p :i.second){
                cout<<"{"<<p.first<<", "<<p.second<<"} ,";
            }
            cout<<endl
        }
    }

    void bfsTravel(T src){
        unordered_map<T,bool> visited;
        queue<T>q;
        
        //initial state
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();

            //go to nbr
            for(auto nbr:adjList[frontend]){
                T nbrData = nbr.first;
                if(!visited[nbrData]){
                    q.push(nbrData);
                    visited[nbrData]=true;
                }
            }
        }
    }

    void dfs(T src unordered_map<T,bool>& visited){
        visited[src] = true;
        cout<<src<<" ";

        for(auto nbr:adjList[src]){
            T nbrData = nbr.first;
            if(!visited[nbrData]){
                dfs(nbrData)
            }
        }
    }
}
int main(){
   Graph g;
   g.addEdge(0,1,1);
   g.addEdge(1,2,1);
   g.addEdge(2,3,1);
   g.bfsTraversal('a')
     
   unordered_map<char,bool>visited;
   for(char node='a';node<="f";node++){
        if(!visited[node])
            g.bfsTraversal(node,visited);
   }
   return 0
}
```


```cpp
#include<iostream>
using namespace std;

int main(){
    unordered_map<string,int>mapping;
    pair<string,int> p = make_pair("love",25);
    pair<string,int> q ("dipansh",24);
    pair<string,int>r;
    q.first = "Arun";
    q.second = 21;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    mapping["babber"] = 51;

    cout<<"Size of map: "<<mapping.size()<<endl;

    cout<<mapping.at("love")<<endl;
    cout<<mapping["love"]<<endl;

    cout<<mapping.count("lover")<<endl;
    cout<<"size of map: "<<map 

}
```