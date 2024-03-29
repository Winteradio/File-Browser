#############################################################
## ----- Setting for Build
MESSAGE( STATUS "Setting for Build")

SET( PROJECT_NAME "Example" )
	## Set the Variable of "PROJECT_NAME" to "Example"
SET( CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
SET( CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe" )
SET( CMAKE_BUILD_TYPE Debug )
SET( CMAKE_CXX_STANDARD 17 )
	## Set the C++ version for 17

CMAKE_MINIMUM_REQUIRED( VERSION 3.11 )
	## Required minimum version for CMAKE
PROJECT( ${PROJECT_NAME} )

MESSAGE( STATUS "Done")
## ----- Setting
#############################################################


#############################################################
###################################################
### If you make new Source or Header file, ########
### Rewrite Under the Code                 ########
### Just SET Directory for New files       ########
###################################################

## ----- Source Directory
MESSAGE( STATUS "Setting for Source Files" )

SET( SRC_DIR ${CMAKE_SOURCE_DIR}/src )

SET( COM_DIR ${SRC_DIR}/COM )
SET( SORT_DIR ${SRC_DIR}/SORT )
SET( SUB_DIR ${SRC_DIR}/SUB )

## ----- Sources

SET( SRCS
	${SRC_DIR}/main.cpp

	${COM_DIR}/SUB_COM.h

	${SORT_DIR}/Node.h
	${SORT_DIR}/BST.h ${SORT_DIR}/BST.cpp

	${SUB_DIR}/Log.h ${SUB_DIR}/Log.cpp
	${SUB_DIR}/Readtext.h ${SUB_DIR}/Readtext.cpp

	)
MESSAGE( STATUS "Done" )
## ----- Sources
#############################################################


#############################################################
## ----- Header Files
MESSAGE( STATUS "Setting for Header Files" )

SET( INCS
	${COM_DIR}
	${SORT_DIR}
	${SUB_DIR}
	)

MESSAGE( STATUS "Done" )
## ----- Header Files
#############################################################


#############################################################
## ----- Linking files for Project in Local
ADD_EXECUTABLE( ${PROJECT_NAME} ${SRCS} )
## ----- Linking files for Project in Local
#############################################################


#############################################################
## ----- Dependency.cmake
INCLUDE( Dependency.cmake )
## ----- Dependency.cmake


## ----- Adding Option for include & library
MESSAGE( STATUS "Setting Options for Target Files")

TARGET_INCLUDE_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR} ${INCS} )
TARGET_LINK_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} PUBLIC ${DEP_LIBS} )

IF ( DEP_LIST )
	ADD_DEPENDENCIES( ${PROJECT_NAME} ${DEP_LIST} )
ENDIF()

MESSAGE( STATUS "Setting Done ")
## ----- Adding Option for include & library
#############################################################
