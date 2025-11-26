class Solution:
    def criticalConnections(self, n, connections):
        g = [[] for _ in range(n)]
        for a, b in connections:
            g[a].append(b)
            g[b].append(a)
        
        disc = [-1] * n
        low  = [-1] * n
        res  = []
        timer = [0]                 # usamos lista para poder modificar dentro da função
        
        def dfs(u, parent):
            disc[u] = low[u] = timer[0]
            timer[0] += 1
            
            for v in g[u]:
                if v == parent:
                    continue
                if disc[v] == -1:           # ainda não visitado
                    dfs(v, u)
                    low[u] = min(low[u], low[v])
                    if low[v] > disc[u]:    # é ponte!
                        res.append([u, v])
                else:                       # back-edge
                    low[u] = min(low[u], disc[v])
        
        dfs(0, -1)                      # começa do nó 0
        return res