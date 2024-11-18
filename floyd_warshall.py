def floyd_warshall():
    n = int(input("Enter the number of vertices in the graph: "))

    print("Enter the adjacency matrix row by row(use 'int' for no direct edge):")
    
    graph = []

    for i in range(n):
        row = input(f"Row {i+1}").split()

        row = [float(x) if x != 'inf' else float('inf') for x in row]
        graph.append(row)
    
    dist = [[graph[i][j] for j in range(n)] for i in range(n)]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j])
    
    print("\nShortest distances between every pair of vertices:")
    for row in dist:
        print(" ".join(f"{x:.1f}" if x!=float('inf') else "inf" for x in row))

floyd_warshall()