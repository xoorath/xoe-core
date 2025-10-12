public_inc = include_directories('public')
private_inc = include_directories('private')

xoe_core_sources = [
	'private/core-types.cpp'
]

xoe_core_lib_includes = ['public']
xoe_core_lib_includes += private_inc
xoe_core_lib_includes += public_inc

xoe_core_lib = library('xoe-core-lib',
	xoe_core_sources,
	include_directories: xoe_core_lib_includes,
	install: true)

xoe_core_lib_dep = declare_dependency(
	link_with: xoe_core_lib,
	include_directories: public_inc)
