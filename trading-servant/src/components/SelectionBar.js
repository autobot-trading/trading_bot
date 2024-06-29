import React from 'react';

const SelectionBar = () => {
    return (
        <div className="selection-bar">
            <select id="market-select">
                <option value="us">US Stock</option>
                <option value="sg">SG Stock</option>
                <option value="crypto">Crypto Stock</option>
            </select>
            <input type="text" id="search" placeholder="Search stocks..." />
        </div>
    );
};

export default SelectionBar;
