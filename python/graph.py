import queue

class Graph:
	def __init__ (self):
		self._adjlist = {}
		
	def add_vertex(self, v):
		if not v in self._adjlist:
			self._adjlist[v] = []
		else:
			print('Vertex already exists')
		
	def add_edge(self, v, u):
		if v in self._adjlist and u in self._adjlist:
			self._adjlist[v].append(u)
		else:
			print('Cannot add an edge to a vertex that does not exist')
	
	def DFS(self, v):
		visited = [False] * len(self._adjlist)
		s = [v]
		while len(s) != 0:
			cur_vertex = s.pop()
			print(cur_vertex)
			visited[cur_vertex] = True
			
			for adj_vertex in self._adjlist[cur_vertex]:
				if not visited[adj_vertex]:
					s.append(adj_vertex)
	
	def BFS(self, v):
		visited = [False] * len(self._adjlist)
		q = queue.Queue()
		q.put(v)
		while q.qsize() != 0:
			cur_vertex = q.get()
			print(cur_vertex)
			visited[cur_vertex] = True
			
			for adj_vertex in self._adjlist[cur_vertex]:
				if not visited[adj_vertex]:
					q.put(adj_vertex)
	

if __name__ == '__main__':
	g = Graph()
	for i in range(4):
		g.add_vertex(i)
		
	g.add_edge(0, 1)
	g.add_edge(0, 2)
	g.add_edge(1, 2)
	g.add_edge(2, 0)
	g.add_edge(2, 3)
	g.add_edge(3, 3)
	
	print('DFS:')
	g.DFS(2)
	print('BFS:')
	g.BFS(2)