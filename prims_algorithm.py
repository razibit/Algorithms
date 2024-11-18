import sys

def prims_algorithm(graph):
    nV = len(graph)

    selected = [False] * nV

    selected[0] = True

    total_weight = 0

    for _ in range(nV - 1):
        min_edge = sys.maxsize
        u = -1
        v = -1

        for i in range(nV):
            if selected[i]:
                for j in range(nV):
                    if not selected[j] and graph[i][j] != 0:
                        if graph[i][j] < min_edge:
                            min_edge = graph[i][j]
                            u,v = i,j
        selected[v] = True
        total_weight += min_edge
        print(f"Edge added: {u}->{v}, Weight: {min_edge}")
    
    print(f"Total weight of MST: {total_weight}")


def input_graph():
    print("Enter the number of vertices:")
    nV = int(input())

    print("Enter the adjacency matrix(row by row):")
    graph1 = []

    for _ in range(nV):
        row = list(map(int,input().split()))
        graph1.append(row)
    
    return graph

if __name__ == "__main__":
    graph = input_graph()
    print("\nRunning Prim's Algorithm: ")
    prims_algorithm(graph)
