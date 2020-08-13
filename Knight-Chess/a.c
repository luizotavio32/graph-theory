#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//can be found at: https://www.geeksforgeeks.org/how-to-concatenate-two-integer-values-into-one/
int concatInt(int a, int b) 
{
    char s1[20]; 
    char s2[20]; 
  
    // Convert both the integers to string 
    sprintf(s1, "%d", a); 
    sprintf(s2, "%d", b); 
  
    // Concatenate both strings 
    strcat(s1, s2); 
  
    // Convert the concatenated string 
    // to integer 
    int c = atoi(s1); 
  
    // return the formed integer 
    return c; 
}

int queueIsEmpty(int start, int end) 
{
    if(start >= end) return 1;
    return 0;
}

int getNeighboor(int x, int y) {
    int row = x % 10, col = y / 10;

    if(x == 0 && row <= 6 && col >= 2) return(y-10+2);
    else if(x == 1 && row <= 6 && col <= 7) return(y+10+2);
    else if(x == 2 && row >= 3 && col >= 2) return(y-10-2);
    else if(x == 3 && row >= 3 && col <= 7) return(y+10-2);
    else if(x == 4 && row <= 7 && col >= 3) return(y-20+1);
    else if(x == 5 && row <= 7 && col <= 6) return(y+20+1);
    else if(x == 6 && row >= 2 && col >= 3) return(y-20-1);
    else if(x == 7 && row >= 2 && col <= 6) return(y+20-1);
    else return(-1);
}

//finding the level of destination vertex to source vertex, we find the number of edges that separate both
int BFS(int source, int destination)
{
    int table[89], level[89], queue[89]; // table[11] = vertex(1,1) , table[33] = vertex(3,3), table[88] = vertex(8,8)
    int i, queue_start = 0, queue_end = 0, u, v;
    for (i = 0; i < 89; i++){
        table[i] = 0;
        level[i] = -1;
    }

    table[source] = 1;
    level[source] = 0;
    queue[queue_end] = source;
    queue_end++;

    while(!queueIsEmpty(queue_start, queue_end)) {
        u = queue[queue_start];
        queue_start++;

        // the knight can have up to 8 moves in the chess table (4: 2 horizontal 1 vertical / other 4: 2 vertical 1 horizontal)
        for(i = 0; i < 8; i++) {
            v = getNeighboor(i ,u);

            if(v!= -1 && table[v] != 1) {
                table[v] = 1;
                queue[queue_end] = v;
                queue_end++;
                level[v] = level[u] + 1;

                if(v == destination) {
                    printf("%d", level[v]);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char start_char, end_char;
    int start_int, end_int;

    scanf("%c", &start_char); // ASCII a=97 b=98 c=99 ... 
    scanf("%d", &start_int);
    scanf(" %c", &end_char); 
    scanf("%d", &end_int);

    BFS(concatInt(start_char - 96, start_int), concatInt(end_char - 96, end_int));  
    return 0;
}
