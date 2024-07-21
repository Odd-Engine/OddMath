project('Odd\'s Math Library', 'cpp',
    version: '0.1',
    default_options: [
        'warning_level=3',
        'cpp_std=c++14',
        'default_library=static'
    ])

subdir('Overflow')
subdir('tests')

if (get_option('coverage'))
    add_global_arguments('--coverage', language: 'cpp')
    add_global_link_arguments('--coverage', language: 'cpp')
endif

r = run_command('python', 'scripts/install_wraps.py', check: true)
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')
gtest_main_dep = gtest_proj.get_variable('gtest_main_dep')

mathlib = library('liboddmath', overflow_files, include_directories: overflow_includes)

test_suite = executable('test_suite',
                        test_files,
                        include_directories: overflow_includes,
                        link_with: mathlib,
                        build_by_default: false,
                        dependencies: [
                            gtest_dep,
                            gmock_dep,
                            gtest_main_dep
                        ])
