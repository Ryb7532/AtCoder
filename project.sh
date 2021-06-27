#!/bin/bash

read project
acc new $project
cp format/test.sh $project/test.sh
cp format/formatCpp.cpp $project/a/a.cpp
cp format/formatCpp.cpp $project/b/b.cpp
cp format/formatCpp.cpp $project/c/c.cpp
cp format/formatCpp.cpp $project/d/d.cpp
cp format/formatCpp.cpp $project/e/e.cpp
cp format/formatCpp.cpp $project/f/f.cpp
chmod u+x $project/test.sh
mv $project submissions/.
cd submissions/$project