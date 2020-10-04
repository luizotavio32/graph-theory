from collections import defaultdict
import heapq, sys

class Graph():
    def __init__(self,V,E):
        self.V = V
        self.dest = V
        self.E = E
        self.graph = defaultdict(list)
        self.dist = [2147483647] * (self.V*10+3)

    def addEdge(self, src, dest, weight):
        self.graph[src*10+2].insert(0, (dest*10+1, weight))
        self.graph[src*10+1].insert(0, (dest*10+2, weight))
        self.graph[dest*10+2].insert(0, (src*10+1, weight))
        self.graph[dest*10+1].insert(0, (src*10+2, weight))

    def djisktra(self):
        if self.E == 0:
            print(-1)
            return

        self.dist[12] = 0
        h = []  # min heap
        heapq.heapify(h)
        heapq.heappush(h, (0,12))
        
        while len(h) != 0:
            #print(h)
            dest = heapq.heappop(h)
        
            for x in self.graph[dest[1]]:

                if self.dist[dest[1]] + x[1] < self.dist[x[0]]:
                    self.dist[x[0]] = self.dist[dest[1]] + x[1]
                    heapq.heappush(h, (self.dist[x[0]], x[0]))


        if self.dist[self.V*10+2] != 2147483647:
            print(self.dist[self.V*10+2])
            return
            
        print(-1)
               
                    



### ENVIO DE TESTE PARA VERIFICAR SE O JUDGE ESTA ACEITANDO OS EXPORTS ###



n, e = input().split() 
n = int(n)
e = int(e)
g = Graph(n,e)

for i in range(e):
    u, v, w = input().split() 
    u = int(u)
    v = int(v)
    w = int(w)
    g.addEdge(u,v,w)
    


g.djisktra()






