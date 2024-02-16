// Low Level Design of Movie ticket website like BookMyShow.

#include <bits/stdc++.h>
using namespace std;

class Date {
  int day;
  int month;
  int year;
};

class BMSService {
  list<CinemaHall> cinemas;
public:
  list<CinemaHall> getCinama(string city);
  list<Movie> getMovie(Date date, string city);
};

class CinemaHall {
  int cinemaHallId;
  string CinemaHallName;
  Address address;
  list<Audi> audiList;

public:
  map<Date, Movie> getMovies(list<Date> dateList);
  map<Date, Show> getShows(list<Date> dateList);
};

class Address {
  int pincode;
  string street;
  string city;
  string state;
  string country;
};

class Audi {
  int audiId;
  string audiName;
  int totalSeat;

  list<Show> shows;
};

class Show {
  int showId;
  Movie movieName;
  int startTime;
  int endTime;

  CinemaHall cinemaHallPlayedAt;
  list<Seat> seats;
};

class Seat {
  int seatId;
  SeatStatus seatStatus;
  SeatType seatType;
  double price;
};

enum SeatStatus {
  DELUX=0,
  VIP,
  ECONOMY,
  OTHERS
};

enum SeatType {
  NOT_AVAILABLE=0,
  AVAILABLE,
  BOOKED,
  RESERVED
};

class Movie {
  int movieId;
  string movieName;
  int duration;
  string language;
  Genre genre;

  map<string, list<Show>> cityShowMap;
};

enum Genre {
  SCI_FI,
  HORROR,
  COMEDY,
  ROMANTIC,
  OTHER
};


// Now let's define User's who will be using this Application.
class User {
  int userId;
  Search searchObject;
};

class SystemMember: public User {
  string name;
  string email;
  Account account;
  Address address;
};

class Member: public SystemMember {
public:
  Booking makeBooking(Booking booking);
  list<Booking> getBooking();
};

class Admin: public SystemMember {
public:
  bool addMovie(Movie movie);
  bool addShow(Show show);
};

class Account {
  string username;
  string passwd;
};

class Search {
public:
  list<Movie> searchMovieByName(string movie_name);
  list<Movie> searchMovieByGenre(string movie_name);
  list<Movie> searchMovieByLang(string movie_name);
  list<Movie> searchMovieByDate(string movie_name);
};

class Booking {
  int bookingId;
  Date bookingDate;
  Member member;
  Show show;
  Audi audi;
  BookingStatus bookingStatus;
  double totalAmount;
  list<Seat> seats;
  Payment paymentObj;

public:
  bool makePayment(Payment payment);
};

enum BookingStatus {
  REQUESTED, PENDING, CONFIRMED, CANCELLED
};

class Payment {
  double amount;
  Date paymentDate;
  int transactionId;
  PaymentStatus paymentStatus;
};

enum PaymentStatus {
  PAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED
};