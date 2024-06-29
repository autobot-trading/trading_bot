import React from 'react';

const Strategy = ({ title, description }) => {
    return (
        <div className="strategy">
            <h3>{title}</h3>
            <p>{description}</p>
        </div>
    );
};

export default Strategy;
