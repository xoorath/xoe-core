project('xoe-core', 'cpp',
	version	: '0.0.0',
	license : 'MIT')

# project wide defines
#-------------------------------------------------------------------------------
if 'aarch' == build_machine.cpu_family() and 'darwin' == build_machine.system() and 'macos' == build_machine.subsystem()
	add_project_arguments(['-DXOE_HOST_OS_MACOS', '-DXOE_HOST_ARCH_AARCH'], language: ['cpp', 'c'])
elif 'x86_64' == build_machine.cpu_family()
	if 'linux' == build_machine.system()
		add_project_arguments(['-DXOE_HOST_OS_LINUX', '-DXOE_HOST_ARCH_X86_64'], language: ['cpp', 'c'])
	elif 'windows' == build_machine.system()
		add_project_arguments(['-DXOE_HOST_OS_WINDOWS', '-DXOE_HOST_ARCH_X86_64'], language: ['cpp', 'c'])
	else
		error('Unsupported build environment')
	endif
else
	error('Unsupported build environment')
endif

compiler = meson.get_compiler('cpp')
if 'gcc' == compiler.get_id()
	add_project_arguments(['-DXOE_HOST_COMPILER_GCC'], language: ['cpp', 'c'])
elif 'clang' == compiler.get_id()
	add_project_arguments(['-DXOE_HOST_COMPILER_CLANG'], language: ['cpp', 'c'])
elif 'msvc' == compiler.get_id()
	add_project_arguments(['-DXOE_HOST_COMPILER_MSVC'], language: ['cpp', 'c'])
else
	error('unsupported compiler')
endif

if 'debug' == get_option('buildtype')
	add_project_arguments(['-DXOE_CONFIG_DEBUG'], language: ['cpp', 'c'])
elif 'debugoptimized' == get_option('buildtype')
	add_project_arguments(['-DXOE_CONFIG_DEBUGOPTIMIZED'], language: ['cpp', 'c'])
elif 'release' == get_option('buildtype')
	add_project_arguments(['-DXOE_CONFIG_RELEASE'], language: ['cpp', 'c'])
else
	error('unsupported buildtype')
endif

# sub-projects
#-------------------------------------------------------------------------------
subdir('xoe-core')
subdir('xoe-core-demo')
