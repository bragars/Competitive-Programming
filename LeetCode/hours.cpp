#include <iostream>
#include <string>

std::string solution(int n)
{
  if (n < 1 || n > 1000000)
    return "do not apply to requirements";

  if (n == 0)
    return "now";

  std::string response = "";
  int days = n / 86400;
  n %= 86400;
  int hours = n / 3600;
  n %= 3600;
  int minutes = n / 60;
  int seconds = n % 60;

  if(days > 1) response += std::to_string(days) + " days ";
  else if(days == 1) response += std::to_string(days) + " day ";

  if (minutes == 0 && seconds == 0 && days > 1) response += "and ";
  if(hours > 1) response += std::to_string(hours) + " hours ";
  else if(hours == 1) response += std::to_string(hours) + " hour ";

  if (seconds == 0 && minutes > 1 || seconds == 0 && days > 1) response += "and ";
  if(minutes > 1) response += std::to_string(minutes) + " minutes ";
  else if(minutes == 1) response += std::to_string(minutes) + " minute ";

  if (minutes > 1 || hours > 1 || days > 1) response += "and ";
  if(seconds > 1) response += std::to_string(seconds) + " seconds ";
  else if(seconds == 1) response += std::to_string(seconds) + " second ";

  return response;
}

int main()
{
  int n;
  std::cin >> n;

  std::string out_;
  out_ = solution(n);
  std::cout << out_ << std::endl;
}
