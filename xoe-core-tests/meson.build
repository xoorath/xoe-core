gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

tests_src = [
     'source/test-core-types.cpp',
]
test_exe = executable(
    'xo-core-tests',
    tests_src,
    dependencies : [
        gtest_dep,
        gmock_dep,
        xoe_core_lib_dep]
)
test('gtest tests', test_exe)