class Solution {
public:
    // Função DFS para explorar e marcar a ilha
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Condição de Parada (Borda, Água ou Já Visitado)
        // Nota: Estamos mudando '1' para '0' para marcar como visitado
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            return;
        }

        // Marca como visitado (transforma terra em água para não contar de novo)
        grid[i][j] = '0';

        // Chamadas Recursivas para os 4 vizinhos (Cima, Baixo, Esq, Dir)
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int total_ilhas = 0;

        // Loop Principal (Varredura da Matriz)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Se encontrar terra firme, é uma nova ilha
                if (grid[i][j] == '1') {
                    total_ilhas++;
                    // Dispara a DFS para afundar essa ilha inteira
                    dfs(grid, i, j);
                }
            }
        }

        return total_ilhas;
    }
};