import React, { useEffect, useState } from 'react'

export default function Header(props) {
  const[hide, setHide] = useState(true)
  const[currentAlgo, setCurrentAlgo] = useState('djikstra')

  useEffect(() => {
    console.log(currentAlgo)
    if(currentAlgo == "bfs" || currentAlgo == "dfs") {
      setHide(false)
    } else {
      setHide(true)  
    } 
  }, [currentAlgo])

  const handleChange = (e) => {
    props.changeAlgorithm(e.target.value)
    setCurrentAlgo(e.target.value)
  }

  const hideDisplay = hide ? "hide" : ""

  return (
    <header className="header">
      <div className="logo">
        Visualizer
      </div> 
      <div className="options">
        <select onChange={ e => handleChange(e) } name='algorithms'>
          <option value="dijkstra">Dijkstra's Algorithm</option>
          <option value="prim">Prim's Algorithm</option>
          <option value="kruskal">Kruskal's Algorithm</option>
          <option value="bfs">BFS</option>
          <option value="dfs">DFS</option>
        </select>
      </div>
      <div>
        <input onChange={e => props.setStartNode(parseInt(e.target.value))} placeholder="Start Node" />
      </div>
      <div className={hideDisplay}>
        <input onChange={e => props.setEndNode(parseInt(e.target.value))} placeholder="End Node" />
      </div> 
      <div>
        <button onClick={() => props.random()}  className="btn-visualize">New Graph</button>
      </div>
      <div className="visualize"> 
        <button onClick={() => props.visualize(props.graph)} className="btn-visualize">Visualize!</button>
      </div>
  
    </header>
  )
}
 
