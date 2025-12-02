// DFS Adjacency Matrix
// November 15, 2024
#include <iostream>
#include <stack>
using namespace std;

void DFS(int **graph, int source, int size){
    stack<int> s;
    bool *visited = new bool[size];

    for(int i = 0; i < size; i++)
        visited[i] = false;
    
    s.push(source);
    while(!s.empty()){
        int cuNode = s.top();
        s.pop();

        if(!visited[cuNode]){
            cout << cuNode << " ";
            visited[cuNode] = true;
        }
        for(int i = 0; i < size; i++){
            if(graph[cuNode][i] != 0 && !visited[i])
                s.push(i);
        }
    }
    cout << endl;
    delete[] visited;
}

// void DFS(int **adjMatrix, int sourceNode, int numNodes) {
//     stack<int> s;
//     bool *visited = new bool[numNodes];
    
//     for (int i = 0; i < numNodes; i++)
//         visited[i] = false;

//     s.push(sourceNode);

//     while (!s.empty()) {
//         int cu = s.top();   // current node = s.top()
//         s.pop();            // pop the top element

//         if (!visited[cu]) {
//             cout << cu << " ";
//             visited[cu] = true;
//         }

//         for (int i = 0; i < numNodes; i++) {
//             if (adjMatrix[cu][i] != 0 && !visited[i])
//                 s.push(i);
//         }
//     }
//     delete[] visited;
// }

int main() {
    // Dynamically allocate the adjacency matrix
    int numNodes = 4;
    int **AJ = new int*[numNodes];
    int data[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}
    };

    for (int i = 0; i < numNodes; i++) {
        AJ[i] = new int[numNodes];
        for (int j = 0; j < numNodes; j++) {
            AJ[i][j] = data[i][j];
        }
    }

    DFS(AJ, 0, numNodes);

    // Free the dynamically allocated matrix
    for (int i = 0; i < numNodes; i++) {
        delete[] AJ[i];
    }
    delete[] AJ;

    return 0;
}