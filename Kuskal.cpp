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
    int cost=0;
    cout<<" Enter Vertex and Edge Number : ";
    cin >> n >> m ;
    for(int i = 0 ; i < N ; i ++){
        
        make_set(i);
    }

    vector<vector<int>> edges;

    for(int i = 0 ; i < m; i++){
        int u , v,w;
        cout<<"Edge & widght :";
        
        cin >> w >> u>>v;
        edges.push_back({w,u,v});

    }
    sort(edges.begin(),edges.end());

    for(auto i: edges){
        int w=i[0];
        int u = i[1];
        int v = i[2];
        cout<<i[0]<<" "<<i[1] <<" "<<i[2] <<" "<<i[3] <<" "<<i[4] <<" "<<i[5] <<" "<<i[6] <<" "<<i[7] <<" "<<i[8]  ;

        int x = find_set(u);
        int y = find_set(v);

        if(x == y ){
            continue;
        }else{
            cout<<u<<""<<v<<"\n";
            cost=cost+w;
            union_sets(u,v);
        }

    }
    cout<<"minimum cost: "<< cost;

     

}

