# מטלה 1 - גרפים (Classes and Namespaces)

### Contact

For any questions or issues, please contact the author at:

- ID: 314906983
- Email: hila.shamir99@gmail.com

### Overview

This project involves the implementation of a graph representation using an adjacency matrix. The graph can be directed, undirected, and weighted. The project includes two main files: `Graph.cpp` and `Algorithms.cpp`.

- `Graph.cpp`: Contains the `Graph` class, which represents the graph and includes methods to load and print the graph.
- `Algorithms.cpp`: Contains several algorithms that operate on the graph, including checking connectivity, finding the shortest path, detecting cycles, checking if the graph is bipartite, and detecting negative cycles.

### Files and Functions

#### Graph.cpp

**Graph Class**
- **loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix)**:
  - Loads an adjacency matrix into the graph.
  - The matrix should be square, with non-negative values representing edge weights (0 for no edge).

- **printGraph() const**:
  - Prints the adjacency matrix representation of the graph in a human-readable format.
  - Useful for visualizing the graph structure.

#### Algorithms.cpp

**Algorithms Class**

- **bool isConnected(const Graph& g)**:
  - Determines if the graph is connected.
  - Uses Depth-First Search (DFS) starting from the first vertex to check if all vertices are reachable.
  - Returns `true` if the graph is connected, otherwise `false`.

- **string shortestPath(Graph& g, int start, int end)**:
  - Finds the shortest path from the `start` vertex to the `end` vertex using the Bellman-Ford algorithm.
  - If the graph contains no path between `start` and `end`, returns `-1`.
  - If a negative weight cycle is detected, returns "Negative cycle detected".
  - Otherwise, returns the shortest path as a string in the format "start -> ... -> end".

- **bool isContainsCycle(const Graph& g)**:
  - Checks if the graph contains any cycles.
  - Uses DFS to detect cycles in the graph.
  - If a cycle is detected, prints the cycle and returns `true`.
  - Returns `false` if no cycle is found.

- **string isBipartite(const Graph& g)**:
  - Determines if the graph is bipartite.
  - Uses BFS to attempt to color the graph with two colors.
  - If the graph is bipartite, returns the two sets as a string in the format "A={...}, B={...}".
  - If the graph is not bipartite, returns "0".

- **string negativeCycle(const Graph& g)**:
  - Detects if there is a negative weight cycle in the graph using the Bellman-Ford algorithm.
  - If a negative cycle is found, constructs and returns the cycle path as a string.
  - If no negative cycle is found, returns "No negative cycle found".


function printGraph
הפונקציה קוראת לפונקציה שבודקת כמה קודקודים יש במטריצה
לאחר מכן היא עוברת בשני לולאות על כל התאים שיש במטריצה אם התא שונה מ0 היא מוסיפה אותו למספר הצלעות
אם הגרף הוא לא מכוון אז ספרנו כל צלע פעמיים ולכן היא מחלקת את מספר הצלעות ב2 ומדפיסה את התשובה

function isConnected
הפונקציה בודקת אם הגרף קשיר 
מחזירה 1 אם הגרף קשיר ו0 אם הגרף לא קשיר
the function called to function dfs from vertex 0
אם הגרף הוא קשיר אזי ניתן להגיע מכל קודקוד לכל קודקוד
בפונקציה נאתחל מערך של כל הקודקודים עם הערך FALSE ואז נריץ DFS על כל הקודקודים
כל קודקוד שנבקר אותו יסומן בTRUE
אם בסוף הריצה יש קודקוד שלא ביקרנו בו בריצת ה DFS 
נחזיר FALSE

function shortestPath
 הפונקציה משתמשת באלגוריתם Bellman Ford 
 אנחנו עוברים מספר הקודקודים פחות 1 על כל הצלעות ועושים להם relax
 ולאחר מכן אם קיימת דרך לקודקוד היא הדרך הכי קצרה
  נבדוק אם אין מעגלים שלילים
   אם אין מחזירים את הדרך ע"י שימוש במערך שמחזיק לכל קודקוד 
   מי האבא שמצביע עליו בדרך הקצרה ביותר
 

function isBipartite
בודקת אם הוא דו צדדי
תחילה בודקת אם הוא מכוון הופכת אותו ללא מכוון
מריצה DFS כדי לבדוק אם יש קודקוד שלא ניתן להגיע אליו
אחרי זה מחלקת את כל קבוצות הקודקודים ל2 קבוצות 
ומחזירה את הקבוצת אם הוא דו צצדי אם לא מחזירה 0

function isContainsCycle
הפונקציה בודקת אם יש מעגל בגרף
 הפונקציה עוברת על כל קודקודי הגרף ומפעילה עליהם DFS ע"י קריאה לפונקציית ISCYCLIC שהיא מבצעת את הבדיקה עבור כל קודקוד
אצלנו היא קוראת לפונקציה isCyclic שבודקת אם קיים מעגל שיוצא מהקודקוד הנשלח


function negativeCycle
הפונקציה בודקת אם יש מעגל שלילי
 הפונקציה משתמשת באלגוריתם Bellman Ford 
אנחנו מריצים בדיקה על כל הצלעות כמספר הקודקודים פחות 1
ואז מבצעים עוד בדיקה על כל הקודקודים אם יש שיפור (RELAX) באחד הצלעות נחזיר שקיים מעגל שלילי ונדפיס אותו




