#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph{
private:
    int vertices;
    list<int>* adjList;
    vector<vector<int>> adjMatrix;

    void initialize(){
        adjList = new list<int>[vertices];
        adjMatrix = vector<vector<int>>(vertices, vector<int>(vertices));
    }
public:
    Graph(int v):vertices(v){
        initialize();
    }
    ~Graph(){
        delete[] adjList;
    }

    void addEdge(int u, int v){

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

    }

    void printAdjMatrix(){
        cout<<"\nAdjacency Matrix: \n";
        for(int i = 0; i < vertices; i++){
            cout<< i << " ";
        }
        cout<<endl;
        for(int i = 0; i < vertices; i++){
            cout<< i << " ";
            for(int j = 0; j < vertices; j++){
                cout<<adjMatrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    
    void printAdjList(){
        cout<<"\nAdjacency List: \n";
        for(int i = 0; i < vertices; i++){
            cout<<"Vertex "<<i<<": ";
            for(int x : adjList[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    
    


};

int main(){


    return 0;
}
