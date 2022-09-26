FROM ubuntu:22.04
RUN apt-get update
RUN apt-get install gcc build-essential libssl-dev -y
RUN apt-get install cmake -y
RUN mkdir -p /workspace/
ADD cpp /workspace/
