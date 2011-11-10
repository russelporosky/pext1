#pext1 - A Simple Python Extension
For learning purposes only :)

##Install
	python setup.py build
	sudo python setup.py install

##Usage
	import pext1
	print '%d' % (pext1.getTime())

##Learnings
This is just a simple Python extension that does one thing - spit out the
current CPU clock time as a double.

In `setup.py`, you might notice that we're detecting whether we're running on
Darwin or not. On OSX, there is no `clock_gettime()` method, so we don't have
access to CLOCK_MONOTONIC and it's relatives, and thus no need to link to
any external libraries. On other platforms (Linux, Win32, etc.), we do need the
`-lrt` option during the linking step.


