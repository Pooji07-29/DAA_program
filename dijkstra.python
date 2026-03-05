import heapq

def dijkstra(graph, start):

    distances = {vertex: float('inf') for vertex in graph}
    distances[start] = 0

    pq = [(0, start)]

    while pq:
        current_distance, current_vertex = heapq.heappop(pq)

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return distances

graph = {}

n = int(input("Enter number of vertices: "))

for i in range(n):
    vertex = input(f"Enter vertex {i+1} name: ")
    graph[vertex] = {}

e = int(input("Enter number of edges: "))

for i in range(e):
    u = input("From vertex: ")
    v = input("To vertex: ")
    w = int(input("Weight: "))
    graph[u][v] = w
    graph[v][u] = w 

start = input("Enter starting vertex: ")

result = dijkstra(graph, start)

print("\nShortest distances from source:")
for vertex in result:
    print(f"{start} -> {vertex} = {result[vertex]}")
