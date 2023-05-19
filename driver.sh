#!/bin/bash

cd ./log
rm error_handler log_error log
cd ..
./bin/driver config.cfg
