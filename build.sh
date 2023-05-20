#!/bin/bash


build_debug() {
    # Debug QT
    QMAKE="/home/demkogg/.conan/data/qt/5.15.7/_/_/package/967f72a50ebf83cb9bbefcddf520d319c6a6b084/bin/qmake"
    mkdir -p build-debug
    cd build-debug
    conan install -s build_type=Debug --build=missing '../conanfile.txt' -s compiler.runtime=MT
    $QMAKE ../TypingAnalysis.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug && make qmake_all
    make -j12 1> stdout-build.log 2> stderr-build.log
}

build_release() {
    # Release QT
    QMAKE="/home/demkogg/.conan/data/qt/5.15.7/_/_/package/100ace4f5c988ff9dec2ad4fd44dabdabc277a78/bin/qmake"
    mkdir -p build-release
    cd build-release
    $QMAKE ../TypingAnalysis.pro -spec linux-g++ CONFIG+=qml_debug && make qmake_all
    conan install -s build_type=Release --build=missing '../conanfile.txt' -s compiler.runtime=MT
    make -j12 1> stdout-build.log 2> stderr-build.log
}

debug=
release=

while getopts rd name
do
    case $name in
    r)  release=1 ;;
    d)  debug=1 ;;
    ?)  printf "Usage: %s: [-r] or [-d]\n" $0
        exit 1 ;;
    esac
done

if [[  -z $debug &&  -z $release ]]; then
    echo "No args"
    printf "Usage: %s: [-r] or [-d]\n" $0
    exit 1
fi

if [[ -n $debug ]]  && [[  -n $release ]]; then
    echo "Too many args"
    printf "Usage: %s: [-r] or [-d]\n" $0
    exit 1
fi

if [[ -n $debug ]]; then
    echo "Build Debug"
    build_debug
else
    echo "Build Release"
    build_release
fi
