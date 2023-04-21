#include <iostream>
#include <list>
#include <climits>

using namespace std;
bool visitados[100000];
long long dist[100000];
long long N = 100000;

long long add(long long num){
    return num + 1;
}

long long reverso(long long num){
    long long reverso = 0, aux;

    while(num != 0) {
        aux = num % 10;
        reverso = reverso * 10 + aux;
        num /= 10;
    }

    return reverso;
}

long long BFS(list<long long> grafo[], long long a, long long b)
{
    list<long long> queue;
    long long valorMin = LLONG_MAX;
 
    queue.push_back(a);
    visitados[a] = true;
    dist[a] = 0;
 
    while (!queue.empty()) {
        long long u = queue.front();
        queue.pop_front();
 
        list<long long>::iterator it;
        for (it = grafo[u].begin(); it != grafo[u].end(); ++it){
            if(visitados[*it] == false){
                visitados[*it] = true;
                dist[*it] = dist[u] + 1;
                if(*it == b) return dist[*it];
                queue.push_back(*it);
            }
        }
    }

    return valorMin;
}

int main() {
    long T;
    cin >> T;

    while(T > 0){

        long long A,B;
        cin >> A >> B;

        list<long long> grafo[N];
        
        // Seta listas 
        for(long long i = 0; i < 100000; i++){
            visitados[i] = false;
            dist[i] = -1;
        }

        // Preenche grafo
        for(long long i = 0; i < N; i++){
            long long v = add(i);
            if(v < N) grafo[i].push_back(v);
            v = reverso(i);
            if(v < N) grafo[i].push_back(v);
        }

        long long valorMin = BFS(grafo,A,B);
        cout << valorMin << endl;
        T--;
    }

    return 0;
}