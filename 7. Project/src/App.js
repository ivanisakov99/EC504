import React, { useEffect, useState } from 'react';
import Graph from './Graph';
import Header from './Header';
 
const INF = 9999999
const connections = [[3,5],[3,4],[8,6],[8,7],[4,6],[7,5],[6,7],[4,5],[7,1],[2,6],[2,4],[5,1]]

export default function App() {
  const[selected, setSelected] = useState(0);
  const[nodes, setNodes] = useState([1,2,3,4,5,6,7,8])
  const[weightSelected, setWeightSelected] = useState([0,0,0,0,0,0,0,0,0,0,0,0])
  const[completed, setCompleted] = useState([0,0,0,0,0,0,0,0,0,0,0,0])
  const[weights, setWeights] = useState([12,56,3,34,54,6,890,14,32,4,5,65])
  const[graph, setGraph] = useState({})
  const[algorithm, setAlgorithm] = useState("dijkstra")
  const[startNode, setStartNode] = useState(1);
  const[endNode, setEndNode] = useState(2);

  useEffect(() => {
    //console.log(weights)
    buildGraph()
  }, [weights])

  useEffect(() => {
    console.log(graph)
  }, [graph])

  useEffect(() => {
    setWeightSelected([[0,0,0,0,0,0,0,0,0,0,0,0]])
    setCompleted([0,0,0,0,0,0,0,0,0,0,0,0])
  }, [algorithm])


  const buildGraph = () => {
    var newGraph = {}
    var node1, node2, weight;
    for(var i = 0; i < 12; i++) {
      node1 = connections[i][0]
      node2 = connections[i][1]
      weight = weights[i]
      
      addEdge(node1, node2, weight)
    }
    
    function addEdge(node1, node2, value) {
      if(node1 in newGraph) {
        newGraph[node1].push([node2, value])
      } else {
        newGraph[node1] = [[node2, value]]
      }
      if(node2 in newGraph) {
        newGraph[node2].push([node1, value])
      } else {
        newGraph[node2] = [[node1, value]]
      }
    }
    setGraph(newGraph)
  }

  const randomSelect = () => {
    //setSelected(Math.floor(Math.random()*10%8+1)) 
    var tempWeights = []
    for(var i = 0; i < weights.length; i++) {
      var randNum = Math.floor(Math.random()*50 + 1)
      while(tempWeights.includes(randNum)) {
        randNum = Math.floor(Math.random()*50 + 1)
        console.log("WE AVERTED CHAOS!")
      }
      tempWeights.push(randNum)
    }
    setWeights(tempWeights)
    setWeightSelected([0,0,0,0,0,0,0,0,0,0,0,0])
    setCompleted([0,0,0,0,0,0,0,0,0,0,0,0])
  }

  // ----------- ALGORITHMS ------------ //

  const traverseBFS = async (graph) => {
    setNodes([1,2,3,4,5,6,7,8])
    let start = startNode
    let end = endNode
  
    var q = [[start, []]];
    var visited = new Set();
    visited.add(start) 
    var arr = [0,0,0,0,0,0,0,0,0,0,0,0]
    var complete = [0,0,0,0,0,0,0,0,0,0,0,0]
    while(q.length > 0) {
      var len = q.length
      var node, path;
      for(var i = 0; i < len; i++) {
        [node, path] = q.shift()
        setSelected(node)
        //console.log(path) 
        if(node == end) {
          for(var item of path) {
            complete[weights.indexOf(item)] = 1
          } 
          setCompleted(complete)
          console.log(path)
          return;
        }

        for(var nei of graph[node]) {
          if(!visited.has(nei[0])) {
            arr[weights.indexOf(nei[1])] = 1
            setWeightSelected(arr)
            visited.add(nei[0])
            q.push([nei[0], [...path, nei[1]]])
          }
        }
      await sleep(500);
      }
    }
    return; 
  }

  const dijkstra = async (graph) => {
    var s = startNode;
    var path = [0,0,0,0,0,0,0,0,0,0,0,0];
    var newArr = ["inf","inf","inf","inf","inf","inf","inf","inf"];
    newArr[startNode-1] = 0;
    setNodes(newArr);

    // All of the paths and distances are stored here
    var solution = {};
    solution[s] = [];
    solution[s].dist = 0;
    while(true) {
      var parent = null;
      var nearest = null;
      var distance = INF;
      // For each existing solution
      for(var n in solution) {
        if(!solution[n]){
          continue;
        }

        var ndist = solution[n].dist;
        var adj = graph[n];
 
        // For each of its adjacent vertices
        for(var a in adj) {
          // Without a solution
          if(solution[adj[a][0]]){
            continue;
          }

          // Choose nearest vertex with the lowest "total" cost
          var dv = adj[a][1] + ndist;
          if(dv < distance) {
            // Reference parent
            parent = solution[n];
            nearest = adj[a][0];
            distance = dv;

            path[weights.indexOf(adj[a][1])] = 1
            setSelected(adj[a][0]);
            setWeightSelected(path);
            await sleep(500);
            
            // Show the distance to a vertex
            newArr[nearest - 1] = distance;
            setNodes(newArr);
            
            await sleep(500);
          }
          setWeightSelected(path)
        }
        
      }
      
      // No more solutions
      if(distance === INF) {
        break;
      }
    
      // Extend parent's solution path
      solution[nearest] = parent.concat(nearest);
      // Extend parent's cost
      solution[nearest].dist = distance;
    }
    
    // Visualise the shortest path to each vertex
    var arr;
    var x;
    for(var i in solution) {
      arr = [0,0,0,0,0,0,0,0,0,0,0,0];
      
      if(!solution[i]) {
        continue;
      }
      
      x = s;
      setSelected(x);
      for(var j of solution[i]){
        
        for(var k in connections){
          
          if((j === connections[k][0] || j === connections[k][1]) && (x === connections[k][0] || x === connections[k][1])){
            arr[k] = 1;
          }
          setWeightSelected(arr);
        }

        setSelected(j);      
        await sleep(400);
        x = j;
      }
  
      setCompleted(arr);
    
      console.log(" -> " + i + ": [" + solution[i].join(", ") + "]   (dist:" + solution[i].dist + ")");
      await sleep(1000);
      setCompleted([0,0,0,0,0,0,0,0,0,0,0,0]);
      setSelected(0);
    }

    setWeightSelected([0,0,0,0,0,0,0,0,0,0,0,0]);
    setCompleted([0,0,0,0,0,0,0,0,0,0,0,0]);
    console.log("Dijkstra Done");
    return;
  }

  const prim = async (graph) => {
    setNodes([1,2,3,4,5,6,7,8])
    // starting node
    var start = startNode

    var arr = [0,0,0,0,0,0,0,0,0,0,0,0]
    var complete = [0,0,0,0,0,0,0,0,0,0,0,0]
    var allMin = []
    var q = [[start, [start]]]
    var visited = new Set()
    visited.add(start)

    while(q.length > 0) {
      var len = q.length
      var node, path;
      for(var i = 0; i < len; i++) {
        [node, path] = q.shift()
        setSelected(node)
        console.log(path)
        if(path.length == 8) {
          console.log("Prim's Complete!")
          for(var item of allMin) {
            complete[weights.indexOf(item)] = 1
          } 
          setCompleted(complete)
          setWeightSelected([0,0,0,0,0,0,0,0,0,0,0,0])
          setSelected(0)
          break;
        }

        var min = [999,999];

        for(var newNode of path) {
          for(var nei of graph[newNode]) {
            if(!visited.has(nei[0])) {
              arr[weights.indexOf(nei[1])] = 1
              setWeightSelected(arr)
              if(nei[1] < min[1]) {
                min = [nei[0],nei[1]]
              }
            }
          }
        }
        allMin.push(min[1]) 
        visited.add(min[0])
        q.push([min[0], [...path, min[0]]])
      }
      await sleep(500) 
    }
    return;
  }

  const buildPartial = (edge_list) => {
    var newGraph = {}
    var node1, node2, weight;
    for(var i = 0; i < 12; i++) {
      if(edge_list[i] === 1){
        node1 = connections[i][0]
        node2 = connections[i][1]
        weight = weights[i]
        
        addEdge(node1, node2, weight)
      }
    }
    
    function addEdge(node1, node2, value) {
      if(node1 in newGraph) {
        newGraph[node1].push([node2, value])
      } else {
        newGraph[node1] = [[node2, value]]
      }
      if(node2 in newGraph) {
        newGraph[node2].push([node1, value])
      } else {
        newGraph[node2] = [[node1, value]]
      }
    }
    return newGraph
  }

  // check for cycles if new edge is added
  const makes_cycle = async (edge, edges_used) => {
    let edge_list = [...edges_used]
    edge_list[edge] = 1
    let graph = buildPartial(edge_list)
    let start = connections[edge][0]
  
    var stack = [[start, []]];
    var visited = new Set();
    visited.add(start) 
    while(stack.length > 0) {
      var len = stack.length
      var node, path;
      for(var i = 0; i < len; i++) {
        [node, path] = stack.pop()
        for(var nei of graph[node]) {
          if(visited.has(nei[0]) && nei[0] !== path[path.length-1]){
            return true
          }
          if(!visited.has(nei[0])) {
            visited.add(nei[0])
            stack.push([nei[0], [...path, node]])
          }
        }
      }
    }
    return false
  }

  const kruskal = async (graph) => {
    setNodes([1,2,3,4,5,6,7,8])
    var complete_weight = [0,0,0,0,0,0,0,0,0,0,0,0]
    var old_weight = [...complete_weight]

    let sorted_weights = [...weights]
    sorted_weights = sorted_weights.sort(function(a,b) {return b-a})

    let edges_added = 0
    while(edges_added < nodes.length - 1){
      complete_weight = [...old_weight]
      let new_edge = sorted_weights.pop()

      complete_weight[weights.indexOf(new_edge)] = 1
      setWeightSelected(complete_weight)
      await sleep(250)
      let c = await makes_cycle(weights.indexOf(new_edge), complete_weight)
      if(!c){
        edges_added++
        complete_weight[weights.indexOf(new_edge)] = 1
        console.log(weights.indexOf(new_edge))
      } else {
        complete_weight = old_weight
      }
      old_weight = [...complete_weight]
      await sleep(250)
      setWeightSelected(complete_weight)
    }
    complete_weight = [...complete_weight]
    await sleep(500)
    setCompleted(complete_weight)
  }

  const traverseDFS = async (graph) => {
    setNodes([1,2,3,4,5,6,7,8])
    let start = startNode
    let end = endNode
  
    var stack = [[start, []]];
    var visited = new Set();
    visited.add(start) 
    var arr = [0,0,0,0,0,0,0,0,0,0,0,0]
    var complete = [0,0,0,0,0,0,0,0,0,0,0,0]
    while(stack.length > 0) {
      var len = stack.length
      var node, path;
      for(var i = 0; i < len; i++) {
        [node, path] = stack.pop()
        setSelected(node)
        //console.log(path) 
        if(node == end) {
          for(var item of path) {
            complete[weights.indexOf(item)] = 1
          } 
          setCompleted(complete)
          console.log(path)
          return;
        }

        for(var nei of graph[node]) {
          if(!visited.has(nei[0])) {
            arr[weights.indexOf(nei[1])] = 1
            setWeightSelected(arr)
            visited.add(nei[0])
            stack.push([nei[0], [...path, nei[1]]])
          }
        }
      await sleep(500);
      }
    }
    return; 
  }

  // ----------- ALGORITHMS ------------ //

  const visualize = (grph) => {
    console.log("running " + algorithm)
    setCompleted([0,0,0,0,0,0,0,0,0,0,0,0])
    switch(algorithm) {
      case "bfs":
        traverseBFS(grph)
        break;
      case "dijkstra":
        dijkstra(grph)
        break;
      case "prim":
        prim(grph)
        break;
      case "kruskal":
        kruskal(grph)
        break;
      case "dfs":
        traverseDFS(grph)
        break;
    }
  }

  return (
    <div className="container">

      <Header setStartNode={setStartNode} setEndNode={setEndNode} changeAlgorithm={setAlgorithm} graph={graph} visualize={visualize} random={randomSelect} />

      <section className="body">
        <Graph completed={completed} weightSelected={weightSelected} weights={weights} nodes={nodes} selected={selected} />
      </section>

    </div>
  )
}


function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}




/*
console.log(connections[edge])
    let paths_inc = {}
    for(let i = 0; i < edges_used.length; i++){
      if(edges_used[i]){
        paths_inc[connections[i][0]].push(connections[i][1])
        paths_inc[connections[i][1]].push(connections[i][0])
      }
    }
    console.log(paths_inc)
    paths_inc[connections[edge][0]].push(connections[edge][1])
    paths_inc[connections[edge][1]].push(connections[edge][0])

    console.log(paths_inc)
    let visited = []
    let curr = connections[edge][1]
    let prev = connections[edge][0]
    visited.push(curr)
    visited.push(prev)
    console.log(visited)
    return false
    for(let i = 0; i < edges_used.length; i++){
      if((paths_inc[curr].filter(function(val,idx,arr){return (!visited.includes(val))&&val!=prev}).length === 0)&&(paths_inc[prev].filter(function(val,idx,arr){return (!visited.includes(val))&&val!=curr}).length === 0))
        return true
      else{

      }
    }*/