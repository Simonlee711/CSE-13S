//Sources: Eric Hernandez Section
#include "graph.h"
#include "path.h"
#include "vertices.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OPTIONS "hvui:o:"

int main(int argc, char **argv) {
    FILE *in = stdin, *out = stdout;
    int opt = 0;
    uint32_t vertices;
    bool undirected = false;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h':
            printf("SYNOPSIS\n");
            printf("  Traveling Salesman Problem using DFS.\n\n");
            printf("USAGE\n");
            printf("  ./tsp [-u] [-v] [-h] [-i infile] [-o outfile]\n\n");
            printf("OPTIONS");
            printf("  -u             Use undirected graph.\n");
            printf("  -v             Enable verbose printing.\n");
            printf("  -h             Program usage and help.\n");
            printf("  -i infile      Input containing graph (default: stdin)\n");
            printf("  -o outfile     Output of computed path (default: stdout)");
            return 0;
        case 'u': undirected = true;
        case 'v':
            //verbose printing
        case 'i':
            if ((in = fopen(optarg, "r")) == NULL) {
                fprintf(stderr, "failed to open infile");
                exit(1);
            }
            break;
        case 'o':
            if ((out = fopen(optarg, "w")) == NULL) {
                fprintf(stderr, "failed to write outfile");
                exit(1);
            }
            break;
        }
    }
    fscanf(in, "%" SCNd32, &vertices);

    char buffer[1024];
    char *cities[vertices];

    for (uint32_t c_count = 0; c_count < vertices; c_count += 1) {
        fgets(buffer, 1024, in);
        cities[c_count] = strdup(buffer);
    }

    Graph *G = graph_create(vertices, undirected);

    uint32_t i, j, k;
    while (fscanf(in, "%d %d %d", &i, &j, &k) != EOF) {
        graph_add_edge(G, i, j, k);
    }
    /*    
    //creating two paths
    Path *curr = path_create();
    Path *shortest = path_create(); 
    
    //dfs algorithm 
    void dfs(Graph *G, uint32_t v, Path *curr, Path *shortest, char *cities[], FILE *outfile){
      return 0;
    }   
*/
}
