#pragma once

#include <string>
#include <exception>

namespace experimental {

	class novalue_exception : public std::exception {

	protected:

		std::string msg_;

	public:

		novalue_exception (const char*  message) {
			msg_ = message;
		}

		virtual const char* what() const {

			return msg_.c_str();

		}

		virtual ~novalue_exception() {}

	};


}