/*  Requirements:
    ------------
  1.) Fetch Contancts.
  2.) Send direct messages.
  3.) Search
  4.) Status
  5.) Group messages.
*/
#include<bits/stdc++.h>
using namespace std;

class Whatsapp{
  list<Contact>   contacts;
  list<Chat>      chats;
  list<Status>    status;
  Story           story;

public:
  list<Chat> Search(string searchString);
  bool createChat(string contactName);
  bool createGroupChat(list<Contact> contacts);
};

class Contact{
  string contactNumber; // key.
  string name;
  string address;
};

class Chat{
  Contact contactInfo;
  list<Message> messages;
public:
  DeliveryStatus send(Message message);
};

class Status{
  Contact   contactInfo;
  Message   message;
};

class Story{
  Message         message;
  list<Contact>  views;
public:
  StoryStatus setStory(Message message);
};

class Message{
  string    text;
  Document  document;
  Bitmap    image;
  Location  gpsLocation;
};

class Document{
  string    documentExtension;
  double    fileSize;
  fstream   file;
};

class Location {
  double    latitude;
  double    longitude;
};

class Bitmap {
  string    format;
  double    size;
  fstream   file;
};

class DeliveryStatus{
  list<Contact>  viewed;
  list<Contact>  delivered;
};

enum StoryStatus{
  SUCCESS, FAILED
};