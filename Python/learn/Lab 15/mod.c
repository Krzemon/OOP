#include <Python.h>
#include "mod_funcs.h"

static PyObject *mod_met(PyObject *self, PyObject *args)
{
	int a, b;
	PyObject *c = NULL;
	PyObject *d = NULL;

	if(!PyArg_ParseTuple(args, "ii|OO", &a, &b, &c, &d))
		return NULL;

	int s;
	if (c)
		s = a + b + PyLong_AsLong(c);
	else
		s = a + b;
	
	if (d)
		for(int i = 0; i < PyList_Size(d); i++)
			s += PyLong_AsLong(PyList_GetItem(d,i));

	return Py_BuildValue("i", s);
}

static PyObject *mod_randsqr(PyObject *self, PyObject *args)
{
	int n;

	if(!PyArg_ParseTuple(args, "i", &n))
		return NULL;

	double result[10] = {0};
	randsqr(n, result);

	PyObject* resultPy = PyList_New(0);
	for (int i = 0; i < 10; i++)
		PyList_Append(resultPy, PyFloat_FromDouble(result[i]));

	return resultPy;
}

static PyObject *mod_euclid(PyObject *self, PyObject *args)
{
	PyObject* d;

	if(!PyArg_ParseTuple(args, "O", &d))
		return NULL;

	PyObject* result = PyDict_New();

	int size = PyDict_Size(d);
	int keys[size], values[size];
	PyObject* keysPy, *valuesPy;
	keysPy = PyDict_Keys(d);
	valuesPy = PyDict_Values(d);
	for (int i = 0; i < size; i++)
	{
		keys[i] = PyLong_AsLong(PyList_GetItem(keysPy, i));
		values[i] = PyLong_AsLong(PyList_GetItem(valuesPy, i));
	}

	PyObject* input = PyTuple_New(2);
	for (int i = 0; i < size; i++)
	{
		PyTuple_SetItem(input, 0, PyLong_FromLong(keys[i]));
		PyTuple_SetItem(input, 1, PyLong_FromLong(values[i]));
		PyDict_SetItem(result, input, PyLong_FromLong(euclid(keys[i], values[i])));
	}

	return result;
}

static PyMethodDef mod_metody[] =
{
	{"met", mod_met, METH_VARARGS, "Zwraca sume przekazanych wartosci."},
	{"randsqr", mod_randsqr, METH_VARARGS, "Losuje wspolrzedne N punktow w kwadracie o boku 1. Zlicza jaki procent punktow trafia odpowiednio w kwadraty o boku [0.1, 0.2, ..., 1]."},
	{"euclid", mod_euclid, METH_VARARGS, "Liczy wedlug algorytmu Euklidesa."},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef modmodule =
{
	PyModuleDef_HEAD_INIT,
	"mod",
	NULL,
	-1,
	mod_metody
};

PyMODINIT_FUNC PyInit_mod(void)
{
	return PyModule_Create(&modmodule);
}
