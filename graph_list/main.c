#include <stdio.h>
#include <stdlib.h>
#include "Graph_list.h"

int main()
{
    /*Graph_list *g = init_graph_list(4);
    add_edge_graph_list(g, 0, 1, 0);
    add_edge_graph_list(g, 0, 2, 0);
    add_edge_graph_list(g, 3, 1, 0);
    add_edge_graph_list(g, 3, 0, 0);
    adjacent_graph_list(g, 0);
    puts("");
    adjacent_graph_list(g, 1);
    puts("");
    adjacent_graph_list(g, 2);
    puts("");
    adjacent_graph_list(g, 3);
    puts("");
    accidents_graph_list(g, 0);
    puts("");
    accidents_graph_list(g, 1);
    puts("");
    accidents_graph_list(g, 2);
    puts("");
    accidents_graph_list(g, 3);
    printf("\nNumero vertici: %d\n", nodes_graph_list(g));
    printf("Numero archi: %d\n", edges_graph_list(g));
    int node = 0;
    printf("Grado uscente di %d: %d\n", node, outgoing_degree_graph_list(g, node));
    printf("Grado entrante di %d: %d\n", node, incoming_degree_graph_list(g, node));
    printf("Grado in totale di %d: %d\n", node, degree_graph_list(g, node));
    int another_node = 3;
    printf("Esiste l'arco (%d, %d)? %d\n", node, another_node, exists_edge_graph_list(g, node, another_node));
    puts("Reduced");
    Graph_list *reduced = remove_node_graph_list(g, 0);
    adjacent_graph_list(reduced, 0);
    puts("");
    adjacent_graph_list(reduced, 1);
    puts("");
    adjacent_graph_list(reduced, 2);
    puts("");
    accidents_graph_list(reduced, 0);
    puts("");
    accidents_graph_list(reduced, 1);
    puts("");
    accidents_graph_list(reduced, 2);
    puts("");
    dfs_graph_list(g);*/
    Graph_list *graph = init_graph_list(5);
    add_edge_graph_list(graph, 0, 1, 3);
    add_edge_graph_list(graph, 0, 2, 5);
    add_edge_graph_list(graph, 1, 2, 2);
    add_edge_graph_list(graph, 1, 3, 6);
    add_edge_graph_list(graph, 2, 1, 1);
    add_edge_graph_list(graph, 2, 3, 3);
    add_edge_graph_list(graph, 2, 4, 6);
    add_edge_graph_list(graph, 3, 4, 2);
    add_edge_graph_list(graph, 4, 3, 7);
    add_edge_graph_list(graph, 4, 0, 3);
    int source = 0;
    int *distances = dijkstra_graph_list(graph, source);
    printf("Source: %d\n", source);
    int i;
    for(i = 0; i != graph->number_nodes; ++i)
        printf("Distanza da %d: %d\n", i, distances[i]);
    free(distances);
    return 0;
}
