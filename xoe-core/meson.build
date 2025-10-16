public_inc = include_directories('public')
private_inc = include_directories('private')

xoe_core_sources = [
    'private/Assert.cpp',
    'private/BasicTypes.cpp',
    'private/Init.cpp',
    'private/String.cpp'
]

xoe_core_lib_includes = ['public']
xoe_core_lib_includes += private_inc
xoe_core_lib_includes += public_inc

hwy_proj = subproject('hwy')
hwy_dep = hwy_proj.get_variable('hwy_dep')

spdlog_proj = subproject('spdlog')
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')

xxhash_proj = subproject('xxhash')
xxhash_dep = xxhash_proj.get_variable('xxhash_dep')

xoe_core_lib_deps = [
    hwy_dep,
    spdlog_dep,
    xxhash_dep
]

xoe_core_lib = library('xoe-core-lib',
                       xoe_core_sources,
                       include_directories : xoe_core_lib_includes,
                       install : true,
                       dependencies : xoe_core_lib_deps)

xoe_core_lib_dep = declare_dependency(
    link_with : xoe_core_lib,
    include_directories : public_inc)

cpp_compiler = meson.get_compiler('cpp')
if not cpp_compiler.compiles('''static_assert(sizeof(short) == 2);
								static_assert(sizeof(int) == 4);
								static_assert(sizeof(long) == 8);
								static_assert(sizeof(void*) == 8);
								static_assert(sizeof(float) == 4);''',
                             werror : true)
    error('Integer types are not the expected size on this compiler.')
endif
