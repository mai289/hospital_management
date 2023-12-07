include_directories("${CMAKE_SOURCE_DIR}/../include")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_FILE)

set(SRC_FILE ${SRC_FILE} PARENT_SCOPE)