#ifndef TKOM_MODULES_FILEREADER_HPP
#define TKOM_MODULES_FILEREADER_HPP

#include <fstream>
#include <string>

namespace tkom {
	namespace modules
	{
		class FileReader
		{
		public:
			FileReader(const std::string& file);

			const char nextSign();
			const bool hasFinished() const;
			const unsigned int& getCurrentLineNo() const;
			const unsigned int& getCurrentSignPosition() const;

		private:
			std::ifstream handler;

			unsigned int currentLineNo = 1;
			unsigned int currentSignPosition = 0;
			char previousSign = 0;

			const bool skipEmptyLine(char sign);
		};
	}
}

#endif