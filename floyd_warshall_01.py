def floyd_warshall():
    INF = 10**9

    n = int(input("Enter the number of vertices in the graph: "))
    print("Enter the adjacency matrix row by row:")

    graph = []

    for i in range(n):
        row = input(f"Row{i+1}: ").split()

        row = [int(x) if x!= 'inf' else INF for x in row]
        graph.append(row)
    
    dist = [[graph[i][j] for j in range(n)] for i in range(n)]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j])
    
    print("\nShortest distances between every pair of vertices:")
    
    for row in dist:
        print(" ".join(str(x) if x != INF else "inf" for x in row))

floyd_warshall()