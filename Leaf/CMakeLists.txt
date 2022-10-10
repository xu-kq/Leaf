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
	"src/Leaf/Events/ApplicationEvent.h"  "src/leafpch.h")

target_include_directories(Leaf INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(EXECUTABLE_PROJECT_NAME Sandbox)
set_target_properties(Leaf 
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CURRENT_ARCHITECUTURE}-${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CURRENT_ARCHITECUTURE}-${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CURRENT_ARCHITECUTURE}-${CMAKE_BUILD_TYPE}/${EXECUTABLE_PROJECT_NAME}
)
target_include_directories(Leaf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)
target_include_directories(Leaf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_definitions(Leaf PRIVATE LEAF_PLATFORM_WINDOWS LEAF_BUILD_DLL)

target_precompile_headers(Leaf
  PRIVATE
    [["leafpch.h"]]
)