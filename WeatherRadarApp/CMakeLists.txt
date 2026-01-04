cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME WeatherRadarApp)

############## CMake Project ################
#        The main options of project        #
#############################################

project(${PROJECT_NAME} CXX)

# Definition of Macros
add_definitions(
   -D_CONSOLE 
  
)

################ Files ################
#   --   Add files to project.   --   #
#######################################
set(SRC
	whrdrAntenna.cpp
	whrdrChannel.cpp
	WeatherRadarApp.cpp
	whrdrPosition.cpp
	whrdrComm.cpp
	WeatherSymbols.cpp
)
set(INCLUDE
	whrdrAntenna.h
	whrdrChannel.h
	whrdrData.h
	WeatherRadarApp.h
	whrdrPosition.h
	whrdrComm.h
	WeatherSymbols.h
)

# Add library to build.
add_executable(${PROJECT_NAME}
   ${SRC}  ${INCLUDE}
)


target_include_directories(${PROJECT_NAME} PRIVATE ../../Include/CoreIG)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Include/Query)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Include/Avionics)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Include/CIGI)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Include/AvionicsComm)
target_include_directories(${PROJECT_NAME} PRIVATE ../../CoreIG)
target_include_directories(${PROJECT_NAME} PRIVATE ${MY_CORECOMMON_THIRDPARTY_PATH}/tinyXml/v2.6.2/inc)
set_common_target_properties(${PROJECT_NAME})

if(PLATFORM_WIN32)
	target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
    target_include_directories(${PROJECT_NAME} PRIVATE ${MY_COREIG_THIRDPARTY_PATH}/freeglut-3.2.1/include)
	find_library(FREEGLUT_LIBRARY_RELEASE NAMES freeglut  PATHS "${MY_COREIG_THIRDPARTY_PATH}/freeglut-3.2.1/Lib/Win${ARCH}/vc${MSVC_TOOLSET_VERSION}" )
	find_library(FREEGLUT_LIBRARY_DEBUG NAMES freeglutd  PATHS "${MY_COREIG_THIRDPARTY_PATH}/freeglut-3.2.1/Lib/Win${ARCH}/vc${MSVC_TOOLSET_VERSION}" )
	SET(LINK_LIBRARY optimized ${FREEGLUT_LIBRARY_RELEASE} debug ${FREEGLUT_LIBRARY_DEBUG})

	target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARY})
	
	# GLEW
	target_include_directories(${PROJECT_NAME} PRIVATE ${MY_COREIG_THIRDPARTY_PATH}/GLEW/glew-1.7.0/include)
	if(${ARCH} EQUAL  32)
		find_library(GLEW_LIBRARY NAMES glew32  PATHS "${MY_COREIG_THIRDPARTY_PATH}/GLEW/glew-1.7.0/lib" )
	else()
		find_library(GLEW_LIBRARY NAMES glew64  PATHS "${MY_COREIG_THIRDPARTY_PATH}/GLEW/glew-1.7.0/lib" )
	endif()

	SET(LINK_LIBRARY ${GLEW_LIBRARY})

	target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARY})

	#message("eee add include ${MY_CORECOMMON_THIRDPARTY_DIR}")
	target_include_directories(${PROJECT_NAME} PRIVATE ${MY_CORECOMMON_THIRDPARTY_PATH})

endif()

if(USE_MASTER_CMAKE)
	target_link_libraries(${PROJECT_NAME} magOgl magCoordinates qryModelIsector magUtils)
	# target_link_libraries(${PROJECT_NAME} magCDB magOgl MMPLibrary shpfile magUtils magMap)
else()
#	find_package(CoreCommon REQUIRED PATHS "${CORECOMMON_INSTALL_PREFIX}/CMake/${EXPORT_PLATFORM_SUFFIX}" COMPONENTS FileHandler coordinates NO_DEFAULT_PATH)
#	target_link_libraries( ${PROJECT_NAME} CoreCommon::FileHandler CoreCommon::coordinates)
	
	find_package(CoreIg REQUIRED PATHS "${COREIG_INSTALL_PREFIX}/CMake/${EXPORT_PLATFORM_SUFFIX}" COMPONENTS 
		magCDB magOgl MMPLibrary shpfile magUtils NO_DEFAULT_PATH)
	target_link_libraries( ${PROJECT_NAME} CoreIg::magOgl magCoordinates)
	# target_link_libraries( ${PROJECT_NAME} CoreIg::magCDB CoreIg::magOgl CoreIg::MMPLibrary CoreIg::shpfile CoreIg::magUtils Avionics::magMap)
endif()

if(PLATFORM_WIN32)
	SET(TINYXML_LIBRARY_PATH "${MY_CORECOMMON_THIRDPARTY_PATH}/tinyXml/v2.6.2/Lib/Win_x86/vc${MSVC_TOOLSET_VERSION}_${ARCH}")
	set(TINYXML_LIBRARY_PATH debug "${TINYXML_LIBRARY_PATH}/Debug" optimized "${TINYXML_LIBRARY_PATH}/Release")
	find_library(TINYXML_LIBRARY NAMES tinyxml PATHS ${TINYXML_LIBRARY_PATH} )
else()
	SET(TINYXML_LIBRARY_PATH "${MY_CORECOMMON_THIRDPARTY_PATH}/tinyXml/v2.6.2/Lib/Linux_x86/gcc${GCC_SHORT_VERSION}_${ARCH}")
	set(TINYXML_LIBRARY_PATH debug "${TINYXML_LIBRARY_PATH}/Debug" optimized "${TINYXML_LIBRARY_PATH}/Release")
	find_library(TINYXML_LIBRARY NAMES tinyxml PATHS ${TINYXML_LIBRARY_PATH} )
endif()

set_dll_output_name(${PROJECT_NAME} ${PROJECT_NAME})

install_target_lib(${PROJECT_NAME})