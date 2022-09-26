# pyyne-coding-challenge

This repository is meant to contain the code relative to the pyyne-coding-challenge. 

All source code is located at the "cpp" directory.

There are two possible ways to build the code:

1 - using cmake:

Steps:

1.1 - Run: $ cd cpp; ./Makefile.sh

2 - using Docker:

There is a Dockerfile in this directory that allows you to create a container based on Ubuntu 22:04,
containing all dependencies needed.

Steps:
2.1 - Run: $ sudo docker build -t pyyne .
2.2 - Run: $ sudo docker container run -it pyyne /usr/bin/bash
2.3 - Inside container, run: $ cd /workspace/; ./Makefile.sh

Using both methods you'll generate the binaries of the main function and the unit_tests into the
"output" directory.
