#include "Python.h"

#include <stdio.h>
#include <time.h>

#ifdef __APPLE__ // OSX-only
#include "osxGetTime.h"
#endif

/*
 * Converts timespec to double.
 */
double convertTsToDouble(struct timespec thetime) {
	return ((double)thetime.tv_nsec / (double)1000000000) + (double)thetime.tv_sec;
}

/*
 * Returns a timespec based on an available clock ID - CLOCK_MONOTONIC_RAW,
 * CLOCK_MONOTONIC or CLOCK_REALTIME. On OSX machines, clock_gettime() is
 * provided in the osxGetTime.h header.
 */
struct timespec getTime(void) {
	struct timespec temp;
#ifdef CLOCK_MONOTONIC_RAW
	clock_gettime(CLOCK_MONOTONIC_RAW, &temp);
#elif CLOCK_MONOTONIC
	clock_gettime(CLOCK_MONOTONIC, &temp);
#elif CLOCK_REALTIME
	clock_gettime(CLOCK_REALTIME, &temp);
#endif
	return temp;
}

/*
 * Returns the current clock time as a double.
 */
static PyObject *
pext1_getTime(PyObject *self, PyObject *args)
{
	return Py_BuildValue("d", convertTsToDouble(getTime()));
};

static PyMethodDef Pext1Methods[] = {
	{"getTime",  pext1_getTime, METH_NOARGS, "Get the current monotonic timestamp as a double."},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
inittimer(void) {
	(void) Py_InitModule3("pext1", Pext1Methods, "Simple Python Extension #1.");
}
