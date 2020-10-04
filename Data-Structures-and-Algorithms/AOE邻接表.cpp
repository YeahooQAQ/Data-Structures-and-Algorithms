#include<iostream>
#include<vector>
#include<queue> 
//7-11 关键活动 (30分)
using namespace std;

struct Edge{
	int to;
	int cost;
};
 
int vertex_num;
int edge_num;
const int kMaxVertexSize = 110;
int in_degree[kMaxVertexSize]; //顶点入度 
int v_late[kMaxVertexSize]; //顶点最迟开始时间 
int v_early[kMaxVertexSize]; //顶点最迟开始时间 
int topo[kMaxVertexSize]; //拓扑排序 
vector<Edge> edges[kMaxVertexSize]; //边 

bool TopologicalSort();
void FindKeyPath();

int main(){
	
	int from, to, cost;
	cin>>vertex_num>>edge_num;
	
	for(int i = 0;i < edge_num;i++){
		cin>>from>>to>>cost;
		in_degree[to]++;
		Edge edge = {to, cost};
		edges[from].push_back(edge);
	}
	
	if(TopologicalSort()){
		FindKeyPath();
	}
	else{
		cout<<"0";
	}
	
	return 0;
} 

bool TopologicalSort(){
	int vertex_cnt = 0;	
	queue<int> q;
	
	for(int i = 1;i <= vertex_num;i++){
		if(in_degree[i] == 0){
			q.push(i);
			topo[++vertex_cnt] = i;
		}
	}
	
	while(!q.empty()){
		int vertex = q.front();
		int edge_size = edges[vertex].size();
		q.pop();
		
		for(int i = 0;i < edge_size;i++){
			in_degree[edges[vertex][i].to]--;
			if(in_degree[edges[vertex][i].to] == 0){
				q.push(edges[vertex][i].to);
				topo[++vertex_cnt] = edges[vertex][i].to;
			} 
		} 
	}
	
	if(vertex_num != vertex_cnt){
		return false;
	}
	return true;
}

void FindKeyPath(){
	
	for(int i = 0;i < vertex_num;i++){
		v_early[i] = 0;
	} 
	
	for(int i = 1;i <= vertex_num;i++){
		int vertex = topo[i];
		int edge_size = edges[vertex].size();
		for(int j = 0;j < edge_size;j++){
			if(v_early[edges[vertex][j].to] < v_early[vertex] + edges[vertex][j].cost){
				v_early[edges[vertex][j].to] = v_early[vertex] + edges[vertex][j].cost;
			}
		}
	}
	
	v_late[topo[vertex_num]] = v_early[topo[vertex_num]];
	int max = 0;
	for(int i = 0;i <= vertex_num;i++){
		if(max < v_early[i]){
			max = v_early[i];
		}
	} 
	
	for(int i = 0;i <= vertex_num;i++){
		v_late[i] = max;
	} 
	
	cout<<max<<endl;	
	for(int i = vertex_num;i > 0;i--){
		int vertex = topo[i];
		int edge_size = edges[vertex].size();
		for(int j = 0;j < edge_size;j++){
			if(v_late[vertex] > v_late[edges[vertex][j].to] - edges[vertex][j].cost){
				v_late[vertex] = v_late[edges[vertex][j].to] - edges[vertex][j].cost;
			}
		}
	}
	

	for(int i = 1;i <= vertex_num;i++){
		int edge_size = edges[i].size(); 
		for(int j = edge_size-1; j >= 0;j--){
			if(v_early[i] + edges[i][j].cost == v_late[edges[i][j].to]){
				cout<<i<<"->"<<edges[i][j].to<<endl;
			}
		}
	}	
}
