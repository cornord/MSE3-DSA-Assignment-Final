# School Road Network: Dijkstra's Algorithm

Malawi University of Business and Applied Sciences (MUBAS)
School of Science and Technology, Department of Mathematical Science Education

## Group members
- Kythie Kachulu (MSE/23/SS/020)
- Bright Jere (MSE/23/SS/017)
- Cornord Adriano (MSE/23/SS/001)

## Test it now (no installation needed)
**Live demo:** https://cornord.github.io/MSE3-DSA-Assignment-Final/

Open the link in any browser, choose a "From" school and a "To" school, and click **Run Dijkstra**. The page shows the shortest distance, the path, and the step-by-step working. The buttons Test 1 to Test 7 run the same tests as in our report.

Note: the web page is a JavaScript version of the same algorithm and graph as our C++ program.

## About the project
The graph is a weighted, undirected road network of 20 secondary schools in Blantyre, Malawi (vertices A to T). Edge weights are distances in kilometres. Dijkstra's algorithm finds the shortest route between two schools.

## Files
| File | Description |
|---|---|
| `Dijkstra_algorith_code.cpp` | Main C++ program (A to L) |
| `Dijkstra_algorith_test1.cpp` to `test7.cpp` | The seven tests described in Question 5 |
| `index.html` | Web version for testing without installation |

## Running the C++ code (optional)
```
g++ Dijkstra_algorith_code.cpp -o dijkstra
./dijkstra
```
