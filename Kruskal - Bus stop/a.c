#include <stdio.h>
#include <stdlib.h>

struct edge {
    int u, v, w, used;
};


/*struct node
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
}; */

void merge(struct edge arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    
    struct edge L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i].w <= R[j].w) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(struct edge arr[], int l, int r) 
{ 
    if (l < r) {  
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 

/*void init_graph(struct graph *g, int n, int m)
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

     
}*/


int find(int *parent, int i) 
{ 
    if (parent[i] != i) parent[i] = find(parent, parent[i]); 
    return parent[i]; 
} 

void _union(int *parent, int x, int y) 
{ 
    int set_x, set_y;
    set_x = find(parent, x);
    set_y = find(parent, y);
    if(set_x != set_y) {
        parent[set_x] = set_y;
    }
    
} 

void kruskal_minimum_cost_spanning_tree(struct edge *edges, int n, int m) {

    int u_parent, v_parent, i = 0, j = 0, maxWeight = 0;
    int *subsets = malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) 
        subsets[i] = i;
        
    i = 0;
    while (i < n - 1 && j < m) {
           
        u_parent = find(subsets, edges[j].u);
        v_parent = find(subsets, edges[j].v);

        //printf("\nx = %d y = %d\n", u_parent, v_parent);
        
        if (u_parent != v_parent) {
            i++;
            edges[j].used = 1;
            _union(subsets, u_parent, v_parent);
        }
        j++;
        
    }

    //printf("\n----------------\n");
    //for (i = 0; i < m; i++) 
        //printf("edges[%d] = %d %d %d %d\n",i, edges[i].u, edges[i].v, edges[i].w ,edges[i].used );
    
    for (i = 0; i < m; i++) {

        if(!edges[i].used) {
            maxWeight = maxWeight + edges[i].w;
        }
    }
    printf("%d\n", maxWeight);
}


int main(int argc, char const *argv[])
{
    int n, m, u, v ,w, i, temp, maxCostEdge[3];
    struct edge *edges;

    scanf("%d %d", &n, &m);
    edges = malloc(sizeof(struct edge) * m);
    //init_graph(&g, n , m);

    for (i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u; 
        edges[i].v = v; 
        edges[i].w = w; 
        edges[i].used = 0; 
    }

    mergeSort(edges, 0, m - 1);
    kruskal_minimum_cost_spanning_tree(edges, n ,m);
    
    return 0;
}