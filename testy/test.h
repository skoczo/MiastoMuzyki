#include <iostream>
#include <string>

class Test
{
	private:
		int errors;
		int success;
	public:
	
		Test()
		{
			errors = 0;
			success = 0;
		}
		
		~Test()
		{
			std::cout<<"###################################"<<std::endl;

			std::cout<<"There was "<<success<<" success/es"<<std::endl;			
			std::cout<<"There was "<<errors<<" error/s"<<std::endl;			

			if(errors > 0)
			{
				std::cout<<"Failure :("<<std::endl;

			}
			else
			{
				std::cout<<"Success. No errors :)"<<std::endl;
			}
			
			std::cout<<"###################################"<<std::endl;
		}
	
		template <typename Any>
		void assert(Any expected, Any actual)
		{
			if(expected != actual)
			{
				std::cout<<"Assert error. Should be "<<expected<<" but is "<<actual<<std::endl;
				errors++;
			}
			else
			{
				success++;
			}
		}
		
		template <typename Any2>
		void assert(std::string errorMessage, Any2 expected, Any2 actual)
		{
			if(expected != actual)
			{
				std::cout<<errorMessage<<" Assert error. Should be "<<expected<<" but is "<<actual<<std::endl;
				errors++;
			}
			else
			{
				success++;
			}
		}

		void error()
		{
			std::cout<<"ERROR"<<std::endl;
			errors++;
		}
};
