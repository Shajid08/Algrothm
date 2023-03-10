#include<bits/stdc++.h>
using namespace std;
const int N = 9999;
vector <int> parent(N);

void make_set(int v){
    parent[v] = v;
}

int find_set(int v){
    if(v == parent[v]){
    return v;
    }
    else{
        return find_set(parent[v]);
    }
}


void union_sets(int a , int b){
    int x = find_set(a);
    int y = find_set(b);

    if(x!= y){
    parent[b] = a;

    }

}


int main(){
    bool flag = false;
    int n , m;
    cout<<" Enter Vertex and Edge Number : ";
    cin >> n >> m ;
    for(int i = 0 ; i < N ; i ++){
        
        make_set(i);
    }

    vector<vector<int>> edges;

    for(int i = 0 ; i < m; i++){
        int u , v;
        cout<<"Edge :";
        
        cin >> u >> v;
        edges.push_back({u,v});

    }

    for(auto i: edges){

        int u = i[0];
        int v = i[1];

        int x = find_set(u);
        int y = find_set(v);

        if(x == y ){
          flag = true;
        }else{
            union_sets(u,v);
        }

    }

    if(flag){
        cout<<"cycle";
    }else
       cout<<"No cycle";

}

