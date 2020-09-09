from collections import defaultdict 
class Graph: 
   
    def __init__(self,vertices): 
        self.V = vertices 
        self.graph = defaultdict(list) 
        self.Time = 1
        self.discoveryTime = [-1] * self.V
        self.fv = [-1] * self.V
   
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
        self.graph[v].append(u) 
   
   
    def DFSTreeRecur(self, v, visited, parent): 
  
        visited[v]= True 
        self.discoveryTime[v] = self.Time 
        self.fv[v] = self.Time
        self.Time += 1
        
        for u in self.graph[v]: 
            if visited[u] == False : 
                parent[u] = v 
                self.DFSTreeRecur(u, visited, parent) 
                self.fv[v] = min(self.fv[v], self.fv[u]) 

            elif u != parent[v]:  
                self.fv[v] = min(self.fv[v], self.discoveryTime[u]) 
  
        self.Time += 1
   
    def DFS(self): 
   
       
        visited = [False] * (self.V) 
        parent = [-1] * (self.V) 
        for i in range(self.V): 
            if visited[i] == False: 
                self.DFSTreeRecur(i, visited, parent) 



    def getFv(self):
        for i in range(self.V):
            print(str(i) + " = " + str(self.fv[i]))


    def getTime(self):
        for i in range(self.V):
            print(str(i) + " = " + str(self.discoveryTime[i]))
            

 

g1 = Graph(13)
# g1.addEdge(0,1)
# g1.addEdge(0,5)
# g1.addEdge(0,6)
# g1.addEdge(1,2)
# g1.addEdge(2,3)
# g1.addEdge(3,4)
# g1.addEdge(5,7)
# g1.addEdge(5,8)
# g1.addEdge(5,6)
# g1.addEdge(8,9)
# g1.addEdge(8,10)
# g1.addEdge(9,10)
# g1.addEdge(10,11)
# g1.addEdge(10,6)
# g1.addEdge(11,12)
# g1.addEdge(12,10)

graphAdj = {0: [1,5,12],
            1: [0,2],
            2: [1,3],
            3: [2,4],
            4: [1,3],
            5: [0,6,7,12],
            6: [5],
            7: [5,8,9],
            8: [7,9],
            9: [7,8,10,11,12],
           10: [9,11],
           11: [9,10],
           12: [0,5,9]}

g1.graph = graphAdj
g1.DFS()
g1.getTime()
g1.getFv()





