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
        cout<<"\nAdjacency Matrix: \n   ";
        for(int i = 0; i < vertices; i++){
            cout<< i << " ";
        }
        cout<<endl;
        for(int i = 0; i < vertices; i++){
            cout<< i << " |";
            for(int j = 0; j < vertices; j++){
                cout<<adjMatrix[i][j]<<" ";
            }
        cout<<endl;
        }
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

    void printQueue(queue<int> q){
        cout<<"\nQueue: \n";
        while(!q.empty()){
            cout<<q.front()<< " ";
            q.pop();
        }
    }

    void printStack(stack<int> s){
        cout<<"\nStack: \n";
        while(!s.empty()){
            cout<<s.top()<< " ";
            s.pop();
        }
    }

    void printVisited(const vector<bool>& visited){
        cout<<"\nVisited: \n";
        for(bool v : visited){
            cout<<v<<" ";
        }
    }

    void BFS(int start){
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout<<"\nBFS starting from vertex "<<start<<": \n";

        while(!q.empty()){
            int current = q.front();
            cout<<"\nProcessing vertex: "<<current;
            q.pop();

            printQueue(q);
            printVisited(visited);

            for(int neighbor : adjList[current]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
    
    void DFS(int start){
        vector<bool> visited(vertices, false);
        stack<int> s;

        cout<<"\n\nDFS Starting from vertex "<< start<< ": \n";

        s.push(start);

        while(!s.empty()){
            int current = s.top();
            s.pop();

            printVisited(visited);


            if(!visited[current]){
                cout<<"\nProcessing vertex: "<<current;
                visited[current] = true;

                for(int neighbour : adjList[current]){
                    if(!visited[neighbour]){
                        s.push(neighbour);
                    }
                }
            printStack(s);
            }
        }
    }


};

int main(){
    Graph g(5);

    // Add edges to create this graph:
    //     0 --- 1
    //       \    \      
    //        2    3
    //         \  /
    //          4
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    // Print both representations
    g.printAdjMatrix();
    g.printAdjList();

    // Perform traversals
    g.BFS(0);
    g.DFS(0);

    return 0;
}
