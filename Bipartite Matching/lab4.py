from collections import defaultdict
class Graph: 
    def __init__(self,N,M):
        
        self.m_graph = defaultdict(list)
        self.childs = N
        self.toys = M
        self.match = [-1] * self.toys
        self.m_MaxMatch = 0
 
    def add_edges(self,N,M):
        self.m_graph[str(N)].insert(0, str(M))
        
        
    
    def check_edges(self,N,M):
         return str(M) in self.m_graph[str(N)]
    
    #Hall perfect match
    def perfect_match(self, l, match, mR):
        for r in range(self.toys): 
            if self.check_edges(l,r) and mR[r] == False: 
                mR[r] = True
                if match[r] == -1 or self.perfect_match(match[r],match, mR): 
                    match[r] = l 
                    return True
        return False
 
    def max_match(self): 
        for i in range(self.childs):  
            mR = [False] * self.toys  
            if self.perfect_match(i, self.match, mR): 
                self.m_MaxMatch += 1
        return self.m_MaxMatch
 
import sys
#judge template
#m_input = input().split() 
m_input =     sys.stdin.readline().split()
N = int(m_input[0])
M = int(m_input[1])
m_range = int(m_input[2])
 
g = Graph(N,M)
 
for i in range(m_range):
    nm_input = sys.stdin.readline().split()
    g.add_edges( int(nm_input[0]) , int(nm_input[1]) )
 
print(g.max_match())