#!/bin/bash

find_qt() {
    grep "\[rootpath_qt\]" ./conanbuildinfo.txt --after-context=1 | tail -1
}

build_debug() {
    # Debug
    mkdir -p build-debug
    cd build-debug
    conan install  --build=missing '../conanfile.txt' -s compiler.libcxx=libstdc++ -s compiler.runtime=MT -e CC=clang -e CXX=clang++
    QT="$(find_qt)"
    QMAKE="${QT}/bin/qmake"
    echo "using ${QMAKE}"
    $QMAKE ../TypingAnalysis.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug && make qmake_all
    make -j12 1> stdout-build.log 2> stderr-build.log
}

build_release() {
    # Release
    mkdir -p build-release
    cd build-release
    conan install  --build=missing '../conanfile.txt' -s compiler.libcxx=libstdc++ -s compiler.runtime=MT -e CC=clang -e CXX=clang++
    QT="$(find_qt)"
    QMAKE="${QT}/bin/qmake"
    echo "using ${QMAKE}"
    $QMAKE ../TypingAnalysis.pro -spec linux-g++ CONFIG+=qml_debug && make qmake_all

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
