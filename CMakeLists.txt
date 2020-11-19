cmake_minimum_required(VERSION 3.17)
project(minishell_parser C)

set(CMAKE_C_STANDARD 99)


add_executable(minishell_parser main.c libft/libft.a)
target_link_libraries(minishell_parser ${CMAKE_SOURCE_DIR}/libft/libft.a)