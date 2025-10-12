project('xoe-core', 'cpp',
	version	: '0.0.0',
	license : 'MIT')

xoe_platform_defines = []
if 'aarch' == build_machine.cpu_family() and 'darwin' == build_machine.system() and 'macos' == build_machine.subsystem()
	xoe_platform_defines += ['-DXOE_HOST_OS_MACOS', '-DXOE_HOST_ARCH_AARCH']
elif 'x86_64' == build_machine.cpu_family()
	if 'linux' == build_machine.system()
		xoe_platform_defines += ['-DXOE_HOST_OS_LINUX', '-DXOE_HOST_ARCH_X86_64']
	elif 'windows' == build_machine.system()
		xoe_platform_defines += ['-DXOE_HOST_OS_WINDOWS', '-DXOE_HOST_ARCH_X86_64']
	else
		error('Unsupported build environment')
	endif
else
	error('Unsupported build environment')
endif

add_project_arguments(xoe_platform_defines, 
	language: ['cpp', 'c'])

subdir('xoe-core')
subdir('xoe-core-demo')
