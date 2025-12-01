cmake_minimum_required(VERSION 3.10.0)
project(JsonParser VERSION 0.1.0 LANGUAGES C)

add_executable(JsonParser main.c FileReader.c Error.c  Lexer.c Token.c String/String.c DataStructures/BinaryTree.c)

