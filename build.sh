QMAKE="/home/demkogg/.conan/data/qt/5.15.7/_/_/package/967f72a50ebf83cb9bbefcddf520d319c6a6b084/bin/qmake"

mkdir -p build
cd build

conan install -s build_type=Debug --build=missing '/home/demkogg/repos/hse ami ba 2/Coursework/TypingAnalysis/conanfile.txt' -s compiler.runtime=MT  

$QMAKE ../TypingAnalysis.pro

make -j13