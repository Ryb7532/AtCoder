#!/bin/bash

read project
acc new $project
cp template/test.sh $project/test.sh
cp template/template.cpp $project/a/a.cpp
cp template/template.cpp $project/b/b.cpp
cp template/template.cpp $project/c/c.cpp
cp template/template.cpp $project/d/d.cpp
cp template/template.cpp $project/e/e.cpp
cp template/template.cpp $project/f/f.cpp
chmod u+x $project/test.sh
mv $project submissions/.
cd submissions/$project