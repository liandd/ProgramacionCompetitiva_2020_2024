#!/usr/bin/python3

"""
Run Dijkstra's algorithm to get the shortest distance from a to every other node.
Run Dijkstra's algorithm again to get the shortest distance from b to every other node.

An edge (u,v) with weight w does not need to be paved if the both: 
    dist[a][u] + w + dist[b][v] != dist[a][b]
    dist[a][v] + w + dist[b][u] != dist[a][b]
Sum the weights over these edges.

An adjacency matrix implementation is used, so the time complexity is:
    O(n^2 log(n))

author: Finn Lidbetter
"""


import sys
import heapq


def dijkstra(adj, src):
    n = len(adj)
    vis = [False for _ in range(n)]
    dist = [float('inf') for _ in range(n)]
    pq = []
    heapq.heappush(pq, (0, src))
    dist[src] = 0
    while pq:
        curr_dist, curr_node = heapq.heappop(pq)
        if vis[curr_node]:
            continue
        best_nbr = None
        best_dist = float('inf')
        for nbr in range(n):
            if vis[nbr]:
                continue
            nbr_dist = curr_dist + adj[curr_node][nbr]
            if nbr_dist < dist[nbr]:
                dist[nbr] = nbr_dist
                heapq.heappush(pq, (nbr_dist, nbr))
        vis[curr_node] = True
    return dist


def main():
    line = sys.stdin.readline()
    tokens = line.split(' ')
    n = int(tokens[0])
    m = int(tokens[1])
    a = int(tokens[2]) - 1
    b = int(tokens[3]) - 1
    adj = [[float('inf') for _ in range(n)] for _ in range(n)]
    for i in range(n):
        adj[i][i] = 0
    for _ in range(m):
        line = sys.stdin.readline()
        tokens = line.split(' ')
        u = int(tokens[0]) - 1
        v = int(tokens[1]) - 1
        w = int(tokens[2])
        adj[u][v] = w
        adj[v][u] = w
    dist_from_a = dijkstra(adj, a)
    dist_to_b = dijkstra(adj, b)
    shortest_path_len = dist_from_a[b]
    total = 0
    for u in range(n):
        for v in range(u + 1, n):
            if adj[u][v] == float('inf'):
                continue
            if dist_from_a[u] + adj[u][v] + dist_to_b[v] != shortest_path_len and dist_from_a[v] + adj[u][v] + dist_to_b[u] != shortest_path_len:
                total += adj[u][v]
    print(total)

if __name__ == '__main__':
    main()
