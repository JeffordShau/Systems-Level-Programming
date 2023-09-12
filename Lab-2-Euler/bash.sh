#!/bin/bash

echo cloneurl=`git remote -v | cut -d ' ' -f 1 | cut -d $'\t' -f 2 | head -n 1`
