cmake_minimum_required(VERSION 3.10)
project(TxtFile VERSION 1.0)

add_library(txtFile STATIC TxtFile.c)
add_library(strUtils STATIC StrUtils.c)