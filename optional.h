#pragma once

#include "novalue_exception.h"


namespace experimental {

	template <typename T>
	struct optional{

	private:

		void* p;

		union inner{
			void* n;
			T val;
		} in;

	public:

		T getValue() {
			if (p) return in.val;

			novalue_exception ne("optional variable has no value!");
			throw ne;
		}

		optional(){

			p = NULL;
			in.n = NULL;
		}

		optional(T v){
			p = this;
			in.val = v;
		}

		optional operator=(T& v){
			p = this;
			in.val = v;
		}

		template <typename U>
		friend std::ostream& operator<<(std::ostream&, experimental::optional<U>);






	};





	template <typename T>
	std::ostream& operator<< (std::ostream& c, experimental::optional<T> o){
		if (o.p) {
			return c << o.in.val;

		}

		else {
			return c << "optional variable is null ... ";
		}

	}




}