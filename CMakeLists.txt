cmake_minimum_required(VERSION 3.13)

# This tells Geode to find the SDK files automatically
find_package(Geode REQUIRED)

# Replace 'MyMod' with your mod name if you want
project(MyMod)

# This is the most important part: 
# It tells the builder to look inside the 'src' folder for 'main.cpp'
add_geode_mod(
    ${PROJECT_NAME}
    SOURCES src/main.cpp
)
