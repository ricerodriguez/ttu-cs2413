### Final Project
Write a program that will implement a weighted graph and use Dijkstra’s
Algorithm to calculate the shortest path from a start node to every other node
in the graph. You may implement your graph using an edge list, adjacency list,
or adjacency matrix structure. It must also implement a priority queue using a
heap. Your program must provide the user with a prompt to allow the user to
construct the graph.

The prompt should provide 6 commands: `add_node`, `add_edge`, `remove_edge`,
`remove_node`, `Dijkstra`, `exit`.

* `add_node <label>` - Will add a node labeled with `label` to the graph. A `label`
will always be a character from a-z. If a node with that `label` already exists in
the graph the program should not add a duplicate to the graph and should inform
the user that a node with that `label` already exists.

* `add_edge <from> <to> <weight>` - `from` will be the label of the node that
the edge starts from. `to` will be the label of the node that the edge goes to.
`weight` will be the be the numerical weight to assign to the edge. You should
only all one edge from a given node to another node. If the user tried to add an
edge that already exists print out a message informing them that that operation
is not allowed.

* `remove_edge <from> <to>` - Remove an edge from the graph that starts at `from`
and goes to `to`. If that edge does not exist then display a message to the user
to indicate that the operation could not be completed.

* `remove_node <label>` - Remove a node from the list that is labeled with
`label` The node should not be able to be removed unless it has not edges going
to or leaving from it. If the node does not exist or can not be removed display
a message to tell the user why the operation could not be completed.

* `dijkstra <label>` - Execute Dijkstra’s algorithm as discussed in class.
`label` will be the label of the node to start from. If that node does not exist
display a message to the user informing them that the operation could not be
completed. Once Dijkstra’s algorithm has run you should display the nodes in the
graph in order from closest to farthest starting from the source node.

#### Status: Finished
