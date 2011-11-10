#!/usr/bin/env python
import sys
from distutils.core import setup, Extension
if sys.platform == "darwin":
	module1 = Extension('pext1',
		sources = ['pext1.c'])
else:
	module1 = Extension('pext1',
		sources = ['pext1.c'],
		extra_link_args = ['-lrt'])

setup (name = 'pext1',
	version = '1.0.0',
	description = 'Simple Python Extension #1.',
	author = 'Russ Porosky',
	author_email = 'russ@indyarmy.com',
	url = 'http://indyarmy.com/python/pext1/',
	ext_modules = [module1])
