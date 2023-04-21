#include <iostream>
#include <list>

using namespace std;
bool visitados[100000];

void DFSUtil(list<long long> grafo[], long long i){
    visitados[i] = true;

    list<long long>::iterator it;
    for (it = grafo[i].begin(); it != grafo[i].end(); ++it){
        if(visitados[*it] == false)
            DFSUtil(grafo,*it);
    }
}

int main() {
    long T;
    cin >> T;

    while(T > 0){

        long long N, M, B, E;
        cin >> N >> M >> B >> E;
        list<long long> grafo[N];
        long long X, Y;
        
        for (long long i = 0; i < M; i++){
            cin >> X >> Y;

            grafo[X-1].push_back(Y-1);
            grafo[Y-1].push_back(X-1);
        }
        
        for(long long i = 0; i < N; i++){
            visitados[i] = false;
        }

        long numComponentes = 0;

        for (long long i = 0; i < N; i++)
        {
            if(visitados[i] == false){
                DFSUtil(grafo,i);
                (grafo,i);
                numComponentes++;
            }
        }
        
        long long valorFinal;
        if(B <= E)
            valorFinal = N * B;
        else
            valorFinal = (numComponentes * B) + ((N - numComponentes) * E);

        cout << valorFinal << endl;
        T--;
    }

    return 0;
}