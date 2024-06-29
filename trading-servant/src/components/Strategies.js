import React from 'react';
import Strategy from './Strategy';

const Strategies = () => {
    const strategies = [
        {
            title: 'Trend Following',
            description: 'This strategy aims to capitalize on market trends, buying in uptrends and selling in downtrends.'
        },
        {
            title: 'Mean Reversion',
            description: 'This strategy is based on the idea that asset prices and other market indicators tend to revert to their long-term average.'
        },
        {
            title: 'Momentum Trading',
            description: 'This strategy involves buying assets that have shown an upward price trend and selling those in a downtrend.'
        }
    ];

    return (
        <div className="strategies">
            {strategies.map((strategy, index) => (
                <Strategy key={index} title={strategy.title} description={strategy.description} />
            ))}
        </div>
    );
};

export default Strategies;
