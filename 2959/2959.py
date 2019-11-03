def DFSUtil(v,y,visitados,grafo):
    ehPossivel = False
    visitados[v] = True

    if v == y:
        ehPossivel = True
    else:
        for i in grafo[v]:
            if visitados[i] == False and ehPossivel == False:
                ehPossivel = DFSUtil(i,y,visitados,grafo)

    return ehPossivel

def DFS(x,y,grafo,N):
    visitados = [False] * N

    ehPossivel = DFSUtil(x,y,visitados,grafo)

    return ehPossivel

N,M,P = map(int, input().split())
g = {i: [] for i in range(N)}

for i in range(M):
    A,B = map(int, input().split())
    g[A-1].append(B-1)
    g[B-1].append(A-1)

for i in range(P):
    K,L = map(int, input().split())
    ehPossivel = DFS(K-1,L-1,g,N)
    if ehPossivel == True:
        print("Lets que lets")
    else:
        print("Deu ruim")