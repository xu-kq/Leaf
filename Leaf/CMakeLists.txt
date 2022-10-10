add_library (Leaf SHARED 
	"src/Leaf/Application.cpp" 
	"src/Leaf/Application.h" 
	"src/Leaf/Core.h"  
	"src/Leaf.h" 
	"src/Leaf/EntryPoint.h" 
	"src/Leaf/Log.h" 
	"src/Leaf/Log.cpp" 
	"src/Leaf/Events/Event.h" 
	"src/Leaf/Events/KeyEvent.h"  
	"src/Leaf/Events/MouseEvent.h" 
	"src/Leaf/Events/ApplicationEvent.h"  
	"src/leafpch.h" 
	"src/Leaf/Window.h"
	"src/Leaf/Platform/Windows/WindowsWindow.h" 
	"src/Leaf/Platform/Windows/WindowsWindow.cpp")

target_link_libraries(Leaf "glfw")
if (WIN32)
    target_link_libraries(Leaf "opengl32.lib")
endif()

target_include_directories(Leaf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
									   ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)

set(EXECUTABLE_PROJECT_NAME Sandbox)
set_target_properties(Leaf 
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CURRENT_ARCHITECUTURE}-${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CURRENT_ARCHITECUTURE}-${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CURRENT_ARCHITECUTURE}-${CMAKE_BUILD_TYPE}/${EXECUTABLE_PROJECT_NAME}
)

target_compile_definitions(Leaf PRIVATE LEAF_PLATFORM_WINDOWS   
										LEAF_BUILD_DLL
										LEAF_ENABLE_ASSERTS)

target_precompile_headers(Leaf PRIVATE [["leafpch.h"]])

