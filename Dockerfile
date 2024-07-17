# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Set environment variables to non-interactive
ENV DEBIAN_FRONTEND=noninteractive

# Update and install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    gcc \
    curl \
    libcurl4-openssl-dev \
    libsqlite3-dev \
    libssl-dev \
    libmysqlcppconn-dev \
    pkg-config \
    wget \
    unzip \
    git \
    zlib1g-dev \
    build-essential \
    gdb \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install CMake from source
RUN wget https://github.com/Kitware/CMake/releases/download/v3.20.6/cmake-3.20.6.tar.gz && \
    tar -zxvf cmake-3.20.6.tar.gz && \
    cd cmake-3.20.6 && \
    ./bootstrap && \
    make -j$(nproc) && \
    make install && \
    cd .. && \
    rm -rf cmake-3.20.6 cmake-3.20.6.tar.gz

# Install Oat++ and its components from GitHub (main branch)
RUN git clone https://github.com/oatpp/oatpp.git && \
    cd oatpp && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make install && \
    cd ../.. && \
    rm -rf oatpp

RUN git clone https://github.com/oatpp/oatpp-swagger.git && \
    cd oatpp-swagger && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make install && \
    cd ../.. && \
    rm -rf oatpp-swagger

RUN git clone https://github.com/oatpp/oatpp-sqlite.git && \
    cd oatpp-sqlite && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make install && \
    cd ../.. && \
    rm -rf oatpp-sqlite

# Install xlsxwriter
RUN wget https://github.com/jmcnamara/libxlsxwriter/archive/refs/tags/RELEASE_1.1.0.tar.gz && \
    tar -xzf RELEASE_1.1.0.tar.gz && \
    cd libxlsxwriter-RELEASE_1.1.0 && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make install && \
    cd ../.. && \
    rm -rf libxlsxwriter-RELEASE_1.1.0 RELEASE_1.1.0.tar.gz

# Copy the current directory contents into the container
WORKDIR /usr/src/app
COPY . .

# Create build directory and run CMake
RUN rm -rf build && mkdir build && cd build && cmake .. && make

# Expose port 8000
EXPOSE 8000

# Command to run the executable
CMD ["./build/trading_bot"]

# docker buildx build --platform linux/amd64,linux/arm64 -t onepersonhere/trading_bot --push .
# docker run -p 8000:8000 onepersonhere/trading_bot