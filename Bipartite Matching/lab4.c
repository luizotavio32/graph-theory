#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int n, m, e;
    int **matrix;
};

void initGraph(struct Graph *g, int n, int m, int e) 
{
    int i;
    g->n = n;
    g->m = m;
    g->e = e;
    g->matrix = malloc(n * sizeof(int*));
    for(i = 0; i < n; i++) g->matrix[i] = malloc(m * sizeof(int));
}

void printMatrix(int **mat, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void fillArray(int *array, int size, int x)
{
    int i;
    for (i = 0; i < size; i++)
        array[i] = x;
}

int findMaxBipartiteMatching(struct Graph *g, int *toys_seen, int *toys_assigned, int current_kid) 
{
    int i;
    for (i = 0; i < g->m; i++){

        if(g->matrix[current_kid][i] && !toys_seen[i]) {
            toys_seen[i] = 1;
            
            if(toys_assigned[i] == -1 || findMaxBipartiteMatching(g, toys_seen, toys_assigned, toys_assigned[i])) {
                toys_assigned[i] = current_kid;
                return 1;
            }
        }
    }
    return 0;
}

void maxKidsCanPlay(struct Graph *g) 
{
    int i, maxKids = 0;
    int *toys_seen, *toys_assigned;

    toys_seen = malloc(g->m * sizeof(int));
    toys_assigned = malloc(g->m * sizeof(int));
    
   fillArray(toys_assigned, g->m, -1);

    for (i = 0; i < g->n; i++) {
        if(findMaxBipartiteMatching(g, toys_seen, toys_assigned, i)) 
            maxKids++;

        fillArray(toys_seen, g->m, 0);
    }

    printf("%d\n", maxKids);
}



int main(int argc, char const *argv[])
{
    int kids, toys, toy_interest, i, c, b;
    scanf("%d %d %d", &kids, &toys, &toy_interest);
    if(toy_interest == 0){
        printf("0\n");
        return 0;
    }

    struct Graph graph;
    initGraph(&graph, kids, toys, toy_interest);

    for (i = 0; i < graph.e; i++) {
        scanf("%d %d", &c, &b);
        graph.matrix[c][b] = 1;
    }

    //printMatrix(graph.matrix, graph.n, graph.m);
    
    maxKidsCanPlay(&graph);

    return 0;
}
