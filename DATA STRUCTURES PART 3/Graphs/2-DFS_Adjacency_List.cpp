// DFS Adjancency List
// November 15, 2024
#include <iostream>
#include <stack>
using namespace std;

struct vertex{
    int data;
    vertex* next;
};

void DFS(int **adjList, int sourceNode, int numNodes) {
    stack<int> s;
    bool *visited = new bool[numNodes];
    
    for (int i = 0; i < numNodes; i++)
        visited[i] = false;

    s.push(sourceNode);
    vertex *cuVertex;

    while (!s.empty()) {
        int cu = s.top();   // current node = s.top()
        s.pop();            // pop the top element

        if (!visited[cu]) {
            cout << cu << " ";
            visited[cu] = true;
        }

        cuVertex = adjList[cu];
        while (cuVertex != nullptr) {
            int nextNode = cuVertex -> data;
            if (!visited[nextNode])
                s.push(nextNode);
            cuVertex = cuVertex -> next;
        }
    }
    delete[] visited;
}

void DFS(vertex* graph[], int source, int size){
    stack<int> s;
    bool* visited = new bool[size];

    for(int i = 0; i < size; i++)
        visited[i] = false;
    
    s.push(source);
    vertex* cuVertex;

    while(!s.empty()){
        int cuNode = s.top();
        s.pop();

        if(!visited[cuNode]){
            cout << cuNode << " ";
            visited[cuNode] = true;
        }

        cuVertex = graph[cuNode];
        while(cuVertex != nullptr){
            int nextNode = cuVertex -> data;
            if(!visited[nextNode])
                s.push(nextNode);
            cuVertex = cuVertex -> next;
        }
    }
    cout << endl;
    delete[] visited;
}

int main(){
    vertex* graph[4] = {nullptr};
    graph[0] = new vertex(1);
    graph[0] -> next = new vertex(2);
    graph[1] = new vertex(0);
    graph[1] -> next = new vertex(2);
    graph[2] = new vertex(0);
    graph[2] -> next = new vertex(1);
    graph[2] -> next -> next = new vertex(3);
    graph[3] = new vertex(2);
    
    DFS(graph, 0, 4);

    for (int i = 0; i < 4; i++) {
        vertex* cuVertex = graph[i];
        while (cuVertex != nullptr) {
            vertex* temp = cuVertex;
            cuVertex = cuVertex->next;
            delete temp;
        }
    }

    return 0;
}

// 0 | 1 -> 2 
// 1 | 0 -> 2
// 2 | 0 -> 1 -> 3
// 3 | 2