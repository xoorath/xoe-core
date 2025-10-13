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

cpp_compiler = meson.get_compiler('cpp')
if not cpp_compiler.compiles('''static_assert(sizeof(short) == 2);
								static_assert(sizeof(int) == 4);
								static_assert(sizeof(long) == 8);
								static_assert(sizeof(void*) == 8);
								static_assert(sizeof(float) == 4);''',
							 werror: true)
error('Integer types are not the expected size on this compiler.')
endif
