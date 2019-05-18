comp testcase.cpp
./a.out > test
comp $1
./a.out < test > a
comp $2
./a.out < test > b