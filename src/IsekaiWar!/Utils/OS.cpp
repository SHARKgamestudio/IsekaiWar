#include "OS.h"

#pragma region External Dependencies

#include <filesystem>
#include <windows.h>
#include <iostream>
#include <codecvt>
#include <locale>

#pragma endregion

namespace fs = std::filesystem;

namespace OS {
	std::string getExecutablePath() {
		wchar_t path[MAX_PATH];
		DWORD length = GetModuleFileName(NULL, path, MAX_PATH);

		if (length == 0) {
			return "";
		}

		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, path, -1, NULL, 0, NULL, NULL);
		if (bufferSize == 0) {
			return "";
		}

		std::string result(bufferSize - 1, '\0');
		WideCharToMultiByte(CP_UTF8, 0, path, -1, &result[0], bufferSize, NULL, NULL);

		result = getStandardPath(result);

		size_t position = result.find_last_of("/");
		if (position != std::string::npos) {
			result = result.substr(0, position);
		}

		return result;
	}

	std::string getAbsolutePath(std::string _path) {
		return fs::absolute(_path).generic_string();
	}

	std::string getStandardPath(std::string _path) {
		std::replace(_path.begin(), _path.end(), '\\', '/');
		return _path;
	}

	bool directoryExists(std::string _path) {
		return fs::is_directory(_path);
	}

	bool fileExists(std::string _path) {
		return fs::exists(_path);
	}

	void createDirectory(std::string _path) {
		fs::create_directories(_path);
	}

	void copyDirectory(std::string _source, std::string _destination) {
		fs::copy(_source, _destination, fs::copy_options::recursive);
	}

	std::vector<std::string> getFilesInDirectory(std::string _path, std::string _extension) {
		std::vector<std::string> files;
		fs::path directoryPath(_path);

		for (const auto& entry : fs::recursive_directory_iterator(directoryPath, fs::directory_options::skip_permission_denied)) {
			if (fs::is_regular_file(entry) && entry.path().extension() == _extension) {
				files.push_back(getStandardPath(entry.path().string()));
			}
		}

		return files;
	}	
}