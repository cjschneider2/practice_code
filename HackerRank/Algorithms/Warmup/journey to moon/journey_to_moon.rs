#![allow(unused_variables, unused_mut)]
extern crate alg;

fn main() {
    let nodes = 10;
    let edges = 7;
    let pairs = vec![(0, 2), (1, 8), (1, 4), (2, 8), (2, 6), (3, 5), (6, 9)];
    journey_to_moon(nodes, edges, pairs);
}

fn journey_to_moon(
    nodes: usize,
    edges: usize,
    pairs: Vec<(usize, usize)>
) -> usize {
    let mut adj = vec![Vec::<usize>::new(); nodes];
    let mut visited = vec![0; nodes];
    // initialize graph
    for (x, y) in pairs {
        adj[x].push(y);
        adj[y].push(x);
    }
    // visit the nodes
    let mut comp = 0;
    let mut subs = Vec::<usize>::new();
    for node in 0..nodes {
        if visited[node] == 0 {
            comp += 1;
            let size = dfs(node, &adj, comp, &mut visited);
            subs.push(size);
        }
    }
    println!("{}", comp);
    println!("{:?}", subs);
    // count the combos
    let mut combos = 0;
    //for idx in 0..comp {
    //    let mut sum = 0;
    //    let val = sub_graph_sizes[idx];
    //    for idy in idx+1..comp {
    //        sum += sub_graph_sizes[idy];
    //    }
    //    combos += val * sum;
    //}
    let ab = nodes * (nodes - 1)/2;
    for idx in 0..comp {
        combos += subs[idx]*(subs[idx]-1)/2;
    }
    combos
}

fn dfs(
    node: usize,
    adj: &Vec<Vec<usize>>,
    sub_graph: usize,
    visited: &mut [usize]
) -> usize {
    visited[node] = sub_graph;
    let mut size = 1;
    for idx in 0..adj[node].len() {
        if visited[adj[node][idx]] == 0 {
            size += dfs(adj[node][idx], adj, sub_graph, visited);
        }
    }
    size
}

#[cfg(test)]
mod tests {
    use super::journey_to_moon;

    #[test]
    fn case1() {
        let nodes = 4;
        let edges = 2;
        let pairs = vec![(0, 1), (2, 3)];
        assert_eq!(4, journey_to_moon(nodes, edges, pairs));
    }

    #[test]
    fn case2() {
        let nodes = 10;
        let edges = 7;
        let pairs = vec![(0, 2), (1, 8), (1, 4), (2, 8), (2, 6), (3, 5), (6, 9)];
        assert_eq!(23, journey_to_moon(nodes, edges, pairs));
    }

    #[test]
    fn case3() {
        let nodes = 100;
        let edges = 2;
        let pairs = vec![(0, 1), (2, 3)];
        assert_eq!(4, journey_to_moon(nodes, edges, pairs));
    }
}
