#1/bin/bash

cloneurl=`git remote -v | cut -d ' ' -f 1 | cut -d $'\t' -f 2 | head -n 1`
cd ..
git clone $cloneurl repo
cd repo
make compile
make run
