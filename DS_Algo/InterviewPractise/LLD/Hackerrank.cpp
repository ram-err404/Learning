/*
  Requirements:
  ------------
  1.) List of Problems.
  // 2.) Login/Singup.
  3.) List of Users.
  4.) Every User can have some portfolio stats (like: 1star, 2star.... 5star champion).
  5.) List of ongoing Contest/Hackathon.
  6.) Admin can add new Problems/Contest/Hackathons.
*/

#include<bits/stdc++.h>
using namespace std;

class Hackerrank{
  list<Problem>     problems;
  list<Contest>     contest;
public:
  list<Problem>     viewProblems();
  list<Contest>     viewContest();
};

class Problem{
  long      problemNumber;
  string    problemName;
  Category  problemCategory;
  string    description;
};
enum Category {
  EASY, MEDIUM, HARD
};

class Contest {
  long          contestId;
  string        contestDescription;
  list<Prize>   prizes;
  list<Winner>  winners;
};

class Prize{
  double  prizeAmount;
};
class Winner{
  User  user;
  Prize prize;
};

class User{
  string  username;
  string  emailid;
  string  name;  
};

class Member: public User{
  float   rating;
  Stats   stats;
public:
  SubmitStatus  submitSolution(Problem problem);
  bool          registerForContest(Contest contest);
};
class SubmitStatus{
  bool    status;   //  {SUCCESS, FAILURE}
  double  efficiency;   // This will tell like your solution is some % faster than others.
};

class Stats{
  long  numberOfProblemsSubmitted;
  long  numberOfContestWon;
  long  numberOfProblemsAttempted;
  long  numberOfContestParticipated; 
  // ... so on.
};

class Admin: public User {
public:
  bool addProblem(Problem problem);
  bool addContest(Contest contest);
};