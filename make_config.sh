#!/bin/bash
SOURCE_DIR=src/
BUILD_DIR=build/


if [ -d "$BUILD_DIR" ]; 
then
    echo "Build dir already exists! Skipping..."
else
    echo "Build dir does not exist! Creating a new one..."
    mkdir build
fi

BUILD_FILES_CONF="$BUILD_DIR/build_files.conf"

if [ -f "$BUILD_FILES_CONF" ];
then
    echo "Build files configuration present"
else
    echo "Build files does not present, touching..."
    touch "$BUILD_FILES_CONF"
fi

echo "Updating build_files.conf..."
ls src/*.cpp | grep -Fxvf "$BUILD_FILES_CONF" > "$BUILD_FILES_CONF"
