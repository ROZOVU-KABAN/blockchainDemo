cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME "blockchain")
project(${PROJECT_NAME})

FILE(GLOB SRCS "${CMAKE_CURRENT_LIST_DIR}/src/blockchain/net/*.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/blockchain/*.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/blockchain/storage/*.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
	)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ssl crypto pthread)
