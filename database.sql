-- Create database
CREATE DATABASE trading_servant;

-- Use the created database
USE trading_servant;

-- Create Users table
CREATE TABLE Users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(100) NOT NULL UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Create Markets table
CREATE TABLE Markets (
    market_id INT AUTO_INCREMENT PRIMARY KEY,
    market_name VARCHAR(50) NOT NULL UNIQUE
);

-- Create Stocks table
CREATE TABLE Stocks (
    stock_id INT AUTO_INCREMENT PRIMARY KEY,
    market_id INT,
    stock_symbol VARCHAR(10) NOT NULL,
    stock_name VARCHAR(100) NOT NULL,
    FOREIGN KEY (market_id) REFERENCES Markets(market_id)
);

-- Create Indicators table
CREATE TABLE Indicators (
    indicator_id INT AUTO_INCREMENT PRIMARY KEY,
    indicator_name VARCHAR(50) NOT NULL UNIQUE,
    description TEXT
);

-- Create Strategies table
CREATE TABLE Strategies (
    strategy_id INT AUTO_INCREMENT PRIMARY KEY,
    strategy_name VARCHAR(50) NOT NULL UNIQUE,
    description TEXT
);

-- Insert sample data into Markets table
INSERT INTO Markets (market_name) VALUES ('US Stock');
INSERT INTO Markets (market_name) VALUES ('SG Stock');
INSERT INTO Markets (market_name) VALUES ('Crypto Stock');

-- Insert sample data into Indicators table
INSERT INTO Indicators (indicator_name, description) VALUES ('Moving Average', 'Averages the price data over a specific period to smooth out price action and identify trends.');
INSERT INTO Indicators (indicator_name, description) VALUES ('RSI', 'Measures the speed and change of price movements, identifying overbought or oversold conditions.');
INSERT INTO Indicators (indicator_name, description) VALUES ('MACD', 'Combines moving averages to identify changes in the strength, direction, momentum, and duration of a trend.');
INSERT INTO Indicators (indicator_name, description) VALUES ('Bollinger Bands', 'Uses standard deviation to plot bands above and below a moving average, indicating volatility.');
INSERT INTO Indicators (indicator_name, description) VALUES ('Fibonacci Retracement', 'Uses horizontal lines to indicate areas of support or resistance at key Fibonacci levels before the price continues in the original direction.');

-- Insert sample data into Strategies table
INSERT INTO Strategies (strategy_name, description) VALUES ('Trend Following with AI', 'Utilize AI algorithms to identify and follow trends by analyzing historical and real-time data. The bot buys in uptrends and sells in downtrends, using indicators like MA, MACD, and AI-predicted trends.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Mean Reversion with AI', 'AI models predict the long-term average price of an asset. The bot buys when the price deviates significantly below the average and sells when it goes above, using indicators like RSI and Bollinger Bands.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Momentum Trading with AI', 'The bot identifies and capitalizes on assets showing upward momentum using AI to predict momentum shifts. It buys assets in an uptrend and sells in a downtrend, using indicators like RSI, MACD, and AI-driven momentum forecasts.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Covered Call with AI', 'AI selects stocks for writing call options based on volatility predictions and trend analysis. The bot holds the underlying asset and sells call options to generate income.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Protective Put with AI', 'AI predicts potential downturns and advises on purchasing put options to protect existing positions. The bot buys puts when significant downtrends are predicted.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Straddle with AI', 'The bot buys call and put options based on AI-predicted volatility spikes, profiting from large price movements in either direction.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Strangle with AI', 'Similar to straddles but with different strike prices, the bot uses AI to identify profitable strangle opportunities.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Iron Condor with AI', 'AI identifies low volatility periods and suggests iron condor strategies, profiting from minimal price movement.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Butterfly Spread with AI', 'The bot uses AI to identify stable price points for executing butterfly spreads, maximizing profit from low volatility.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Calendar Spread with AI', 'AI predicts price stability over different time frames, enabling the bot to execute profitable calendar spreads.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Diagonal Spread with AI', 'The bot combines AI predictions of price movement and volatility to execute diagonal spreads with different strike prices and expirations.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Vertical Spread with AI', 'AI assists in identifying optimal strike prices and expirations for vertical spreads, maximizing profit from directional movements.');
INSERT INTO Strategies (strategy_name, description) VALUES ('Ratio Spread with AI', 'The bot leverages AI to balance risk and reward in ratio spreads, identifying periods of relative price stability and movement.');
