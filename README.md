# Template C++/CMake Project

Cross-platform CMake based project developed in C++.

[![CMake-CI](https://github.com/VgTajdd/cmake_vscode_template/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/VgTajdd/cmake_vscode_template/actions/workflows/cmake.yml)

## Usage

### Debug and Release

#### Single configurations (CLI)

```js
# Debug.
cmake -S. -B build -DCMAKE_BUILD_TYPE=Debug     # Configure.
cmake --build build --config Debug -j           # Build.

# Release.
cmake -S. -B build -DCMAKE_BUILD_TYPE=Release   # Configure.
cmake --build build --config Release -j         # Build.
```

For ```Linux```, you can use the script ```build_debug.sh```.

#### Multi-configuration
```js
cmake -S. -B build -DCMAKE_CONFIGURATION_TYPES="Debug;Release"
```
Or simply run ```generate_vs_solution.bat``` if you are using ```Windows```.

Then you could use ```Visual Studio``` if you are using ```Windows```.

## Tests

Use the following commands:

```bash
cmake --build build/tests --target test_template -j
cd build && ctest --output-on-failure && cd ..
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[Apache License 2.0](https://choosealicense.com/licenses/apache-2.0/)
