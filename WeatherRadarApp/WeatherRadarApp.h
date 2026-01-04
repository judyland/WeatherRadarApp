#pragma once

#include <cmath>
#include <filesystem>
#include "qryMultiModelsIsector.h"

const float PI_f = 3.14159265358979323846f;

inline float SinDeg(float a)
{
	return ::sinf(a * PI_f / 180.0f);
}

inline float CosDeg(float a)
{
	return ::cosf(a * PI_f / 180.0f);
}



namespace whrdr
{
	class Antenna;
	class Channel;
	using Path = std::filesystem::path;

	struct RadarData
	{
		double dCenterLon = 34.5;
		double dCenterLat = 30.5;
		double dScanRange = 1E+4; // meters;

		std::unique_ptr<qryIsectDB> pDatabase;
		qryIsect::ModelsSharedVec	vActiveAreas;
		Antenna* pAntenna = nullptr;
		Channel* pChannel = nullptr;
	};

	RadarData& getRadarData();

	/**
	* @brief Returns the path to the directory containing weather radar data files.
	* This function attempts to retrieve the path from the environment variable "WEATHER_RADAR_CHANNEL_DATA_PATH".
	* If the environment variable is not set or the path does not exist, it falls back to a default path.
	* The resolved path is cached for subsequent calls. 
	* @return const Path& Reference to the path of the weather data files directory.
	*/
	const Path& getWeatherDataFilesPath();

	/*
	* Returns the full path to a specific weather radar data file.
	* This function constructs the absolute path to a weather data file by appending the given filename
	* to the directory path returned by getWeatherDataFilesPath(). If the resulting file does not exist,
	* an error message is printed to the standard output it returns an empty Path.
	* @param filename The name of the weather data file.
	* @return Path The full path to the requested weather data file.
	*/
	Path getWeatherDataFilePath(const Path& filename);

	inline bool isFileExists(const Path& path)
	{
		return std::filesystem::exists(path);
	}

}

