    find_package(PythonInterp REQUIRED)

      # ... download stuff for the project ...
      BUILD_COMMAND ("${PYTHON_EXECUTABLE} setup.py build")
      INSTALL_COMMAND ("${PYTHON_EXECUTABLE} setup.py install")

      BUILD_IN_SOURCE (1)
        # I assume for python setup.py to work, the source directory
        # and the build directory must be the same?
