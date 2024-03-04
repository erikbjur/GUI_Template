project( GoogleTestLibrary )

set( Sources 
    googletest/googletest/src/gtest_main.cc
    googletest/googletest/src/gtest-assertion-result.cc
    googletest/googletest/src/gtest-death-test.cc
    googletest/googletest/src/gtest-filepath.cc
    googletest/googletest/src/gtest-matchers.cc
    googletest/googletest/src/gtest-port.cc
    googletest/googletest/src/gtest-printers.cc
    googletest/googletest/src/gtest-test-part.cc
    googletest/googletest/src/gtest-typed-test.cc
    googletest/googletest/src/gtest.cc
)

# Set the name of the gtest library here
set( LibName gtest )

add_library( ${LibName} STATIC ${Sources} )
target_include_directories( ${LibName} PUBLIC
    googletest/googletest
    googletest/googletest/include
)