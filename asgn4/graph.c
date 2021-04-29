#include "graph.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    uint32_t vertices;
    bool undirected;
    bool visited[VERTICES];
    uint32_t matrix[VERTICES][VERTICES];
};

Graph *graph_create(uint32_t vertices, bool undirected){
  Graph *g = (Graph *)malloc(sizeof(Graph));
  if (g){
  g->vertices = vertices;
  g->undirected = undirected;
  for(uint32_t i = 0; i < vertices; i ++){
    visited[i] = 0;
    for (uint32_t k = 0; k < vertices; k++){
      Matrix[i][j] = 0;
    }
  }
  }
  
}

void graph_delete(Graph **G){
  if (*g){
    free(*g);
  }
  return
}
uint32_t graph_vertices(Graph *G){
  return vertices;
}
  
bool graph_add_edge(Graph *G, uint32_t i, uint32_t j, uint32_t k){
  if((0 < i && i <= vertices) && (0 < j && j <= vertices) && (0 < k && k <= vertices)){
    matrix[i][j] = k; 
  } 
}

bool graph_has_edge(Graph *G, uint32_t i, uint32_t j){
  if(matrix[i][j] <= 0){
    return false
  } 
  return true
}
uint32_t graph_edge_weight(Graph *G, uint32_t i, uint32_t j){}
  if(graph_has_edge(*G, i, j)){
    return k
  }
bool graph_visited(Graph *G, uint32_t v){}

void graph_mark_visited(Graph *G, uint32_t v){}

void graph_mark_unvisited(Graph *G, uint32_t v){}

void graph_print(Graph *G){}

