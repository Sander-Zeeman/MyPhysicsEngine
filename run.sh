#!/usr/bin/sh

cd build
rm -rf ./*
cmake .. -DCMD=1
make
./PhysicsEngine
