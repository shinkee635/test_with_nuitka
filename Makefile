
all: cpptest

cpptest: cpptest.cpp pythontest.py
	g++ -o my_program main.cpp -I/usr/include/python3.8 -L. -lpythontest -lpython3.8
