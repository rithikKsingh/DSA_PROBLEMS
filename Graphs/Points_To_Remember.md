BFS uses a queue, so memory is explicit. Safe even for very large grids if memory allows.
DFS recursion can cause stack overflow if grid is huge (like 1000 × 1000 or bigger), depending on system recursion limits.
