function(set_project_warnings project_name)
    option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

    set(CLANG_WARNINGS
        -Wall 
        -Wextra
        -Wshadow                # Warn if local declaration shadows a global declaration (vague)
        -Wold-style-cast        # Warn for c-style casts
        -Wcast-align            # Warn for potential performance problem casts
        -Woverloaded-virtual    # Warn if you overload (not override) a virtual function
        -Wpedantic              # Warn on non-standard C++ usage
        -Wformat=2              # Warn on format security issues (e.g. printf)
        -Wconversion            # Warn on type conversions that may lose data
        -Wsign-conversion       # Warn on sign conversions
        -Wnull-dereference      # Warn if null dereference is detected
        -Wdouble-promotion      # Warn if float is implicitly promote 
        -Wimplicit-fallthrough  # Warn on statements that fallthrough without an explicit annotation
        -Wunused                # Warn on unused variables/functions
        -Wundef                 # Warn if used identifier is undefined (and thus evaluates to 0)
    )

    if(WARNINGS_AS_ERRORS)
        set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        set(PROJECT_WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        set(PROJECT_WARNINGS ${CLANG_WARNINGS})
    else()
        message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
    endif()

    target_compile_options(${project_name} INTERFACE ${PROJECT_WARNINGS})

endfunction()
