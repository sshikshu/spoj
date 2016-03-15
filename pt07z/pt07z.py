'''
You are given an unweighted, undirected tree. Write a program to output the length of the longest
path (from one node to another in that tree. The length of a path in this case is number of edges
we traverse from source to destination.

Input

The first line of the input file contains one integer N --- number of nodes in the tree
(0 < N <= 10000).
Next N-1 lines contain N-1 edges of that tree --- Each line contains a pair (u, v)
means there is an edge between node u and node v (1 <= u,v <= N).

Output

Print the length of the longest path on one line.

Example

Input:
3
1 2
2 3

Output:
2
'''

from typing import Dict, Set
from copy import deepcopy


def bfs(initial_node: int, adjacency_list: Dict[str, Set[int]]) -> Dict[int, int]:
    '''
    performs bfs (coz we are using a set to pop items which is supposed to be non-deterministic
    but seems to act more like a queue) on graph
    '''
    distance = {initial_node: 0}
    parent = {}
    black_set = {initial_node}
    if initial_node in adjacency_list:
        white_set = deepcopy(adjacency_list[initial_node])
        for child in adjacency_list[initial_node]:
            parent[child] = initial_node
        while len(white_set) != 0:
            node = white_set.pop()
            parent_node = parent[node]
            distance[node] = distance[parent_node] + 1
            # print(node, parent_node, distance)
            black_set.add(node)
            # if node in adjacency_list:
            # print(adjacency_list[node])
            # print()
            for child in adjacency_list[node]:
                if child not in black_set:
                    parent[child] = node
                    white_set.add(child)
    return distance


def read_paths(number_of_nodes: int) -> Dict[int, Set[int]]:
    '''reads paths from stdin'''
    adjacency_list = {}
    for _ in range(number_of_nodes - 1):
        start_node, end_node = (int(x) for x in input().strip().split(' '))
        if start_node in adjacency_list:
            adjacency_list[start_node].add(end_node)
        else:
            adjacency_list[start_node] = {end_node}
        if end_node in adjacency_list:
            adjacency_list[end_node].add(start_node)
        else:
            adjacency_list[end_node] = {start_node}
    return adjacency_list


if __name__ == '__main__':
    N = int(input())
    ADJACENCY_LIST = read_paths(N)
    distances = bfs(1, ADJACENCY_LIST)
    updated_distances = bfs(max(distances.keys(), key=(lambda k: distances[k])), ADJACENCY_LIST)
    print(max(updated_distances.values()))
