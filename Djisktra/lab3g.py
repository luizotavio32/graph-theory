from collections import defaultdict
import math


class MinHeap(): 
  
    def __init__(self): 
        self.array = []
        self.pos = [] 
        self.size = 0
         
  
    def newMinHeapNode(self, v, dist): 
        minHeapNode = [v, dist] 
        return minHeapNode 
  
 
    def swap(self,a, b): 
        t = self.array[a] 
        self.array[a] = self.array[b] 
        self.array[b] = t 
  

    def minHeapify(self, idx): 
        smallest = idx 
        left = 2*idx + 1
        right = 2*idx + 2
  
        if left < self.size and self.array[left][1] < self.array[smallest][1]: 
            smallest = left 
  
        if right < self.size and self.array[right][1] < self.array[smallest][1]: 
            smallest = right 
  
         
        if smallest != idx:   
            self.pos[ self.array[smallest][0] ] = idx 
            self.pos[ self.array[idx][0] ] = smallest 
            self.swap(smallest, idx) 
            self.minHeapify(smallest) 
  
     
    def extractMin(self): 
  
        if self.isEmpty() == True: 
            return
        root = self.array[0] 
        lastNode = self.array[self.size - 1] 
        self.array[0] = lastNode 
        self.pos[lastNode[0]] = 0
        self.pos[root[0]] = self.size - 1
        self.size -= 1
        self.minHeapify(0) 
  
        return root 
  
    def isEmpty(self): 
        return True if self.size == 0 else False
  
    def decreaseKey(self, v, dist): 
  
        i = self.pos[v] 
        self.array[i][1] = dist 
        
        while i > 0 and self.array[i][1] < self.array[(i - 1)//2][1]: 
            self.pos[self.array[i][0]] = int((i-1)/2)
            self.pos[self.array[(i-1)//2][0]] = i 
            self.swap(i, (i - 1)//2) 
            i = (i - 1)//2
  
  
    def isInMinHeap(self, v): 
  
        if self.pos[v] < self.size: 
            return True
        return False
  
  

  


class Graph():
    def __init__(self,V,E):
        self.V = V
        self.dest = V - 1
        self.E = E
        self.graph = defaultdict(list)
        self.visited = [0] * self.V


    def addEdge(self, src, dest, weight):
        self.graph[src-1].insert(0, (dest-1,weight))
        self.graph[dest-1].insert(0, (src-1,weight))






    def djisktra(self):
        #print(self.graph)

        dist = [2147483647]* self.V 
        dist[0] = 0  
        parent = [-1] * self.V
        parent[0] = -2 
        h = MinHeap() 
  
         
        for v in range(self.V): 
             
            h.array.append(h.newMinHeapNode(v, dist[v]) ) 
            h.pos.append(v) 
  
         
        h.pos[0] = 0 
        dist[0] = 0
        h.decreaseKey(0, dist[0]) 
        h.size = self.V

        def count_vertices(parent, v):
            if (parent[v] == -2):
                return 1
            elif(parent[v] == -1):
                return 0
            elif(parent[v] != -2):
                return count_vertices(parent, parent[v]) + 1
  
         
        while h.isEmpty() == False: 
  
             
            newHeapNode = h.extractMin() 
            u = newHeapNode[0] 
            for node in self.graph[u]: 
  
                v = node[0]
                
              
                if h.isInMinHeap(v) and dist[u] != 2147483647 and node[1] + dist[u] < dist[v]: 
                        dist[v] = node[1] + dist[u] 
                        parent[v] = u 
                        h.decreaseKey(v, dist[v])

        #print(dist)
        #print(parent)
        

        if(dist[self.dest] == 2147483647):
            return -1
                
        vertices = count_vertices(parent, self.dest)
    
        if(vertices % 2 == 0):
            for i in range(len(self.graph[parent[u]])):
                y = self.graph[parent[u]][i]
                if(y[0] == u):
                    self.graph[parent[u]].pop(i)
                    return -2

        return dist[self.dest]
                            

    def djisktraHelper(self):

        ret = -1
        for i in range(self.E):
            ret = self.djisktra()
            if(ret == -1 or ret >= 0):
                print(ret)
                break
            
    # def backtrack_djikstra(self, u, vertex_count, d):



    #         #print(u)
        
    #         if(u == self.dest and vertex_count % 2 == 1):
    #             print(d)

    #         h = []
    #         heapq.heapify(h)
    #         for x in self.graph[u]:
    #             heapq.heappush(h, x)
                
    #         self.visited[u] = 1
    #         for x in self.graph[u]:
    #             dest = heapq.heappop(h)
    #             if(self.visited[dest[1]] == 0):
    #                 self.backtrack_djikstra(dest[1], vertex_count + 1, d+dest[0])
    #         self.visited[u] = 0
            





### ENVIO DE TESTE PARA VERIFICAR SE O JUDGE ESTA ACEITANDO OS EXPORTS ###

# g = Graph(4,4)
# g.addEdge(1,2,2)
# g.addEdge(2,3,1)
# g.addEdge(2,4,10)
# g.addEdge(3,4,6)

# g = Graph(5,5)
# g.addEdge(1,2,2)
# g.addEdge(2,3,3)
# g.addEdge(2,4,4)
# g.addEdge(4,5,1)


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
    


g.djisktraHelper()
#g.backtrack_djikstra(0, 1, 0)





