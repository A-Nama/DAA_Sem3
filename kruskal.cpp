#include<iostream>
using namespace std;

#define MAX_EDGES 100
#define MAX_NODES 100

struct Edge{
	int u,v, weight;
};

void sortEdges(Edge edges[], int E){
	for(int i = 0; i< E-1; i++){
		for(int j = 0; j<E-i-1; j++){
			if(edges[j].weight > edges[j+1].weight){
				Edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}
}

int find(int parent[], int x){
	if(parent[x] != x){
		parent[x] = find(parent, parent[x]);}
	return parent[x];
}

void unionSets(int parent[], int x, int y){
	int rootX = find(parent,x);
	int rootY = find(parent,y);
	parent[rootX] = rootY;
}

void kruskal(Edge edges[], int V, int E){
	sortEdges(edges, E);
	
	int parent[MAX_NODES];
	for(int i = 0; i<V; i++){
		parent[i] = i;
	}	
	int mstWeight = 0;
	cout<<"Edges in MST: "<<endl;
	
	for(int i = 0; i <E; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int weight = edges[i].weight;
		
		if(find(parent, u) != find(parent,v)){
			cout<<u<<" - "<<v<<" : "<<weight<<endl;
			mstWeight += weight;
			unionSets(parent,u,v); 
		}
	}
	cout<<"Total weight of MST : "<<mstWeight<<endl;
}

int main(){
	int V, E;
	Edge edges[MAX_EDGES];
	
	cout<<"Enter number of vertices and edges: "<<endl;
	cin>> V >> E;
	
	cout<<"Enter edges (u,v,weight) : "<<endl;
	for(int i =0; i<E; i++){
		cin>>edges[i].u>>edges[i].v>>edges[i].weight;
	}
	
	kruskal(edges, V, E);
}




