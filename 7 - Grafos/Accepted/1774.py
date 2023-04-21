def find(pai, i):
    if pai[i] == i:
        return i
    return find(pai, pai[i])

def union(pai, rank, x, y):
    raizDeX = find(pai,x)
    raizDeY = find(pai,y)

    if rank[raizDeX] < rank[raizDeY]:
        pai[raizDeX] = raizDeY
    elif rank[raizDeX] > rank[raizDeY]:
        pai[raizDeY] = raizDeX
    else:
        pai[raizDeY] = raizDeX
        rank[raizDeX] +=1

def Kruskal(arestas,N):
    resultado = []

    i = 0 #indice das arestas
    e = 0 #indice do resultado

    arestas = sorted(arestas, key=lambda item:item[2]) #faz um sort tendo como base o item[2] -> peso das arestas

    pai = []
    rank = []

    for no in range(N):
        pai.append(no)
        rank.append(0)

    while e < N-1:  #enquanto a qtd de arestas nao for vertices-1
        u,v,w = arestas[i]
        i += 1
        x = find(pai,u)
        y = find(pai,v)

        if x != y:
            e += 1 #adicionou uma aresta
            resultado.append([u,v,w])
            union(pai,rank,x,y)

    pesoTotal = 0
    for u,v,w in resultado:
        pesoTotal += w

    return pesoTotal
    
#Driver
R,C = map(int,input().split())

arestas = []

for i in range(C):
    V,W,P = map(int, input().split())
    arestas.append([V-1,W-1,P])

print(Kruskal(arestas,R))