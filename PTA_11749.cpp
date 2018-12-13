// 22441726

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
 
using namespace std;
 
int n; 
int matriz [500 + 5] [500 + 5]; 
int maiorPPA; 
bool visitado [500 + 5];
 
set <int> componente;

void dfs(int at)
{
    for ( int i = 1; i <= n; i++ ) {
        if (matriz [at] [i] == maiorPPA && !visitado [i]) {
            visitado [at] = visitado [i] = true;
            componente.insert(at);
            componente.insert(i);
            dfs(i);
        }
    }
}
 
void reinicia(){
    for ( int i = 0; i < 505; i++ ) {
        for ( int j = 0; j < 505; j++ ) {
            matriz [i] [j] = -Inf;
        }
    }
}
 
int main (){
    int m;
     
    while (scanf ("%d %d", &n, &m) != EOF) {
         
        if (n == 0 && m == 0) break;
         
        maiorPPA = -Inf;
         
        reinicia();
         
        for ( int i = 0; i < m; i++ ) {
            int a, b, c;
            scanf ("%d %d %d", &a, &b, &c);
             
            // várias arestas com PPA diferente, pega o maior
            if (c > matriz [a] [b])
                matriz [a] [b] = matriz [b] [a] = c;
             
            maiorPPA = max(maiorPPA, c);
        }
         
        memset(visitado, false, sizeof visitado);
         
        int forteConectado = 0;
         
        for ( int i = 1; i <= n; i++ ) {
            if (!visitado [i]) {
                componente.clear();
                dfs(i);
                forteConectado = max (forteConectado, (int) componente.size());
            }
        }
         
        printf ("%d\n", forteConectado);
    }
     
    return 0;
}
