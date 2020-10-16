# Takes input graph as list, initial goal or start node, goal node.
def uniform_cost_search(graph, start, goal):    
    # Path list to store the path from initial node to goal node
    path = []    
    # Explored nodes to store each node visited to avoid multiple paths by re-visiting
    explored_nodes = list()    
    
    # Goal state condition check inital node==goal node else continue down
    if start == goal:    
        return path, explored_nodes    
    
    # Appending each node to path list, also simultaneously counting the step cost.
    path.append(start)    
    path_cost = 0    
    
    # Frontier list stores the path cost along with the visited path
    frontier = [(path_cost, path)]    
    while len(frontier) > 0:    
        # Explores the different nodes from the frontier queue by dequeing or selecting a particular node.
        path_cost_till_now, path_till_now = pop_frontier(frontier)    
        current_node = path_till_now[-1]    # Replace the current node with dequed node
        explored_nodes.append(current_node)     # Add it to explored node
    
        if current_node == goal:    # Condition to terminate and found the goal node !!
            return path_till_now, explored_nodes    
    
        neighbours = graph[current_node]    
        # Declaring the neighbour list to store the neighbours of current node selected.
        neighbours_list_int = [int(n) for n in neighbours]    
        neighbours_list_int.sort(reverse=False)    
        neighbours_list_str = [str(n) for n in neighbours_list_int]    
        # Above lines finds the length of the neighbour node ( At most one node will have n neighbours including itself).
        for neighbour in neighbours_list_str:    
            path_to_neighbour = path_till_now.copy()    
            path_to_neighbour.append(neighbour)    
            # Stores path to reach the neighbour
            extra_cost = 1    
            neighbour_cost = extra_cost + path_cost_till_now    
            new_element = (neighbour_cost, path_to_neighbour)    
            # Checks whether the new neighbour exists or not and along with the cost
            is_there, indexx, neighbour_old_cost, _ = get_frontier_params_new(neighbour, frontier)    
            # Adds the neighbours to the explored list which was first created
            if (neighbour not in explored_nodes) and not is_there:    
                frontier.append(new_element)    
            elif is_there:    
                if neighbour_old_cost > neighbour_cost:    # Here it checks whether to reach a particular node from different neighbours cost is same or not
                    # It then removes that cost, path from the frontier list to store the minimum cost and path
                    frontier.pop(indexx)        
                    frontier.append(new_element)    
    
    return None, None  
