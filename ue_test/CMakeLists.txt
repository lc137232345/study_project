# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(./src DIR_LIB_UE_SRC)

include_directories(${PROJECT_SOURCE_DIR}/pub/include) 
include_directories(./inc)

add_subdirectory(./test)
# 生成链接库
add_library (UE STATIC ${DIR_LIB_UE_SRC})