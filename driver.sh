#!/bin/bash

cd ./log
rm error_handler log_error log
cd intermud
rm traffic.log udp.log
cd ../..
./bin/driver config.cfg
