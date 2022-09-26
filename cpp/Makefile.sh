#!/usr/bin/bash

BASEDIR=$PWD
mkdir -p build
rm -rf build/*
cd build
cmake ..
make
cd $BASEDIR
mkdir -p output
rm output/*
ln -s $BASEDIR/build/src/main/challenge output/challenge
ln -s $BASEDIR/build/test/unit_tests output/unit_tests
