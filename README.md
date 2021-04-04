# 8-Tile-A-Star

There's a state class which is basically an array class with locations of the empty space on the 8 tile tab.
Then there's a StateNode class which stores the current state and info about the parent. It also has 2 ints for g and h.
The AStarPuzzle files are what do the main task.
It has the move functions which create a new state, move the tile in that state, assign it's parent and then add it to the open list. The open list has all states which have not been completely explored.
After all the children for a node have been added. We find the one with the smallest f value. (f = g + h).
We then do into the node and explore it's children and repeat until the solution is found.
