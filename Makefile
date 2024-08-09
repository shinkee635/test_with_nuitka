
all: cpptest

cpptest: cpptest.cpp pythontest.py
	nuitka --module pythontest.py
	g++ -o mytest cpptest.cpp -I/usr/include/python3.8 -L. -lpythontest -lpython3.8
