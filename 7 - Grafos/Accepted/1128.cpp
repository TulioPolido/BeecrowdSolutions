#include <iostream>
#include <list>

using namespace std;
bool visitados[1000];

void DFSUtil(list<int> grafo[], int i){
    visitados[i] = true;

    list<int>::iterator it;
    for (it = grafo[i].begin(); it != grafo[i].end(); ++it){
        if(visitados[*it] == false)
            DFSUtil(grafo,*it);
    }
}

bool DFS(list<int> grafo[], int N, int i){

    bool ehConexo = true;

    for(int i = 0; i < N; i++){
        visitados[i] = false;
    }

    DFSUtil(grafo, i);

    for(int j = 0; j < N && ehConexo; j++){
        if(visitados[j] == false)
            ehConexo = false;  
    }

    return ehConexo;
}

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    while(N != 0 && M != 0){

        list<int> grafo[N];
        int V, W, P;
        for (int i = 0; i < M; i++){
            cin >> V >> W >> P;

            grafo[V-1].push_front(W-1);
            if(P == 2){
                grafo[W-1].push_front(V-1);
            }
        }
        
        bool ehConexo = true;
        for (int i = 0; i < N && ehConexo; i++)
        {
            if(!DFS(grafo,N,i))
                ehConexo = false;
        }
        
        cout << ehConexo << endl;

        cin >> N;
        cin >> M;
    }

    return 0;
}