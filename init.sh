#!/bin/bash

path=$@
file_path=$(python ../construct_file_name.py "$path")
touch $file_path
cat ../cpp-template.h > $file_path
code $file_path
clear