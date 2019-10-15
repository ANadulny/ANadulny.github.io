#include "FileReader.hpp"

using FileReader = tkom::modules::FileReader;

FileReader::FileReader(const std::string& file) : handler(file) {
	if (this->handler.fail())
	{
		std::string errorMsg("Failed to open file: " + file);
		throw std::exception(errorMsg.c_str());
	}
};

const char FileReader::nextSign()
{
	char sign;
	sign = this->handler.get();

	while (skipEmptyLine(sign))
		sign = this->handler.get();
	
	this->previousSign = sign;
	this->currentSignPosition++;

	return sign;
}

const bool FileReader::hasFinished() const
{
	return this->handler.eof();
}

const unsigned int& FileReader::getCurrentLineNo() const
{
	return this->currentLineNo;
}

const unsigned int& FileReader::getCurrentSignPosition() const
{
	return this->currentSignPosition;
}

const bool tkom::modules::FileReader::skipEmptyLine(char sign)
{
	if (sign == '\n' || sign == '\r') {
		if (this->previousSign != sign && (this->previousSign == '\n' || this->previousSign == '\r')) {
		}
		else {
			this->currentLineNo++;
			this->currentSignPosition = 0;
		}
		this->previousSign = sign;
		return true;
	}

	return false;
}
