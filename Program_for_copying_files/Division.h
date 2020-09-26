class Division
{
	
		std::string source;
		std::string delimit;
      public:
        Division();
        ~Division();
        int find_delimiter(std::string, std::string);
        std::string first_text(int, std::string);
        std::string second_text(int, std::string, int);
};
