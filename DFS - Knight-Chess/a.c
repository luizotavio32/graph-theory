#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int concatInt(int a, int b) 
{
    //can be found at: https://www.geeksforgeeks.org/how-to-concatenate-two-integer-values-into-one/
    char s1[2]; 
    char s2[2]; 
  
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
    if(start > end) return 1;
    return 0;
}

int getNeighboor(int x, int y) {
    int col = y / 10, row = y % 10;
                                                      //  C,R
    if(x == 0 && col <= 7 && row <= 6) return y+10+2; // (7,6)
    if(x == 1 && col <= 7 && row >= 3) return y+10-2; // (7,3)
    if(x == 2 && col >= 2 && row <= 6) return y-10+2; // (2,6)
    if(x == 3 && col >= 2 && row >= 3) return y-10-2; // (2,3)
    if(x == 4 && col <= 6 && row <= 7) return y+20+1; // (6,7)
    if(x == 5 && col <= 6 && row >= 2) return y+20-1; // (6,2)
    if(x == 6 && col >= 3 && row <= 7) return y-20+1; // (3,7)
    if(x == 7 && col >= 3 && row >= 2) return y-20-1; // (3,2)
    
    return -1;
}

//finding the level of destination vertex to source vertex, we find the number of edges that separate both
int BFS(int source, int destination)
{
    if(source == destination) {
        printf("0");
        return 1;
    }

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

            if(table[v] != 1 && v != -1) {
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

    //printf("\n%d %d\n", concatInt(start_char - 96, start_int), concatInt(end_char - 96, end_int));

    BFS(concatInt(start_char - 96, start_int), concatInt(end_char - 96, end_int));  
    return 0;
}
