--- hello Project ---

 - How to Build -
   - mkdir build
   - cd build 
   - cmake ..
   - make

 - After build -
   - The built smart contract is under the 'hello' directory in the 'build' directory
   - You can then do a 'set contract' action with 'cleos' and point in to the './build/hello' directory

 - Additions to CMake should be done to the CMakeLists.txt in the './src' directory and not in the top level CMakeLists.txt
