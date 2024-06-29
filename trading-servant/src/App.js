import React from 'react';
import './App.css';
import Header from './components/Header';
import SelectionBar from './components/SelectionBar';
import Chart from './components/Chart';
import Indicators from './components/Indicators';
import Strategies from './components/Strategies';

function App() {
    return (
        <div className="container">
            <Header />
            <SelectionBar />
            <Chart />
            <Indicators />
            <Strategies />
        </div>
    );
}

export default App;
