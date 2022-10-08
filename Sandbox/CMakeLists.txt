project(Sandbox)

add_executable(Sandbox "src/Sandbox.cpp"    )
	
target_link_libraries(Sandbox Leaf)

set_property(TARGET Sandbox PROPERTY RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_SOURCE_DIR}/bin/${CURRENT_ARCHITECUTURE}-${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
)

target_compile_definitions(Sandbox PRIVATE LEAF_PLATFORM_WINDOWS)
