from distutils.core import setup, Extension
import numpy as np

hungarian = Extension('_hungarian',
			sources = ['_hungarian.c','../../libhungarian/hungarian.c'],
			include_dirs = ['../../libhungarian',np.get_include()],
#			library_dirs=['../../libhungarian'],
#			libraries = ['hungarian']
)

setup (name = 'Hungarian',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [hungarian])


