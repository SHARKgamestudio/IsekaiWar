#pragma once

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

namespace OS {
	/// <summary>
	/// Returns the path of the program executable.
	/// </summary>
	static std::string getExecutablePath();

	/// <summary>
	/// Transforms a relative path into an absolute path.
	/// </summary>
	static std::string getAbsolutePath(std::string _path);

	/// <summary>
	/// Replace all backslashes with forward slashes.
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	static std::string getStandardPath(std::string _path);

	/// <summary>
	/// Return true if the directory exists.
	/// </summary>
	static bool directoryExists(std::string _path);

	/// <summary>
	/// Return true if the file exists.
	/// </summary>
	static bool fileExists(std::string _path);

	/// <summary>
	/// Create a directory at the specified path.
	/// </summary>
	static void createDirectory(std::string _path);

	/// <summary>
	/// Copy a directory and its subdirectories to another directory.
	/// </summary>
	static void copyDirectory(std::string _source, std::string _destination);

	/// <summary>
	/// Returns a vector of file paths with a specific extension in a directory and its subdirectories.
	/// </summary>
	static std::vector<std::string> getFilesInDirectory(std::string _path, std::string _extension = ".png");
}