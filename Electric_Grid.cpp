#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int st, dest, weight;
    
    Edge(int s, int d, int w) : st(s), dest(d), weight(w) {}

    bool operator<(const Edge &other) const{
        return weight < other.weight;
    }
};

class DisjointSet{
    vector<int> parent, rank;

public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if (parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionSets(int x, int y){
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py]){
            parent[px] = py;
        }else if (rank[px] > rank[py]){
            parent[py] = px;
        }else{
            parent[py] = px;
            rank[px]++;
        }
    }
};

class ElectricalGrid
{
    int V;
    vector<Edge> edges;

public:

    ElectricalGrid(int vertices) : V(vertices) {}

    void addConnection(int st, int dest, int cost){
        edges.emplace_back(st, dest, cost);
    }

    vector<Edge> findMinimumCostConnections(){
        vector<Edge> result;

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        for (const auto &it : edges){
            
            int stParent = ds.find(it.st);
            int destParent = ds.find(it.dest);

            if (stParent != destParent){
                result.push_back(it);
                ds.unionSets(stParent, destParent);
            }
        }

        return result;
    }
};

int main(){
    
    int n;
    cout << "Enter Number of nodes: ";
    cin >> n;
    ElectricalGrid grid(n);
    
    int a ,b, wt;
    
    cout << "\nEnter -1 -1 when connections are over!\n" << endl;
    bool flag = true;
    
    while(flag){
        cout << "Enter node numbers to be connected: ";
        cin >> a;
        cin >> b;
        if(a < 0 || b < 0) break;
        cout << "Enter length of the connection: ";
        cin >> wt;
        grid.addConnection(a, b, wt);
    }

    vector<Edge> minSpanningTree = grid.findMinimumCostConnections();

    int totalCost = 0;
    cout << "\nMinimum cost connections:\n\n";
    
    for (const auto &it : minSpanningTree){
        cout << "Connect node " << it.st << " to node " << it.dest << " with length " << it.weight << "\n";
        totalCost += it.weight;
    }
    cout << "\nTotal minimum length: " << totalCost << "\n";

    return 0;
}
