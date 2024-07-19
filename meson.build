project('Odd\'s Math Library', 'cpp',
    version: '0.1',
    default_options: [
        'warning_level=3',
        'cpp_std=c++14',
        'default_library=static'
    ])

gtest_dep = dependency('gtest', main: true)

subdir('Overflow')
subdir('tests')

r = run_command('python', 'scripts/install_wraps.py', check: true)

mathlib = library('math', overflow_files, include_directories: overflow_includes)

test_suite = executable('test_suite',
                        test_files,
                        include_directories: overflow_includes,
                        link_with: mathlib,
                        install: true,
                        build_by_default: false,
                        dependencies: [
                            gtest_dep
                        ])

test('run tests', test_suite)