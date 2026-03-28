class Solution:
    def articulationPoints(self, V, edges):
        # code here
        from collections import defaultdict
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        timer = [0]
        tin = [-1] * V
        low = [-1] * V
        visited = [False] * V
        articulation = set()

        def dfs(u, parent):
            visited[u] = True
            tin[u] = low[u] = timer[0]
            timer[0] += 1
            children = 0

            for v in graph[u]:
                if v == parent:
                    continue
                if not visited[v]:
                    dfs(v, u)
                    low[u] = min(low[u], low[v])
                    if low[v] >= tin[u] and parent != -1:
                        articulation.add(u)
                    children += 1
                else:
                    low[u] = min(low[u], tin[v])

            if parent == -1 and children > 1:
                articulation.add(u)

        for i in range(V):
            if not visited[i]:
                dfs(i, -1)

        return sorted(articulation) if articulation else [-1]