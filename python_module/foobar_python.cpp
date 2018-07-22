#include <Python.h>

#include <foo.h>
#include <bar.h>

static PyObject* foobar_run(PyObject* self, PyObject* args)
{
  foo();
  bar();
  Py_RETURN_NONE;
}

static PyMethodDef foobar_methods[] = {
    {
        "run",
        foobar_run,
        METH_VARARGS,
	NULL,
    },
    {NULL, NULL, 0, NULL}
};

static PyModuleDef foobar_module = {
    PyModuleDef_HEAD_INIT,
    "foobar",
    "An example Python C extension module.",
    -1,
    foobar_methods,
};

PyMODINIT_FUNC PyInit_foobar()
{
  PyObject* module = PyModule_Create(&foobar_module);

  if (module == NULL)
  {
    return NULL;
  }

  return module;
}
