# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/emma/Desktop/Repos/trading_bot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/emma/Desktop/Repos/trading_bot/build

# Include any dependencies generated for this target.
include CMakeFiles/trading_bot.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/trading_bot.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/trading_bot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trading_bot.dir/flags.make

CMakeFiles/trading_bot.dir/test/main.cpp.o: CMakeFiles/trading_bot.dir/flags.make
CMakeFiles/trading_bot.dir/test/main.cpp.o: /Users/emma/Desktop/Repos/trading_bot/test/main.cpp
CMakeFiles/trading_bot.dir/test/main.cpp.o: CMakeFiles/trading_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/emma/Desktop/Repos/trading_bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/trading_bot.dir/test/main.cpp.o"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/trading_bot.dir/test/main.cpp.o -MF CMakeFiles/trading_bot.dir/test/main.cpp.o.d -o CMakeFiles/trading_bot.dir/test/main.cpp.o -c /Users/emma/Desktop/Repos/trading_bot/test/main.cpp

CMakeFiles/trading_bot.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/trading_bot.dir/test/main.cpp.i"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emma/Desktop/Repos/trading_bot/test/main.cpp > CMakeFiles/trading_bot.dir/test/main.cpp.i

CMakeFiles/trading_bot.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/trading_bot.dir/test/main.cpp.s"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emma/Desktop/Repos/trading_bot/test/main.cpp -o CMakeFiles/trading_bot.dir/test/main.cpp.s

CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o: CMakeFiles/trading_bot.dir/flags.make
CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o: /Users/emma/Desktop/Repos/trading_bot/src/api/binance/binance_api.cpp
CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o: CMakeFiles/trading_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/emma/Desktop/Repos/trading_bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o -MF CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o.d -o CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o -c /Users/emma/Desktop/Repos/trading_bot/src/api/binance/binance_api.cpp

CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.i"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emma/Desktop/Repos/trading_bot/src/api/binance/binance_api.cpp > CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.i

CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.s"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emma/Desktop/Repos/trading_bot/src/api/binance/binance_api.cpp -o CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.s

CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o: CMakeFiles/trading_bot.dir/flags.make
CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o: /Users/emma/Desktop/Repos/trading_bot/src/api/curl_main.cpp
CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o: CMakeFiles/trading_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/emma/Desktop/Repos/trading_bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o -MF CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o.d -o CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o -c /Users/emma/Desktop/Repos/trading_bot/src/api/curl_main.cpp

CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.i"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emma/Desktop/Repos/trading_bot/src/api/curl_main.cpp > CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.i

CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.s"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emma/Desktop/Repos/trading_bot/src/api/curl_main.cpp -o CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.s

CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o: CMakeFiles/trading_bot.dir/flags.make
CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o: /Users/emma/Desktop/Repos/trading_bot/src/api/alphavantage/alphavantage_api.cpp
CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o: CMakeFiles/trading_bot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/emma/Desktop/Repos/trading_bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o -MF CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o.d -o CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o -c /Users/emma/Desktop/Repos/trading_bot/src/api/alphavantage/alphavantage_api.cpp

CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.i"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emma/Desktop/Repos/trading_bot/src/api/alphavantage/alphavantage_api.cpp > CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.i

CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.s"
	/opt/homebrew/bin/aarch64-apple-darwin23-g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emma/Desktop/Repos/trading_bot/src/api/alphavantage/alphavantage_api.cpp -o CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.s

# Object files for target trading_bot
trading_bot_OBJECTS = \
"CMakeFiles/trading_bot.dir/test/main.cpp.o" \
"CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o" \
"CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o" \
"CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o"

# External object files for target trading_bot
trading_bot_EXTERNAL_OBJECTS =

trading_bot: CMakeFiles/trading_bot.dir/test/main.cpp.o
trading_bot: CMakeFiles/trading_bot.dir/src/api/binance/binance_api.cpp.o
trading_bot: CMakeFiles/trading_bot.dir/src/api/curl_main.cpp.o
trading_bot: CMakeFiles/trading_bot.dir/src/api/alphavantage/alphavantage_api.cpp.o
trading_bot: CMakeFiles/trading_bot.dir/build.make
trading_bot: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/lib/libcurl.tbd
trading_bot: /opt/homebrew/Cellar/libxlsxwriter/1.1.7/lib/libxlsxwriter.dylib
trading_bot: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.4.sdk/usr/lib/libz.tbd
trading_bot: CMakeFiles/trading_bot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/emma/Desktop/Repos/trading_bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable trading_bot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trading_bot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trading_bot.dir/build: trading_bot
.PHONY : CMakeFiles/trading_bot.dir/build

CMakeFiles/trading_bot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trading_bot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trading_bot.dir/clean

CMakeFiles/trading_bot.dir/depend:
	cd /Users/emma/Desktop/Repos/trading_bot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/emma/Desktop/Repos/trading_bot /Users/emma/Desktop/Repos/trading_bot /Users/emma/Desktop/Repos/trading_bot/build /Users/emma/Desktop/Repos/trading_bot/build /Users/emma/Desktop/Repos/trading_bot/build/CMakeFiles/trading_bot.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/trading_bot.dir/depend

