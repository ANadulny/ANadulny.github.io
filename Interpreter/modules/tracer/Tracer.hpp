#ifndef TKOM_MODULES_TRACER_HPP
#define TKOM_MODULES_TRACER_HPP

#include <string>

namespace tkom {
	namespace modules
	{
		class Tracer
		{
		private:
			unsigned int nestingLevel = 0;

		public:
			Tracer();

			void increaseNestingLevel(const std::string& message = "");
			void resetNestingLevel();
			void decreaseNestingLevel(const std::string& message = ""); //leave
			
			void printMessage(const std::string& message);
		
		private:
			void printNestingLevel();
		};
	}
}

#endif