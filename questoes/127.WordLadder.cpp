class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Colocar todas as palavras num Set para busca rápida O(1)
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // Se a palavra final não estiver no dicionário, é impossível chegar lá.
        if (dict.find(endWord) == dict.end()) return 0;
        
        // 2. Fila para a BFS
        queue<string> q;
        q.push(beginWord);
        
        // Removemos a palavra inicial do dicionário para não visitá-la de novo
        if (dict.find(beginWord) != dict.end()) {
            dict.erase(beginWord);
        }
        
        // Nível começa em 1 (contando a própria beginWord)
        int nivel = 1;
        
        // 3. Loop Principal da BFS
        while (!q.empty()) {
            int tamanhoNivel = q.size();
            
            // Processa todos os nós da camada atual
            while (tamanhoNivel--) {
                string palavraOriginal = q.front();
                q.pop();
                
                string palavraAtual = palavraOriginal;
                
                // Tenta trocar cada letra da palavra
                for (int i = 0; i < palavraAtual.length(); i++) {
                    char letraOriginal = palavraAtual[i];
                    
                    // Testa todas as letras de 'a' a 'z'
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == letraOriginal) continue;
                        
                        palavraAtual[i] = c;
                        
                        // Achamos o destino?
                        if (palavraAtual == endWord) return nivel + 1;
                        
                        // Se a palavra existe no dicionário, é um vizinho válido
                        if (dict.find(palavraAtual) != dict.end()) {
                            q.push(palavraAtual);
                            dict.erase(palavraAtual); // Marca como visitado removendo do set
                        }
                    }
                    // Restaura a letra para a próxima iteração
                    palavraAtual[i] = letraOriginal;
                }
            }
            // Terminou a camada, incrementa a distância
            nivel++;
        }
        
        return 0;
    }
};