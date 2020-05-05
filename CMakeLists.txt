cmake_minimum_required ( VERSION 2.8 )

project ( SimpleVectors )

set ( TARGET_NAME SimpleVectors )

file ( GLOB SOURCE_FILES "src/*" )
file ( GLOB TEST_FILES  "test/*" )

add_executable ( ${TARGET_NAME} ${SOURCE_FILES} ${TEST_FILES} )

source_group ( "Source" FILES ${SOURCE_FILES} )
source_group ( "Test" FILES ${TEST_FILES} )

set_target_properties ( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )

target_include_directories ( ${TARGET_NAME}
	PUBLIC ${PROJECT_SOURCE_DIR}/src
	PUBLIC ${PROJECT_SOURCE_DIR}/test
	)