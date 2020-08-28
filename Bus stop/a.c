#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* next;
    int index;
    int distanceToHeadNode;
    //more info can be added
};

struct graph
{
    int n; //number of vertices
    int m; //number of edges
    struct node **adjList;
    //more info can be added
};

void init_graph(struct graph *g, int n, int m)
{
    int i;

    g->n = n;
    g->m = m;
    g->adjList = malloc (sizeof(struct node*) * n);
    for(i = 0; i < n; i++)
        g->adjList[i] = NULL;
}


struct node* create_node(int index, int w)
{
    struct node *newNode = malloc (sizeof(struct node));
    newNode->index = index;
    newNode->distanceToHeadNode = w;
    return newNode;
}

void connect_nodes(struct graph *g, int a, int b, int w)
{
    struct node *node1 = create_node(a, w);
    struct node *node2 = create_node(b, w);

    node2->next = g->adjList[a];
    g->adjList[a] = node2;
    node1->next = g->adjList[b];
    g->adjList[b] = node1;

     
}




int main(int argc, char const *argv[])
{
    int n, m, u, v ,w, i;
    struct graph g;

    scanf("%d %d", &n, &m);
    init_graph(&g, n , m);

    for (i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
    }
    



   


    
    
    
    return 0;
}