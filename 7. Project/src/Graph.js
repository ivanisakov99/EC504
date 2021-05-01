import React from 'react';

export default function Graph(props) {
 
  const renderNodes = props.nodes.map((item, index) => {
    var selected = false; 
    if(props.selected == index+1) {
      selected = true
    }
    return (
      <div className={`node node-${index+1} ${selected ? "selected" : ""}`}>{item}</div>
    )
  })

  const renderWeights = props.weights.map((item, index) => {
    var selected = false;
    if(props.weightSelected[index] == 1) {
      selected = true;
    }
    var completed = false
    if(props.completed[index] == 1) {
      completed = true;
    }
    return (
      <div className={`connection connection-${index+1} ${selected ? "selected" : ""} ${completed ? "completed" : ""}`}><span className={`connection-text connection_text-${index + 1}`}>{item}</span></div>
    )
  })

  return (
    <div className="graph-container">
      {renderNodes} 
      {renderWeights} 
    </div>  
  ) 
}
 
