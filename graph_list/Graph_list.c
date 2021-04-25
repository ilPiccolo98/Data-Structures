#include "Graph_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Queue.h"

//FUNZIONI NASCOSTE
int count_edges(Edge *head)
{
    if(!head)
        return 0;
    return 1 + count_edges(head->next);
}

bool exists_node(Edge *head, int node)
{
    if(!head)
        return false;
    else if(head->edge == node)
        return true;
    return exists_node(head->next, node);
}

void print_adjacent_list(Edge *head)
{
    if(head)
    {
        printf("%d ", head->edge);
        print_adjacent_list(head->next);
    }
}

void free_edges(Edge *head)
{
    if(head)
    {
        free_edges(head->next);
        free(head);
    }
}

Edge* push_front_edge(Edge *head, int node, int weight)
{
    Edge *edge = (Edge*)malloc(sizeof(Edge));
    edge->edge = node;
    edge->weight = weight;
    edge->next = head;
    return edge;
}

Edge* copy_edges(Edge *head)
{
    if(!head)
        return NULL;
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->edge = head->edge;
    e->next = copy_edges(head->next);
    return e;
}

Edge* remove_edge(Edge *head, int node)
{
    if(!head)
        return NULL;
    if(head->edge == node)
    {
        Edge *next = head->next;
        free(head);
        return next;
    }
    head->next = remove_edge(head->next, node);
    return head;
}

void reduce_value_edge(Edge *head)
{
    if(head)
    {
        --head->edge;
        reduce_value_edge(head->next);
    }
}

void dfs_visit(Graph_list *graph, int source, bool *visited)
{
    visited[source] = true;
    Edge *adjacent = graph->edges[source];
    while(adjacent)
    {
        if(!visited[adjacent->edge])
        {
            printf("Sto per visitare %d\n", adjacent->edge);
            dfs_visit(graph, adjacent->edge, visited);
        }
        adjacent = adjacent->next;
    }
}

void init_dijkstra(int *distances, bool *visited, int length)
{
    int i;
    for(i = 0; i != length; ++i)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }
}

int get_minimum_dijkstra(int *distances, bool *visited, int length)
{
    int node = 0;
    int distance = INT_MAX;
    int i;
    for(i = 0; i != length; ++i)
        if(visited[i] == false && distances[i] < distance)
        {
            distance = distances[i];
            node = i;
        }
    return node;
}

//FUNZIONI VISIBILI
Graph_list* init_graph_list(int nodes)
{
    Graph_list *graph = (Graph_list*)malloc(sizeof(Graph_list));
    if(graph)
    {
        graph->edges = (Edge**)malloc(sizeof(Edge*) * nodes);
        if(graph->edges)
        {
            graph->number_nodes = nodes;
            int i;
            for(i = 0; i != nodes; ++i)
                graph->edges[i] = NULL;
            return graph;
        }
        free(graph);
    }
    return NULL;
}

bool is_empty(Graph_list *graph)
{
    if(graph && graph->number_nodes)
        return false;
    return true;
}

int nodes_graph_list(Graph_list *graph)
{
    return graph->number_nodes;
}

int edges_graph_list(Graph_list *graph)
{
    int counter = 0;
    int i;
    for(i = 0; i != graph->number_nodes; ++i)
        counter += count_edges(graph->edges[i]);
    return counter;
}

int incoming_degree_graph_list(Graph_list *graph, int node)
{
    if(node >= 0 && node < graph->number_nodes)
    {
        int counter = 0;
        int i;
        for(i = 0; i != graph->number_nodes; ++i)
            if(exists_node(graph->edges[i], node))
                ++counter;
        return counter;
    }
    return -1;
}

int outgoing_degree_graph_list(Graph_list *graph, int node)
{
    if(node >= 0 && node < graph->number_nodes)
        return count_edges(graph->edges[node]);
    return -1;
}

int degree_graph_list(Graph_list *graph, int node)
{
    if(node >= 0 && node < graph->number_nodes)
        return incoming_degree_graph_list(graph, node) + outgoing_degree_graph_list(graph, node);
    return -1;
}

void adjacent_graph_list(Graph_list *graph, int node)
{
    if(node >= 0 && node < graph->number_nodes)
    {
        printf("Vertici adiacenti a %d:\n", node);
        print_adjacent_list(graph->edges[node]);
    }
    else
        puts("Il nodo inserito non e' corretto");
}

void accidents_graph_list(Graph_list *graph, int node)
{
    if(node >= 0 && node < graph->number_nodes)
    {
        printf("Vertici incidenti a %d\n", node);
        int i;
        for(i = 0; i != graph->number_nodes; ++i)
            if(exists_node(graph->edges[i], node))
                printf("%d ", i);
    }
    else
        puts("Il nodo inserito non e' corretto");
}

bool exists_edge_graph_list(Graph_list *graph, int a, int b)
{
    return exists_node(graph->edges[a], b);
}

bool add_edge_graph_list(Graph_list *graph, int a, int b, int weight)
{
    if(a >= 0 && a < graph->number_nodes && b >= 0 && b < graph->number_nodes)
        if(!exists_node(graph->edges[a], b))
        {
            graph->edges[a] = push_front_edge(graph->edges[a], b, weight);
            return true;
        }
    return false;
}

void free_graph_list(Graph_list *graph)
{
    int i;
    for(i = 0; i != graph->number_nodes; ++i)
        free_edges(graph->edges[i]);
    free(graph->edges);
    free(graph);
}

Graph_list* add_node_graph_list(Graph_list *graph)
{
    Graph_list *extended = init_graph_list(graph->number_nodes + 1);
    if(extended)
    {
        int i;
        for(i = 0; i != graph->number_nodes; ++i)
            extended->edges[i] = copy_edges(graph->edges[i]);
        return extended;
    }
    return NULL;
}

Graph_list* remove_node_graph_list(Graph_list *graph, int node)
{
    Graph_list *reduced = init_graph_list(graph->number_nodes - 1);
    if(reduced)
    {
        int index_reduced = 0;
        int i;
        for(i = 0; i != graph->number_nodes; ++i)
            if(i != node)
            {
                reduced->edges[index_reduced] = copy_edges(graph->edges[i]);
                ++index_reduced;
            }
        for(i = 0; i != reduced->number_nodes; ++i)
        {
            reduced->edges[i] = remove_edge(reduced->edges[i], node);
            reduce_value_edge(reduced->edges[i]);
        }
        return reduced;
    }
    return NULL;
}

Graph_list* trasposed_graph_list(Graph_list *graph)
{
    Graph_list *trasposed = init_graph_list(graph->number_nodes);
    if(trasposed)
    {
        int i;
        for(i = 0; i != trasposed->number_nodes; ++i)
        {
            Edge *e = graph->edges[i];
            while(e)
            {
                trasposed->edges[e->edge] = push_front_edge(trasposed->edges[e->edge], i, e->weight);
                e = e->next;
            }
        }
        return trasposed;
    }
    return NULL;
}

void bfs_graph_list(Graph_list *graph, int source, int *distance, int *predecessor)
{
    if(source >= 0 && source < graph->number_nodes)
    {
        int i;
        bool *visited = (bool*)malloc(sizeof(bool) * graph->number_nodes);
        for(i = 0; i != graph->number_nodes; ++i)
        {
            predecessor[i] = INT_MAX;
            distance[i] = 0;
            visited[i] = false;
        }
        Queue q;
        init_queue(&q, graph->number_nodes);
        enqueue(&q, source);
        visited[source] = true;
        while(!empty_queue(&q))
        {
            int node = tail_queue(&q);
            dequeue(&q);
            Edge *adjacent = graph->edges[node];
            while(adjacent)
            {
                if(!visited[adjacent->edge])
                {
                    distance[adjacent->edge] = distance[node] + 1;
                    predecessor[adjacent->edge] = node;
                    visited[adjacent->edge] = true;
                    enqueue(&q, adjacent->edge);
                }
                adjacent = adjacent->next;
            }
        }
        free(visited);
    }
}

void dfs_graph_list(Graph_list *graph)
{
    bool *visited = (bool*)malloc(sizeof(bool) * graph->number_nodes);
    int i;
    for(i = 0; i != graph->number_nodes; ++i)
        visited[i] = false;
    for(i = 0; i != graph->number_nodes; ++i)
        if(!visited[i])
            dfs_visit(graph, i, visited);
    free(visited);
}

int* dijkstra_graph_list(Graph_list *graph, int source)
{
    if(source >= 0 && source < graph->number_nodes)
    {
        int *distances = (int*)malloc(sizeof(int) * graph->number_nodes);
        bool *visited = (bool*)malloc(sizeof(int) * graph->number_nodes);
        init_dijkstra(distances, visited, graph->number_nodes);
        distances[source] = 0;
        int i;
        for(i = 0; i != graph->number_nodes - 1; ++i)
        {
            int node = get_minimum_dijkstra(distances, visited, graph->number_nodes);
            visited[node] = true;
            Edge *adjacent = graph->edges[node];
            if(distances[node] != INT_MAX)
                while(adjacent)
                {
                    if((distances[node] + adjacent->weight) < distances[adjacent->edge])
                        distances[adjacent->edge] = distances[node] + adjacent->weight;
                    adjacent = adjacent->next;
                }
        }
        free(visited);
        return distances;
    }
    return NULL;
}


