import React from 'react';

const Indicators = () => {
    const indicators = ['Moving Average', 'RSI', 'MACD', 'Bollinger Bands'];
    return (
        <div className="indicators">
            {indicators.map((indicator, index) => (
                <div key={index} className="indicator">{indicator}</div>
            ))}
        </div>
    );
};

export default Indicators;
