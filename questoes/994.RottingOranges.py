from collections import deque

class Solution:
    def orangesRotting(self, grid):
        m, n = len(grid), len(grid[0])          # dimensões da grade
        
        q = deque()           # fila BFS: (i, j, tempo_em_que_apodreceu)
        fresh = 0             # contador de laranjas frescas
        time = 0              # maior tempo registrado até agora
        
        # 1ª varredura: conta laranjas frescas e enfileira todas as podres com tempo 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j, 0))   
        
        # direções dos 4 vizinhos
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # BFS: espalha a podridão
        while q:
            x, y, t = q.popleft()      # célula atual e o minuto em que ela apodreceu
            time = max(time, t)        # atualiza o tempo máximo necessário
            
            # tenta contaminar os 4 vizinhos
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                # verifica se a posição é válida e contém laranja fresca
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                    grid[nx][ny] = 2               # marca como podre
                    fresh -= 1                     # reduz contador de frescas
                    q.append((nx, ny, t + 1))      # nova podre entra na fila com tempo +1
        
        # se todas as laranjas apodreceram retorna o tempo máximo
        # caso contrário = impossível
        return time if fresh == 0 else -1