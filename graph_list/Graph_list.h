#ifndef GRAPH_LIST_H_INCLUDED
#define GRAPH_LIST_H_INCLUDED
#include <stdbool.h>

typedef struct Edge
{
    int edge;
    int weight;
    struct Edge *next;
}
Edge;

typedef struct Graph_list
{
    int number_nodes;
    Edge **edges;
}
Graph_list;

Graph_list* init_graph_list(int nodes);
bool is_empty_graph_list(Graph_list *graph);
int nodes_graph_list(Graph_list *graph);
int edges_graph_list(Graph_list *graph);
int incoming_degree_graph_list(Graph_list *graph, int node);
int outgoing_degree_graph_list(Graph_list *graph, int node);
int degree_graph_list(Graph_list *graph, int node);
void adjacent_graph_list(Graph_list *graph, int node);
void accidents_graph_list(Graph_list *graph, int node);
bool exists_edge_graph_list(Graph_list *graph, int a, int b);
bool add_edge_graph_list(Graph_list *graph, int a, int b, int weight);
void free_graph_list(Graph_list *graph);
Graph_list* add_node_graph_list(Graph_list *graph);
Graph_list* remove_node_graph_list(Graph_list *graph, int node);
Graph_list* trasposed_graph_list(Graph_list *graph);
void bfs_graph_list(Graph_list *graph, int source, int *distance, int *predecessor);
void dfs_graph_list(Graph_list *graph);
int* dijkstra_graph_list(Graph_list *graph, int source);
#endif // GRAPH_LIST_H_INCLUDED
