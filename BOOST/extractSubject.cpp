//To demonstrate linking with a Boost binary library, we'll use the following simple program
//that extracts the subject lines from emails.
//it uses the Boost.Regex library, which has a separately-compiled binary component.

#include <boost/regex.hpp>


#include <iostream>
#include <string>

int main()
{
std::string line;
boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

while (std::cin)
  {
     std::getline(std::cin, line);
                        boost::smatch matches;
                if (boost::regex_match(line, matches, pat))
                                            std::cout << matches[2] << std::endl;
                                                }
                                                }
