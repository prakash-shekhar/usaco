#!/bin/bash
mkdir $1 && cd $1
touch main.cpp $1.in
echo -e "/*\nID: prakash35\nLANG: C++14\nTASK: "$1"\n*/\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main(){\n\t//read input\n\tifstream cin(\"$1.in\");\n\t// ofstream cout(\"$1.out\");\n\n}" >> main.cpp
cd ..